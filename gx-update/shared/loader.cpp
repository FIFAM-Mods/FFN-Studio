#include "loader.h"
#include "plugin-std.h"
#include <string>
#include <map>
#include "FifamReadWrite.h"
#include <Windows.h>
#include <wchar.h>
#include <fstream>
#include <iomanip>
#include <filesystem>

using namespace std;
using namespace plugin;

unsigned int GetBaseAddress() {
    static unsigned int addr = reinterpret_cast<unsigned int>(GetModuleHandleA(NULL));
    return addr;
}

unsigned int GX(unsigned int address) {
    return GetBaseAddress() - 0x400000 + address;
}

void DumpToHex(const wchar_t *filename, unsigned char *data, size_t dataSize) {
    FILE *fp = _wfopen(filename, L"w");
    if (!fp) {
        return;
    }
    for (size_t i = 0; i < dataSize; ++i) {
        if (i % 16 == 0) {
            if (i > 0) {
                fprintf(fp, "\n");
            }
        }
        else {
            fprintf(fp, " ");
        }
        fprintf(fp, "%02X", data[i]);
    }
    if (dataSize > 0) {
        fprintf(fp, "\n");
    }
    fclose(fp);
}

HMODULE gimex;
char faceName[1024] = {};
bool Windows1251 = false;

UInt Gimex(UInt addr) {
    return (UInt)gimex + addr;
}

