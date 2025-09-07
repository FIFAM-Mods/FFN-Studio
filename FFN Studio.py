# FFN Studio.py
# Python 3.7+, Qt5 (PyQt5)
import os
import sys
import struct
import tempfile
import subprocess
import resources

from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtGui import QFont, QIcon


APP_TITLE = "FFN Studio (0.2)"


def app_root_dir() -> str:
    return os.path.abspath(os.path.dirname(sys.argv[0] if getattr(sys, 'frozen', False) else __file__))


def gx_path() -> str:
    return os.path.join(app_root_dir(), "tools", "gx.exe")


def ensure_gx_exists(parent=None) -> bool:
    if os.path.isfile(gx_path()):
        return True
    #QtWidgets.QMessageBox.critical(parent, "gx.exe not found",
    #                               f'Could not find "gx.exe" at:\n{gx_path()}\n\n'
    #                               "Please place gx.exe into the tools/ folder.")
    return False


# ----- FFN -> FSH converter -----
FSH_HEADER = bytes.fromhex(
    "53 48 50 49 F0 41 01 00 01 00 00 00 47 33 35 39 "
    "66 6F 6E 74 18 00 00 00"
)

def convert_ffn_to_fsh(in_filename, out_filename):
    with open(in_filename, "rb") as f:
        f.seek(28)
        data_offset_bytes = f.read(4)
        if len(data_offset_bytes) >= 4:
            data_offset = struct.unpack("<I", data_offset_bytes)[0]
            f.seek(data_offset)
            fsh_data = f.read()
            with open(out_filename, "wb") as out_f:
                out_f.write(FSH_HEADER)
                out_f.write(fsh_data)


# ----- Small helpers -----
def quoted(path: str) -> str:
    # We'll pass subprocess args as a list (no shell), so quoting not needed in args,
    # but still helpful for clear error messages.
    if " " in path and not (path.startswith('"') and path.endswith('"')):
        return f'"{path}"'
    return path


def rgba_to_hex(qcolor: QtGui.QColor) -> str:
    # lower-case hex (rgba) with 0x prefix: 0xrrggbbaa
    r = qcolor.red()
    g = qcolor.green()
    b = qcolor.blue()
    a = qcolor.alpha()
    return "0x{0:02x}{1:02x}{2:02x}{3:02x}".format(a, r, g, b)

def run_gx(parent, args_list):
    """
    Run gx.exe with the provided list of arguments.
    Shows a message box on error; returns (ok: bool, stdout:str, stderr:str)
    """
    if not ensure_gx_exists(parent):
        return False, "", "gx.exe missing"

    startupinfo = None
    if sys.platform == "win32":
        startupinfo = subprocess.STARTUPINFO()
        startupinfo.dwFlags |= subprocess.STARTF_USESHOWWINDOW

    try:
        proc = subprocess.run(
            [gx_path()] + args_list,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=False,
            shell=False,
            startupinfo=startupinfo,
            creationflags=subprocess.CREATE_NO_WINDOW if sys.platform == "win32" else 0,
        )
        out = proc.stdout.decode(errors="replace")
        err = proc.stderr.decode(errors="replace")

        if proc.returncode != 0:
            QtWidgets.QMessageBox.critical(
                parent, "gx.exe failed",
                f"Command:\n{gx_path()} {' '.join(args_list)}\n\n"
                f"Exit code: {proc.returncode}\n\nSTDERR:\n{err}\n\nSTDOUT:\n{out}"
            )
            return False, out, err
        return True, out, err

    except Exception as e:
        QtWidgets.QMessageBox.critical(parent, "Error running gx.exe", str(e))
        return False, "", str(e)


# ----- Reusable UI pieces -----
class LabeledWidget(QtWidgets.QWidget):
    def __init__(self, label_text: str, widget: QtWidgets.QWidget, parent=None):
        super().__init__(parent)
        layout = QtWidgets.QHBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 0)
        lab = QtWidgets.QLabel(label_text)
        lab.setMinimumWidth(110)
        layout.addWidget(lab)
        layout.addWidget(widget)
        self.label = lab
        self.widget = widget


