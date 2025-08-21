del /s /q build
py -3.7 -m PyInstaller --noconsole --icon=icon.ico --onefile --distpath ./output "FFN Studio.py"