const std::map<unsigned int, unsigned char> UnicodeToWin1251 = {
    {0x0000, 0x00}, // U+0000
    {0x0001, 0x01}, // U+0001
    {0x0002, 0x02}, // U+0002
    {0x0003, 0x03}, // U+0003
    {0x0004, 0x04}, // U+0004
    {0x0005, 0x05}, // U+0005
    {0x0006, 0x06}, // U+0006
    {0x0007, 0x07}, // U+0007
    {0x0008, 0x08}, // U+0008
    {0x0009, 0x09}, // U+0009
    {0x000A, 0x0A}, // U+000A
    {0x000B, 0x0B}, // U+000B
    {0x000C, 0x0C}, // U+000C
    {0x000D, 0x0D}, // U+000D
    {0x000E, 0x0E}, // U+000E
    {0x000F, 0x0F}, // U+000F
    {0x0010, 0x10}, // U+0010
    {0x0011, 0x11}, // U+0011
    {0x0012, 0x12}, // U+0012
    {0x0013, 0x13}, // U+0013
    {0x0014, 0x14}, // U+0014
    {0x0015, 0x15}, // U+0015
    {0x0016, 0x16}, // U+0016
    {0x0017, 0x17}, // U+0017
    {0x0018, 0x18}, // U+0018
    {0x0019, 0x19}, // U+0019
    {0x001A, 0x1A}, // U+001A
    {0x001B, 0x1B}, // U+001B
    {0x001C, 0x1C}, // U+001C
    {0x001D, 0x1D}, // U+001D
    {0x001E, 0x1E}, // U+001E
    {0x001F, 0x1F}, // U+001F
    {0x0020, 0x20}, // ' '
    {0x0021, 0x21}, // '!'
    {0x0022, 0x22}, // '"'
    {0x0023, 0x23}, // '#'
    {0x0024, 0x24}, // '$'
    {0x0025, 0x25}, // '%'
    {0x0026, 0x26}, // '&'
    {0x0027, 0x27}, // '''
    {0x0028, 0x28}, // '('
    {0x0029, 0x29}, // ')'
    {0x002A, 0x2A}, // '*'
    {0x002B, 0x2B}, // '+'
    {0x002C, 0x2C}, // ','
    {0x002D, 0x2D}, // '-'
    {0x002E, 0x2E}, // '.'
    {0x002F, 0x2F}, // '/'
    {0x0030, 0x30}, // '0'
    {0x0031, 0x31}, // '1'
    {0x0032, 0x32}, // '2'
    {0x0033, 0x33}, // '3'
    {0x0034, 0x34}, // '4'
    {0x0035, 0x35}, // '5'
    {0x0036, 0x36}, // '6'
    {0x0037, 0x37}, // '7'
    {0x0038, 0x38}, // '8'
    {0x0039, 0x39}, // '9'
    {0x003A, 0x3A}, // ':'
    {0x003B, 0x3B}, // ';'
    {0x003C, 0x3C}, // '<'
    {0x003D, 0x3D}, // '='
    {0x003E, 0x3E}, // '>'
    {0x003F, 0x3F}, // '?'
    {0x0040, 0x40}, // '@'
    {0x0041, 0x41}, // 'A'
    {0x0042, 0x42}, // 'B'
    {0x0043, 0x43}, // 'C'
    {0x0044, 0x44}, // 'D'
    {0x0045, 0x45}, // 'E'
    {0x0046, 0x46}, // 'F'
    {0x0047, 0x47}, // 'G'
    {0x0048, 0x48}, // 'H'
    {0x0049, 0x49}, // 'I'
    {0x004A, 0x4A}, // 'J'
    {0x004B, 0x4B}, // 'K'
    {0x004C, 0x4C}, // 'L'
    {0x004D, 0x4D}, // 'M'
    {0x004E, 0x4E}, // 'N'
    {0x004F, 0x4F}, // 'O'
    {0x0050, 0x50}, // 'P'
    {0x0051, 0x51}, // 'Q'
    {0x0052, 0x52}, // 'R'
    {0x0053, 0x53}, // 'S'
    {0x0054, 0x54}, // 'T'
    {0x0055, 0x55}, // 'U'
    {0x0056, 0x56}, // 'V'
    {0x0057, 0x57}, // 'W'
    {0x0058, 0x58}, // 'X'
    {0x0059, 0x59}, // 'Y'
    {0x005A, 0x5A}, // 'Z'
    {0x005B, 0x5B}, // '['
    {0x005C, 0x5C}, // '\'
    {0x005D, 0x5D}, // ']'
    {0x005E, 0x5E}, // '^'
    {0x005F, 0x5F}, // '_'
    {0x0060, 0x60}, // '`'
    {0x0061, 0x61}, // 'a'
    {0x0062, 0x62}, // 'b'
    {0x0063, 0x63}, // 'c'
    {0x0064, 0x64}, // 'd'
    {0x0065, 0x65}, // 'e'
    {0x0066, 0x66}, // 'f'
    {0x0067, 0x67}, // 'g'
    {0x0068, 0x68}, // 'h'
    {0x0069, 0x69}, // 'i'
    {0x006A, 0x6A}, // 'j'
    {0x006B, 0x6B}, // 'k'
    {0x006C, 0x6C}, // 'l'
    {0x006D, 0x6D}, // 'm'
    {0x006E, 0x6E}, // 'n'
    {0x006F, 0x6F}, // 'o'
    {0x0070, 0x70}, // 'p'
    {0x0071, 0x71}, // 'q'
    {0x0072, 0x72}, // 'r'
    {0x0073, 0x73}, // 's'
    {0x0074, 0x74}, // 't'
    {0x0075, 0x75}, // 'u'
    {0x0076, 0x76}, // 'v'
    {0x0077, 0x77}, // 'w'
    {0x0078, 0x78}, // 'x'
    {0x0079, 0x79}, // 'y'
    {0x007A, 0x7A}, // 'z'
    {0x007B, 0x7B}, // '{'
    {0x007C, 0x7C}, // '|'
    {0x007D, 0x7D}, // '}'
    {0x007E, 0x7E}, // '~'
    {0x007F, 0x7F}, // U+007F
    {0x0402, 0x80}, // 'Ђ'
    {0x0403, 0x81}, // 'Ѓ'
    {0x201A, 0x82}, // '‚'
    {0x0453, 0x83}, // 'ѓ'
    {0x201E, 0x84}, // '„'
    {0x2026, 0x85}, // '…'
    {0x2020, 0x86}, // '†'
    {0x2021, 0x87}, // '‡'
    {0x20AC, 0x88}, // '€'
    {0x2030, 0x89}, // '‰'
    {0x0409, 0x8A}, // 'Љ'
    {0x2039, 0x8B}, // '‹'
    {0x040A, 0x8C}, // 'Њ'
    {0x040C, 0x8D}, // 'Ќ'
    {0x040B, 0x8E}, // 'Ћ'
    {0x040F, 0x8F}, // 'Џ'
    {0x0452, 0x90}, // 'ђ'
    {0x2018, 0x91}, // '‘'
    {0x2019, 0x92}, // '’'
    {0x201C, 0x93}, // '“'
    {0x201D, 0x94}, // '”'
    {0x2022, 0x95}, // '•'
    {0x2013, 0x96}, // '–'
    {0x2014, 0x97}, // '—'
    {0x2122, 0x99}, // '™'
    {0x0459, 0x9A}, // 'љ'
    {0x203A, 0x9B}, // '›'
    {0x045A, 0x9C}, // 'њ'
    {0x045C, 0x9D}, // 'ќ'
    {0x045B, 0x9E}, // 'ћ'
    {0x045F, 0x9F}, // 'џ'
    {0x00A0, 0xA0}, // NO-BREAK SPACE
    {0x040E, 0xA1}, // 'Ў'
    {0x045E, 0xA2}, // 'ў'
    {0x0408, 0xA3}, // 'Ј'
    {0x00A4, 0xA4}, // '¤'
    {0x0490, 0xA5}, // 'Ґ'
    {0x00A6, 0xA6}, // '¦'
    {0x00A7, 0xA7}, // '§'
    {0x0401, 0xA8}, // 'Ё'
    {0x00A9, 0xA9}, // '©'
    {0x0404, 0xAA}, // 'Є'
    {0x00AB, 0xAB}, // '«'
    {0x00AC, 0xAC}, // '¬'
    {0x00AD, 0xAD}, // SOFT HYPHEN
    {0x00AE, 0xAE}, // '®'
    {0x0407, 0xAF}, // 'Ї'
    {0x00B0, 0xB0}, // '°'
    {0x00B1, 0xB1}, // '±'
    {0x0406, 0xB2}, // 'І'
    {0x0456, 0xB3}, // 'і'
    {0x0491, 0xB4}, // 'ґ'
    {0x00B5, 0xB5}, // 'µ'
    {0x00B6, 0xB6}, // '¶'
    {0x00B7, 0xB7}, // '·'
    {0x0451, 0xB8}, // 'ё'
    {0x2116, 0xB9}, // '№'
    {0x0454, 0xBA}, // 'є'
    {0x00BB, 0xBB}, // '»'
    {0x0458, 0xBC}, // 'ј'
    {0x0405, 0xBD}, // 'Ѕ'
    {0x0455, 0xBE}, // 'ѕ'
    {0x0457, 0xBF}, // 'ї'
    {0x0410, 0xC0}, // 'А'
    {0x0411, 0xC1}, // 'Б'
    {0x0412, 0xC2}, // 'В'
    {0x0413, 0xC3}, // 'Г'
    {0x0414, 0xC4}, // 'Д'
    {0x0415, 0xC5}, // 'Е'
    {0x0416, 0xC6}, // 'Ж'
    {0x0417, 0xC7}, // 'З'
    {0x0418, 0xC8}, // 'И'
    {0x0419, 0xC9}, // 'Й'
    {0x041A, 0xCA}, // 'К'
    {0x041B, 0xCB}, // 'Л'
    {0x041C, 0xCC}, // 'М'
    {0x041D, 0xCD}, // 'Н'
    {0x041E, 0xCE}, // 'О'
    {0x041F, 0xCF}, // 'П'
    {0x0420, 0xD0}, // 'Р'
    {0x0421, 0xD1}, // 'С'
    {0x0422, 0xD2}, // 'Т'
    {0x0423, 0xD3}, // 'У'
    {0x0424, 0xD4}, // 'Ф'
    {0x0425, 0xD5}, // 'Х'
    {0x0426, 0xD6}, // 'Ц'
    {0x0427, 0xD7}, // 'Ч'
    {0x0428, 0xD8}, // 'Ш'
    {0x0429, 0xD9}, // 'Щ'
    {0x042A, 0xDA}, // 'Ъ'
    {0x042B, 0xDB}, // 'Ы'
    {0x042C, 0xDC}, // 'Ь'
    {0x042D, 0xDD}, // 'Э'
    {0x042E, 0xDE}, // 'Ю'
    {0x042F, 0xDF}, // 'Я'
    {0x0430, 0xE0}, // 'а'
    {0x0431, 0xE1}, // 'б'
    {0x0432, 0xE2}, // 'в'
    {0x0433, 0xE3}, // 'г'
    {0x0434, 0xE4}, // 'д'
    {0x0435, 0xE5}, // 'е'
    {0x0436, 0xE6}, // 'ж'
    {0x0437, 0xE7}, // 'з'
    {0x0438, 0xE8}, // 'и'
    {0x0439, 0xE9}, // 'й'
    {0x043A, 0xEA}, // 'к'
    {0x043B, 0xEB}, // 'л'
    {0x043C, 0xEC}, // 'м'
    {0x043D, 0xED}, // 'н'
    {0x043E, 0xEE}, // 'о'
    {0x043F, 0xEF}, // 'п'
    {0x0440, 0xF0}, // 'р'
    {0x0441, 0xF1}, // 'с'
    {0x0442, 0xF2}, // 'т'
    {0x0443, 0xF3}, // 'у'
    {0x0444, 0xF4}, // 'ф'
    {0x0445, 0xF5}, // 'х'
    {0x0446, 0xF6}, // 'ц'
    {0x0447, 0xF7}, // 'ч'
    {0x0448, 0xF8}, // 'ш'
    {0x0449, 0xF9}, // 'щ'
    {0x044A, 0xFA}, // 'ъ'
    {0x044B, 0xFB}, // 'ы'
    {0x044C, 0xFC}, // 'ь'
    {0x044D, 0xFD}, // 'э'
    {0x044E, 0xFE}, // 'ю'
    {0x044F, 0xFF}, // 'я'
};