class ColorButton(QtWidgets.QPushButton):
    colorChanged = QtCore.pyqtSignal(QtGui.QColor)

    def __init__(self, initial=QtGui.QColor(0, 0, 0, 255), parent=None):
        super().__init__(parent)
        self._color = QtGui.QColor(initial)
        self.setText("")
        self.setFixedSize(40, 20)
        self.clicked.connect(self.pick_color)

    def color(self) -> QtGui.QColor:
        return QtGui.QColor(self._color)

    def setColor(self, color: QtGui.QColor):
        self._color = QtGui.QColor(color)
        self.update()

    def pick_color(self):
        dlg = QtWidgets.QColorDialog(self._color, self)
        dlg.setOption(QtWidgets.QColorDialog.ShowAlphaChannel, True)
        if dlg.exec_() == QtWidgets.QDialog.Accepted:
            self.setColor(dlg.selectedColor())
            self.colorChanged.emit(self._color)

    def paintEvent(self, event):
        super().paintEvent(event)
        # draw colored rectangle inside button
        p = QtGui.QPainter(self)
        rect = self.rect()
        p.fillRect(rect, self._color)
        p.setPen(QtGui.QPen(QtCore.Qt.black))
        p.drawRect(rect)


# ----- TTF/OTF -> FFN Window -----
class TtfToFfnWindow(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("TTF/OTF to FFN")
        self.setModal(True)
        self.setMinimumWidth(560)

        main = QtWidgets.QVBoxLayout(self)

        # Input file row
        self.inputEdit = QtWidgets.QLineEdit()
        browseBtn = QtWidgets.QPushButton("Browse...")
        browseBtn.clicked.connect(self.browse_input)
        row1 = QtWidgets.QHBoxLayout()
        row1.addWidget(self.inputEdit)
        row1.addWidget(browseBtn)
        main.addLayout(row1)

        # --- Font parameters group ---
        fontGroup = QtWidgets.QGroupBox("Font Parameters")
        fgL = QtWidgets.QGridLayout(fontGroup)

        # Row 1: Point Size + Style
        self.pointSizeCombo = QtWidgets.QComboBox()
        self.pointSizeCombo.setEditable(True)
        for v in [6,8,9,10,11,12,14,16,18,24,30,36,48,60,72]:
            self.pointSizeCombo.addItem(str(v))
        self.pointSizeCombo.setCurrentText("14")

        self.styleCombo = QtWidgets.QComboBox()
        # text -> id mapping
        self.style_map = {
            "Default/Regular": 0,
            "Bold": 1,
            "Italic": 2,
            "Bold/Italic": 3,
            "Underline": 4,
            "Strikeout": 8,
        }
        for k in self.style_map.keys():
            self.styleCombo.addItem(k)

        pointSizeLabel = QtWidgets.QLabel("Point Size")
        pointSizeLabel.setToolTip("Size for font in points (72 dpi)")
        fgL.addWidget(pointSizeLabel, 0, 0)
        fgL.addWidget(self.pointSizeCombo, 0, 1)
        styleLabel = QtWidgets.QLabel("Style")
        styleLabel.setToolTip("Specify font style")
        fgL.addWidget(styleLabel, 0, 2)
        fgL.addWidget(self.styleCombo, 0, 3)

        # Row 2: Aspect ratio + Small Capitals
        self.aspectSpin = QtWidgets.QDoubleSpinBox()
        self.aspectSpin.setRange(0.01, 1000.0)
        self.aspectSpin.setDecimals(2)
        self.aspectSpin.setSingleStep(0.05)
        self.aspectSpin.setValue(1.0)

        self.smallCapsSpin = QtWidgets.QDoubleSpinBox()
        self.smallCapsSpin.setRange(0.0, 1000.0)
        self.smallCapsSpin.setDecimals(2)
        self.smallCapsSpin.setSingleStep(0.05)
        self.smallCapsSpin.setValue(0.0)

        aspectRatioLabel = QtWidgets.QLabel("Aspect Ratio")
        aspectRatioLabel.setToolTip("Specify font aspect ratio (1 = 1:1. 0.5 = half height)")
        fgL.addWidget(aspectRatioLabel, 1, 0)
        fgL.addWidget(self.aspectSpin, 1, 1)
        smallCapitalsLabel = QtWidgets.QLabel("Small Capitals")
        smallCapitalsLabel.setToolTip("Specify small capitals ratio (0.8 typical, 0 to disable). Makes lowercase use uppercase with this size ratio") 
        fgL.addWidget(smallCapitalsLabel, 1, 2)
        fgL.addWidget(self.smallCapsSpin, 1, 3)

        main.addWidget(fontGroup)

        # --- Outline effect group ---
        outlineGroup = QtWidgets.QGroupBox("Outline Effect")
        ogL = QtWidgets.QGridLayout(outlineGroup)

        self.outlineXSpin = QtWidgets.QSpinBox()
        self.outlineXSpin.setRange(-10000, 10000)
        self.outlineXSpin.setValue(0)

        self.outlineYSpin = QtWidgets.QSpinBox()
        self.outlineYSpin.setRange(-10000, 10000)
        self.outlineYSpin.setValue(0)

        self.outlineWSpin = QtWidgets.QSpinBox()
        self.outlineWSpin.setRange(0, 10000)
        self.outlineWSpin.setValue(0)

        self.outlineHSpin = QtWidgets.QSpinBox()
        self.outlineHSpin.setRange(0, 10000)
        self.outlineHSpin.setValue(0)

        self.colorBtn = ColorButton(QtGui.QColor(0, 0, 0, 255))
        colorLabel = QtWidgets.QLabel("Color")
        colorRow = QtWidgets.QHBoxLayout()
        colorRow.addWidget(colorLabel)
        colorRow.addWidget(self.colorBtn)
        colorRow.addStretch()

        ogL.addWidget(QtWidgets.QLabel("X Offset"), 0, 0)
        ogL.addWidget(self.outlineXSpin, 0, 1)
        ogL.addWidget(QtWidgets.QLabel("Y Offset"), 0, 2)
        ogL.addWidget(self.outlineYSpin, 0, 3)

        ogL.addWidget(QtWidgets.QLabel("Width"), 1, 0)
        ogL.addWidget(self.outlineWSpin, 1, 1)
        ogL.addWidget(QtWidgets.QLabel("Height"), 1, 2)
        ogL.addWidget(self.outlineHSpin, 1, 3)
        ogL.addLayout(colorRow, 1, 4)

        main.addWidget(outlineGroup)

        # --- Font raster group ---
        rasterGroup = QtWidgets.QGroupBox("Font Raster")
        rgL = QtWidgets.QHBoxLayout(rasterGroup)
        self.antialiasChk = QtWidgets.QCheckBox("Antialiased")
        self.antialiasChk.setToolTip("Specify antialiasing for font")
        self.antialiasChk.setChecked(True)
        self.bppCombo = QtWidgets.QComboBox()
        self.bpp_map = {
            "4-bit": 4,
            "8-bit": 8,
            "16-bit": 16,
            "32-bit": 32
        }
        for k in self.bpp_map.keys():
            self.bppCombo.addItem(k)
        self.bppCombo.setCurrentText("8-bit")
        rgL.addWidget(self.antialiasChk)
        rgL.addStretch()
        bitsPerPixelLabel = QtWidgets.QLabel("Bits Per Pixel")
        bitsPerPixelLabel.setToolTip("Specify bits per pixel for font texture")
        rgL.addWidget(QtWidgets.QLabel(bitsPerPixelLabel))
        rgL.addWidget(self.bppCombo)
        main.addWidget(rasterGroup)

        # --- Encoding group ---
        encGroup = QtWidgets.QGroupBox("Encoding and Charset")
        egL = QtWidgets.QHBoxLayout(encGroup)

        self.encodingCombo = QtWidgets.QComboBox()
        self.encodingCombo.addItems(["ASCII", "Unicode", "Windows-1251"])
        self.encodingCombo.setCurrentText("ASCII")
        self.encodingCombo.currentIndexChanged.connect(self.encodingComboIndexChanged)

        self.charsetCombo = QtWidgets.QComboBox()
        # name -> id mapping
        self.charset_map = [
            ("ANSI", 0), ("DEFAULT", 1), ("SYMBOL", 2),
            ("SHIFTJIS", 128), ("HANGUL", 129), ("GB2312", 134),
            ("CHINESEBIG5", 136), ("OEM", 255), ("JOHAB", 130),
            ("HEBREW", 177), ("ARABIC", 178), ("GREEK", 161),
            ("TURKISH", 162), ("VIETNAMESE", 163), ("THAI", 222),
            ("EASTEUROPE", 238), ("RUSSIAN", 204), ("MAC", 77),
            ("BALTIC", 186),
        ]
        for name, _id in self.charset_map:
            self.charsetCombo.addItem(name, _id)
        self.charsetCombo.setCurrentIndex(0)  # ANSI by default
        self.charsetCombo.currentIndexChanged.connect(self.charsetComboIndexChanged)

        encodingLabel = QtWidgets.QLabel("Encoding")
        encodingLabel.setToolTip("Specify encoding")
        egL.addWidget(encodingLabel)
        egL.addWidget(self.encodingCombo)
        egL.addSpacing(12)
        charsetLabel = QtWidgets.QLabel("Charset")
        charsetLabel.setToolTip("Specify font charset")
        egL.addWidget(charsetLabel)
        egL.addWidget(self.charsetCombo)
        egL.addStretch()
        main.addWidget(encGroup)

        # --- Spacing & Kerning group ---
        skGroup = QtWidgets.QGroupBox("Spacing and Kerning")
        skL = QtWidgets.QHBoxLayout(skGroup)

        self.tightenSpin = QtWidgets.QDoubleSpinBox()
        self.tightenSpin.setRange(0.0, 1000.0)
        self.tightenSpin.setDecimals(2)
        self.tightenSpin.setSingleStep(0.1)
        self.tightenSpin.setValue(1.0)

        self.trackingSpin = QtWidgets.QDoubleSpinBox()
        self.trackingSpin.setRange(-1000.0, 1000.0)
        self.trackingSpin.setDecimals(2)
        self.trackingSpin.setSingleStep(0.1)
        self.trackingSpin.setValue(0.0)

        self.formatCombo = QtWidgets.QComboBox()
        self.formatCombo.addItems(["Character12", "Character16"])
        self.formatCombo.setCurrentText("Character12")

        tightenLabel = QtWidgets.QLabel("Tighten")
        tightenLabel.setToolTip("Specify font tighten (1 = none, 0.8 narrow, 1.2 spaced out)")
        skL.addWidget(tightenLabel)
        skL.addWidget(self.tightenSpin)
        skL.addSpacing(12)
        trackingLabel = QtWidgets.QLabel("Tracking")
        trackingLabel.setToolTip("Specify font tracking")
        skL.addWidget(trackingLabel)
        skL.addWidget(self.trackingSpin)
        skL.addSpacing(12)
        formatLabel = QtWidgets.QLabel("Format")
        formatLabel.setToolTip("Specify character format layout")
        skL.addWidget(formatLabel)
        skL.addWidget(self.formatCombo)
        skL.addStretch()
        main.addWidget(skGroup)

        # Buttons
        btnRow = QtWidgets.QHBoxLayout()
        btnRow.addStretch()
        convertBtn = QtWidgets.QPushButton("Convert")
        closeBtn = QtWidgets.QPushButton("Close")
        convertBtn.clicked.connect(self.convert)
        closeBtn.clicked.connect(self.reject)
        btnRow.addWidget(convertBtn)
        btnRow.addWidget(closeBtn)
        main.addLayout(btnRow)

    def browse_input(self):
        path, _ = QtWidgets.QFileDialog.getOpenFileName(
            self, "Select TTF/OTF file", "", "Font files (*.ttf *.otf);;All files (*.*)"
        )
        if path:
            self.inputEdit.setText(path)

    def encodingComboIndexChanged(self, index):
        if self.encodingCombo.currentText() == "Windows-1251" or self.encodingCombo.currentText() == "Unicode":
            if self.charsetCombo.currentText() != "DEFAULT":
                self.charsetCombo.setCurrentText("DEFAULT")

    def charsetComboIndexChanged(self, index):
        if self.encodingCombo.currentText() == "Windows-1251" and self.charsetCombo.currentText() != "DEFAULT":
            self.encodingCombo.setCurrentText("ASCII")

    # Build OPTIONS_LIST according to spec
    def build_options(self):
        opts = []

        # Point Size
        ps_text = self.pointSizeCombo.currentText().strip()
        if ps_text:
            try:
                ps_val = int(round(float(ps_text)))
                opts.append(f"-pointsize{ps_val}")
            except ValueError:
                pass

        # Style
        style_text = self.styleCombo.currentText()
        style_id = self.style_map.get(style_text, 0)
        if style_id != 0:
            opts.append(f"-style{style_id}")

        # Aspect ratio
        aspect = self.aspectSpin.value()
        if abs(aspect - 1.0) > 1e-9:
            opts.append(f"-aspect{self.clean_float(aspect)}")

        # Small capitals
        smallcaps = self.smallCapsSpin.value()
        if abs(smallcaps - 0.0) > 1e-9:
            opts.append(f"-smallcaps{self.clean_float(smallcaps)}")

        # Outline effect
        ox = self.outlineXSpin.value()
        oy = self.outlineYSpin.value()
        ow = self.outlineWSpin.value()
        oh = self.outlineHSpin.value()
        if any(v != 0 for v in (ox, oy, ow, oh)):
            color_hex = rgba_to_hex(self.colorBtn.color())
            opts.append(f"-outline{ox},{oy},{ow},{oh},{color_hex}")

        # Font raster
        if self.antialiasChk.isChecked():
            opts.append("-antialias1")
        bpp_label = self.bppCombo.currentText()
        opts.append(f"-bpp{self.bpp_map.get(bpp_label, 8)}")

        # Encoding
        enc = self.encodingCombo.currentText()
        if enc == "ASCII":
            opts.append("-ascii1")
        elif enc == "Windows-1251":
            opts.append("-windows12511")
        # Unicode -> no option

        # Charset: "If not DEFAULT - add -charsetX"
        charset_id = self.charsetCombo.currentData()
        charset_name = self.charsetCombo.currentText()
        if charset_name != "DEFAULT":
            opts.append(f"-charset{charset_id}")

        # Spacing & Kerning
        tighten = self.tightenSpin.value()
        if abs(tighten - 1.0) > 1e-9:
            opts.append(f"-tighten{self.clean_float(tighten)}")

        tracking = self.trackingSpin.value()
        if abs(tracking - 0.0) > 1e-9:
            opts.append(f"-tracking{self.clean_float(tracking)}")

        # Format
        if self.formatCombo.currentText() == "Character16":
            opts.append("-char16")
        
        # test
        #opts.append("-cramspace4")

        return opts

    @staticmethod
    def clean_float(val: float) -> str:
        # trim trailing zeros and dot
        s = f"{val:.6f}".rstrip('0').rstrip('.')
        return s if s else "0"

    def convert(self):
        in_path = self.inputEdit.text().strip()
        if not in_path or not os.path.isfile(in_path):
            QtWidgets.QMessageBox.warning(self, "Input required", "Please select a valid TTF/OTF file.")
            return

        out_path, _ = QtWidgets.QFileDialog.getSaveFileName(
            self, "Save font file as", os.path.splitext(in_path)[0] + ".ffn", "PC Font File (*.ffn);;Sony PS2 Font File (*.sfn);;GameCube Font File (*.gfn);;Xbox Font File (*.xfn);;Macintosh Font File (*.mfn);;PSX Font File (*.pfn);;All files (*.*)"
        )
        if not out_path:
            return

        opts = self.build_options()
        args = [f'"{in_path}"'] + opts + [f'-="{out_path}"']
        
        #cmd_display = gx_path() + " " + " ".join(quoted(a) for a in args)
        #QtWidgets.QMessageBox.information(self, "About to run", f"Command:\n{cmd_display}")

        self.setDisabled(True)
        QtWidgets.QApplication.processEvents()

        ok, _, _ = run_gx(self, args)
        #if ok:
        #    QtWidgets.QMessageBox.information(self, "Done", f"Saved:\n{out_path}")
        #    self.accept()

        self.setDisabled(False)


# ----- FFN -> FSH Window -----
class FfnToFshWindow(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("FFN to FSH")
        self.setModal(True)
        self.setMinimumWidth(560)

        main = QtWidgets.QVBoxLayout(self)

        self.inputEdit = QtWidgets.QLineEdit()
        browseBtn = QtWidgets.QPushButton("Browse...")
        browseBtn.clicked.connect(self.browse_input)
        row1 = QtWidgets.QHBoxLayout()
        row1.addWidget(self.inputEdit)
        row1.addWidget(browseBtn)
        main.addLayout(row1)

        btnRow = QtWidgets.QHBoxLayout()
        btnRow.addStretch()
        convertBtn = QtWidgets.QPushButton("Convert")
        closeBtn = QtWidgets.QPushButton("Close")
        convertBtn.clicked.connect(self.convert)
        closeBtn.clicked.connect(self.reject)
        btnRow.addWidget(convertBtn)
        btnRow.addWidget(closeBtn)
        main.addLayout(btnRow)

    def browse_input(self):
        path, _ = QtWidgets.QFileDialog.getOpenFileName(
            self, "Select font file", "", "PC Font File (*.ffn);;Sony PS2 Font File (*.sfn);;GameCube Font File (*.gfn);;Xbox Font File (*.xfn);;Macintosh Font File (*.mfn);;PSX Font File (*.pfn);;All files (*.*)"
        )
        if path:
            self.inputEdit.setText(path)

    def convert(self):
        in_path = self.inputEdit.text().strip()
        if not in_path or not os.path.isfile(in_path):
            QtWidgets.QMessageBox.warning(self, "Input required", "Please select a valid FFN file.")
            return

        out_path, _ = QtWidgets.QFileDialog.getSaveFileName(
            self, "Save FSH file as", os.path.splitext(in_path)[0] + ".fsh", "FSH files (*.fsh);;All files (*.*)"
        )
        if not out_path:
            return

        self.setDisabled(True)
        QtWidgets.QApplication.processEvents()

        try:
            convert_ffn_to_fsh(in_path, out_path)
            #QtWidgets.QMessageBox.information(self, "Done", f"Saved:\n{out_path}")
            #self.accept()
        except Exception as e:
            QtWidgets.QMessageBox.critical(self, "Conversion failed", str(e))

        self.setDisabled(False)


# ----- FFN -> PNG Window -----
class FfnToPngWindow(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("FFN to PNG")
        self.setModal(True)
        self.setMinimumWidth(560)

        main = QtWidgets.QVBoxLayout(self)

        self.inputEdit = QtWidgets.QLineEdit()
        browseBtn = QtWidgets.QPushButton("Browse...")
        browseBtn.clicked.connect(self.browse_input)
        row1 = QtWidgets.QHBoxLayout()
        row1.addWidget(self.inputEdit)
        row1.addWidget(browseBtn)
        main.addLayout(row1)

        self.withBgChk = QtWidgets.QCheckBox("With background")
        main.addWidget(self.withBgChk)

        btnRow = QtWidgets.QHBoxLayout()
        btnRow.addStretch()
        convertBtn = QtWidgets.QPushButton("Convert")
        closeBtn = QtWidgets.QPushButton("Close")
        convertBtn.clicked.connect(self.convert)
        closeBtn.clicked.connect(self.reject)
        btnRow.addWidget(convertBtn)
        btnRow.addWidget(closeBtn)
        main.addLayout(btnRow)

    def browse_input(self):
        path, _ = QtWidgets.QFileDialog.getOpenFileName(
            self, "Select font file", "", "PC Font File (*.ffn);;Sony PS2 Font File (*.sfn);;GameCube Font File (*.gfn);;Xbox Font File (*.xfn);;Macintosh Font File (*.mfn);;PSX Font File (*.pfn);;All files (*.*)"
        )
        if path:
            self.inputEdit.setText(path)

    def convert(self):
        in_path = self.inputEdit.text().strip()
        if not in_path or not os.path.isfile(in_path):
            QtWidgets.QMessageBox.warning(self, "Input required", "Please select a valid FFN file.")
            return

        out_path, _ = QtWidgets.QFileDialog.getSaveFileName(
            self, "Save PNG file as", os.path.splitext(in_path)[0] + ".png", "PNG files (*.png);;All files (*.*)"
        )
        if not out_path:
            return

        # 1) FFN -> temp FSH
        try:
            tmp_dir = tempfile.mkdtemp(prefix="ffn2png_")
            ext = os.path.splitext(in_path)[1].lstrip(".").lower()
            if ext:  
                letter = ext[0]
            else:
                letter = "f"
            tmp_fsh = os.path.join(tmp_dir, f"temp.{letter}sh")
            convert_ffn_to_fsh(in_path, tmp_fsh)
        except Exception as e:
            QtWidgets.QMessageBox.critical(self, "FFN to FSH failed", str(e))
            return

        # 2) FSH -> PNG via gx.exe
        if not ensure_gx_exists(self):
            return

        args = [f'"{tmp_fsh}"']
        if self.withBgChk.isChecked():
            args += ["-backgroundBLACK", "+0", "-24"]
        args += [f'-="{out_path}"']

        self.setDisabled(True)
        QtWidgets.QApplication.processEvents()
        
        ok, _, _ = run_gx(self, args)
        try:
            # best-effort cleanup
            if os.path.isfile(tmp_fsh):
                os.remove(tmp_fsh)
            if os.path.isdir(tmp_dir):
                os.rmdir(tmp_dir)
        except Exception:
            pass

        #if ok:
            #QtWidgets.QMessageBox.information(self, "Done", f"Saved:\n{out_path}")
            #self.accept()
        
        self.setDisabled(False)


# ----- Main Window -----
class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowIcon(QtGui.QIcon(":/icon.png"))
        self.setWindowTitle(APP_TITLE)
        central = QtWidgets.QWidget()
        central.setObjectName("centralWidget")
        central.setStyleSheet("""
            #centralWidget {
                background-image: url(:/background.png);
                background-repeat: no-repeat;
                background-position: center;
            }
        """)
        self.setCentralWidget(central)
        self.setFixedSize(640, 480)

        layout = QtWidgets.QGridLayout(central)
        layout.setContentsMargins(16, 16, 16, 16)
        layout.setSpacing(12)
        
        largeFont = QFont()
        largeFont.setPointSize(12)

        btn1 = QtWidgets.QPushButton("TTF/OTF to FFN")
        btn2 = QtWidgets.QPushButton("FFN to FSH")
        btn3 = QtWidgets.QPushButton("FFN to PNG")
        btn1.setFont(largeFont)
        btn2.setFont(largeFont)
        btn3.setFont(largeFont)

        btn1.clicked.connect(self.open_ttf_to_ffn)
        btn2.clicked.connect(self.open_ffn_to_fsh)
        btn3.clicked.connect(self.open_ffn_to_png)
        
        button_layout = QtWidgets.QVBoxLayout()
        button_layout.addStretch()
        for b in (btn1, btn2, btn3):
            b.setFixedHeight(48)
            b.setFixedWidth(350)
            button_layout.addWidget(b, alignment=QtCore.Qt.AlignHCenter)
        button_layout.addStretch()

        layout.addLayout(button_layout, 0, 0, 1, 1, QtCore.Qt.AlignCenter)
        
        font = QFont()
        font.setPointSize(10)
        
        info_label = QtWidgets.QLabel(
            "<b>FFN</b> - Windows &nbsp;&nbsp;"
            "<b>SFN</b> - PlayStation 2 &nbsp;&nbsp;"
            "<b>GFN</b> - GameCube &nbsp;&nbsp;"
            "<b>XFN</b> - Xbox &nbsp;&nbsp;"
            "<b>PFN</b> - PlayStation &nbsp;&nbsp;"
            "<b>MFN</b> - Macintosh"
        )
        info_label.setFont(font)
        layout.addWidget(info_label, 0, 0, 1, 1, QtCore.Qt.AlignLeft | QtCore.Qt.AlignBottom)

    def open_ttf_to_ffn(self):
        dlg = TtfToFfnWindow(self)
        dlg.exec_()

    def open_ffn_to_fsh(self):
        dlg = FfnToFshWindow(self)
        dlg.exec_()

    def open_ffn_to_png(self):
        dlg = FfnToPngWindow(self)
        dlg.exec_()


def main():
    QtWidgets.QApplication.setAttribute(QtCore.Qt.AA_EnableHighDpiScaling, True)
    app = QtWidgets.QApplication(sys.argv)
    app.setStyle("Fusion")
    w = MainWindow()
    w.resize(560, 120)
    w.show()
    sys.exit(app.exec_())


if __name__ == "__main__":
    main()
