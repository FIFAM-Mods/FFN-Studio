#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <string>
#include <vector>

class loader {
public:
    static void InstallPatches();
    static void UninstallPatches();
    static bool LoadLib(std::wstring const &libName, HMODULE &handle);
    static void Load();
    static void Unload();
    static std::wstring GetModulePath(HMODULE hmodule);
    static std::wstring GetModuleName(HMODULE hmodule);
    static std::wstring GetModuleDir(HMODULE hmodule);
};