unsigned int GetUnicodeCharater1251Code(unsigned int ucode) {
    auto it = UnicodeToWin1251.find(ucode);
    if (it != UnicodeToWin1251.end())
        return (*it).second;
    return 0;
}

int TTF_REAL2INT(float x) {
    return ((int)(((float)(x)) + ((((float)(x)) >= 0.0f) ? 0.5f : -0.5f)));
}

int WINAPI TTF_frameindex(HDC hdc, void *) {
    bool &ttf_ascii = *(bool *)Gimex(0x1FB208);
    unsigned short *ttf_frametounicode = (unsigned short *)Gimex(0x1FB650);
    int frames = 0;
    int glyphsetsize = GetFontUnicodeRanges(hdc, NULL);
    GLYPHSET *glyphset = (GLYPHSET *)malloc(glyphsetsize);
    GetFontUnicodeRanges(hdc, glyphset);
    for (int range = 0; range < (int)glyphset->cRanges; ++range) {
        for (int unicode = 0; unicode < glyphset->ranges[range].cGlyphs; ++unicode) {
            int code = glyphset->ranges[range].wcLow + unicode;
            if (code >= 32) {
                if (Windows1251) {
                    if (GetUnicodeCharater1251Code(code))
                        ttf_frametounicode[frames++] = code;
                }
                else if (!ttf_ascii || (code < 256))
                    ttf_frametounicode[frames++] = code;
            }
        }
    }
    free(glyphset);
    return frames;
}

typedef BOOL(WINAPI *PGetFontResourceInfoW)(LPCWSTR lpszFilename, LPDWORD cbBuffer, LPVOID lpBuffer, DWORD dwQueryType);

PGetFontResourceInfoW LoadGetFontResourceInfoW(void) {
    HMODULE hGdi32 = GetModuleHandleW(L"gdi32.dll");
    if (!hGdi32) return NULL;
    return (PGetFontResourceInfoW)GetProcAddress(hGdi32, "GetFontResourceInfoW");
}

std::vector<std::wstring> GetTtfFonts(const wchar_t *ttfPath) {
    std::vector<std::wstring> result;
    auto pGFRI = LoadGetFontResourceInfoW();
    if (!pGFRI) return result;
    int added = AddFontResourceExW(ttfPath, FR_PRIVATE, nullptr);
    if (added <= 0) return result;
    DWORD faces = 0, cb = sizeof(faces);
    if (!pGFRI(ttfPath, &cb, &faces, 0) || faces == 0)
        faces = (DWORD)added;
    cb = faces * sizeof(LOGFONTW);
    std::vector<LOGFONTW> lfs(faces);
    if (pGFRI(ttfPath, &cb, lfs.data(), 2)) {
        size_t count = cb / sizeof(LOGFONTW);
        for (size_t i = 0; i < count; ++i)
            result.emplace_back(lfs[i].lfFaceName);
    }
    RemoveFontResourceExW(ttfPath, FR_PRIVATE, nullptr);
    return result;
}

int WINAPI TTF_Open(void **gxptr, void *g, const char *pathname, bool framecountflag) {
    //::Error(faceName);
    wchar_t *ttf_fontname = (wchar_t *)Gimex(0x1FB190);
    wchar_t *ttf_pathname = (wchar_t *)Gimex(0x1FB250);
    //wcscpy(ttf_pathname, pathname);
    if (faceName[0])
        wcscpy(ttf_fontname, Utils::AtoW(faceName).c_str());
    else {
        auto fonts = GetTtfFonts(Utils::AtoW(pathname).c_str());
        if (!fonts.empty())
            wcscpy(ttf_fontname, fonts[0].c_str());
        else
            return 0;
        //::Error(L"Found fonts in %s:\n%s", Utils::AtoW(pathname).c_str(), Utils::Join(fonts, L", ").c_str());
    }
    return CallMethodAndReturnDynGlobal<int>(Gimex(0xD0930), 0, gxptr, g, pathname, framecountflag);
}

bool Ascii = false;

int WINAPI TTF_Info(void *gx, int framenum) {
    void *ttf = *raw_ptr<void *>(gx, 20);
    Ascii = *raw_ptr<int>(ttf, 30);
    return CallMethodAndReturnDynGlobal<int>(Gimex(0xD0D10), 0, gx, framenum);
}

//void METHOD TTF_pathtofontname(HDC hdc, wchar_t *fontnamebuf, int *style, wchar_t const *pathname) {
//    *style = 0;
//    fontnamebuf
//    auto ff = GetTtfFonts(pathname);
//    
//}

int CheckFontOption(char const *str, char const *substr, size_t size) {
    if (!_strnicmp(str, "font", 4))
        return 0;
    return _strnicmp(str, substr, size);
}

char const *METHOD GetFontOption(char *out, char const *in, bool strip_outer, bool keep_ops) {
    char const *pArgName = in - 9;
    if (!_strnicmp(pArgName, "font", 4)) {
        auto result = CallFastcallAndReturnDynGlobal<char *>(GX(0x4D4ED0), faceName, pArgName + 4);
        auto len = strlen(faceName);
        for (size_t i = 0; i < len; i++) {
            if (faceName[i] == '*')
                faceName[i] = ' ';
        }
        return result;
    }
    return CallFastcallAndReturnDynGlobal<char *>(GX(0x4B2960), out, in);
}

int CheckWindows1251Option(char const *str, char const *substr, size_t size) {
    if (!_strnicmp(str, "windows1251", 11))
        return 0;
    return _strnicmp(str, substr, size);
}

char const *METHOD GetWindows1251Option(char *out, char const *in, bool strip_outer, bool keep_ops) {
    char const *pArgName = in - 5;
    if (!_strnicmp(pArgName, "windows1251", 11)) {
        char OPTwindows1251[256];
        auto result = CallFastcallAndReturnDynGlobal<char *>(GX(0x4B2960), OPTwindows1251, pArgName + 11);
        if (strlen(OPTwindows1251) == 1)
            Windows1251 = OPTwindows1251[0] == 1;
        return result;
    }
    return CallFastcallAndReturnDynGlobal<char *>(GX(0x4B2960), out, in);
}

void FontPrintCodeNameSmall(char *out, char const *format, unsigned int code, int, int) {
    if (Windows1251)
        code = GetUnicodeCharater1251Code(code);
    sprintf(out, format, code, code, code);
}

void FontPrintCodeNameLarge(char *out, char const *format, unsigned int code, int) {
    if (Windows1251)
        code = GetUnicodeCharater1251Code(code);
    sprintf(out, format, code, code);
}

std::vector<KERNINGPAIR> &VecKerningPairs() {
    static std::vector<KERNINGPAIR> kerningPairs;
    return kerningPairs;
}

DWORD WINAPI GetKerningPairsSize(HDC hdc, DWORD, LPKERNINGPAIR) {
    VecKerningPairs().clear();
    int numkerns = GetKerningPairs(hdc, 0, NULL);
    if (numkerns) {
        KERNINGPAIR *kerningpair = (KERNINGPAIR *)malloc(numkerns * sizeof(KERNINGPAIR));
        GetKerningPairs(hdc, numkerns, kerningpair);
        for (int i = 0; i < numkerns; ++i) {
            unsigned int prevunicode = (unsigned int)kerningpair[i].wFirst;
            if (prevunicode >= 32) {
                bool add = true;
                if (Windows1251) {
                    UInt code = GetUnicodeCharater1251Code(prevunicode);
                    if (code != 0)
                        kerningpair[i].wFirst = code;
                    else
                        add = false;
                }
                else if (Ascii) {
                    add = prevunicode < 256;
                }
                if (add)
                    VecKerningPairs().push_back(kerningpair[i]);
            }
        }
        free(kerningpair);
    }
    return VecKerningPairs().size();
}

DWORD WINAPI GerFontKerningPairs(HDC hdc, DWORD nPairs, KERNINGPAIR *kernPairs) {
    memcpy(kernPairs, VecKerningPairs().data(), VecKerningPairs().size() * sizeof(KERNINGPAIR));
    return VecKerningPairs().size();
}

void loader::InstallPatches() {
    std::wstring procDir = loader::GetModuleDir(NULL);
    gimex = LoadLibraryA("gimex.dll");
    patch::Nop(Gimex(0xCFD90), 56);
    patch::SetPointer(Gimex(0x1F30FC), TTF_Open);
    patch::SetPointer(Gimex(0x1F3100), TTF_Info);
    //patch::RedirectCall(Gimex(0xD0A39), TTF_pathtofontname);
    patch::RedirectCall(GX(0x4C9FF6), CheckFontOption);
    patch::RedirectCall(GX(0x4CA011), GetFontOption);
    patch::RedirectCall(GX(0x4CDC0A), CheckWindows1251Option);
    patch::RedirectCall(GX(0x4CDC25), GetWindows1251Option);
    patch::RedirectCall(Gimex(0xD0C3A), TTF_frameindex);
    patch::SetUShort(Gimex(0xD0C3A) + 5, 0xF88B); // mov edi, eax
    patch::RedirectJump(Gimex(0xD0C3A) + 7, (void *)Gimex(0xD0CB0));
    patch::RedirectCall(Gimex(0xD14E4), FontPrintCodeNameSmall);
    patch::RedirectCall(Gimex(0xD14F4), FontPrintCodeNameLarge);
    patch::RedirectCall(Gimex(0xD13B9), GetKerningPairsSize);
    patch::Nop(Gimex(0xD13B9) + 5, 1);
    patch::RedirectCall(Gimex(0xD13E6), GerFontKerningPairs);
    patch::Nop(Gimex(0xD13E6) + 5, 1);
}

void loader::UninstallPatches() {
    FreeLibrary(gimex);
}

bool loader::LoadLib(std::wstring const &libName, HMODULE &handle) {
    wchar_t systemDir[MAX_PATH + 1];
    GetSystemDirectoryW(systemDir, MAX_PATH);
    auto libPath = std::wstring(systemDir) + L"\\" + libName;
    handle = LoadLibraryW(libPath.c_str());
    if (handle == 0)
        return false;
    return true;
}

void loader::Load() {
    HMODULE hExecutableInstance = GetModuleHandle(NULL);
    IMAGE_NT_HEADERS* ntHeader = (IMAGE_NT_HEADERS*)((DWORD)hExecutableInstance + ((IMAGE_DOS_HEADER*)hExecutableInstance)->e_lfanew);
    SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
    DWORD oldProtect;
    VirtualProtect((VOID*)hExecutableInstance, size, PAGE_EXECUTE_READWRITE, &oldProtect);
    InstallPatches();
}

void loader::Unload() {
    UninstallPatches();
}

std::wstring loader::GetModulePath(HMODULE hmodule) {
    static constexpr auto INITIAL_BUFFER_SIZE = MAX_PATH;
    static constexpr auto MAX_ITERATIONS = 7;
    std::wstring ret;
    auto bufferSize = INITIAL_BUFFER_SIZE;
    for (size_t iterations = 0; iterations < MAX_ITERATIONS; ++iterations) {
        ret.resize(bufferSize);
        auto charsReturned = GetModuleFileNameW(hmodule, &ret[0], bufferSize);
        if (charsReturned < ret.length()) {
            ret.resize(charsReturned);
            return ret;
        }
        else
            bufferSize *= 2;
    }
    return std::wstring();
}

std::wstring loader::GetModuleName(HMODULE hmodule) {
    auto modulePath = GetModulePath(hmodule);
    if (!modulePath.empty()) {
        auto lastSlash = modulePath.find_last_of(L"/\\");
        if (lastSlash != std::wstring::npos)
            modulePath = modulePath.substr(lastSlash + 1);
        return modulePath;
    }
    return std::wstring();
}

std::wstring loader::GetModuleDir(HMODULE hmodule) {
    std::wstring modulePath = GetModulePath(hmodule);
    if (!modulePath.empty()) {
        auto lastSlash = modulePath.find_last_of(L"/\\");
        if (lastSlash != std::wstring::npos) {
            modulePath.resize(lastSlash + 1);
            return modulePath;
        }
    }
    return std::wstring();
}
