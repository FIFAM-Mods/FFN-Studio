#include <Windows.h>
#include <algorithm>
#include "plugin-std.h"
#include "loader.h"

const wchar_t * const PLUGIN_VERSION = L"1.0.0.0";
struct TheDll {
    HMODULE handle;
} dll;

struct d3d9_dll {
    FARPROC D3DPERF_BeginEvent;
    FARPROC D3DPERF_EndEvent;
    FARPROC D3DPERF_GetStatus;
    FARPROC D3DPERF_QueryRepeatFrame;
    FARPROC D3DPERF_SetMarker;
    FARPROC D3DPERF_SetOptions;
    FARPROC D3DPERF_SetRegion;
    FARPROC DebugSetLevel;
    FARPROC DebugSetMute;
    FARPROC Direct3D9EnableMaximizedWindowedModeShim;
    FARPROC Direct3DCreate9;
    FARPROC Direct3DCreate9Ex;
    FARPROC Direct3DShaderValidatorCreate9;
    FARPROC PSGPError;
    FARPROC PSGPSampleTexture;
} d3d9;

__declspec(naked) void _D3DPERF_BeginEvent() { _asm { jmp[d3d9.D3DPERF_BeginEvent] } }
__declspec(naked) void _D3DPERF_EndEvent() { _asm { jmp[d3d9.D3DPERF_EndEvent] } }
__declspec(naked) void _D3DPERF_GetStatus() { _asm { jmp[d3d9.D3DPERF_GetStatus] } }
__declspec(naked) void _D3DPERF_QueryRepeatFrame() { _asm { jmp[d3d9.D3DPERF_QueryRepeatFrame] } }
__declspec(naked) void _D3DPERF_SetMarker() { _asm { jmp[d3d9.D3DPERF_SetMarker] } }
__declspec(naked) void _D3DPERF_SetOptions() { _asm { jmp[d3d9.D3DPERF_SetOptions] } }
__declspec(naked) void _D3DPERF_SetRegion() { _asm { jmp[d3d9.D3DPERF_SetRegion] } }
__declspec(naked) void _DebugSetLevel() { _asm { jmp[d3d9.DebugSetLevel] } }
__declspec(naked) void _DebugSetMute() { _asm { jmp[d3d9.DebugSetMute] } }
__declspec(naked) void _Direct3D9EnableMaximizedWindowedModeShim() { _asm { jmp[d3d9.Direct3D9EnableMaximizedWindowedModeShim] } }
__declspec(naked) void _Direct3DCreate9() { _asm { jmp[d3d9.Direct3DCreate9] } }
__declspec(naked) void _Direct3DCreate9Ex() { _asm { jmp[d3d9.Direct3DCreate9Ex] } }
__declspec(naked) void _Direct3DShaderValidatorCreate9() { _asm { jmp[d3d9.Direct3DShaderValidatorCreate9] } }
__declspec(naked) void _PSGPError() { _asm { jmp[d3d9.PSGPError] } }
__declspec(naked) void _PSGPSampleTexture() { _asm { jmp[d3d9.PSGPSampleTexture] } }

struct version_dll {
    FARPROC GetFileVersionInfoA;
    FARPROC GetFileVersionInfoByHandle;
    FARPROC GetFileVersionInfoExA;
    FARPROC GetFileVersionInfoExW;
    FARPROC GetFileVersionInfoSizeA;
    FARPROC GetFileVersionInfoSizeExA;
    FARPROC GetFileVersionInfoSizeExW;
    FARPROC GetFileVersionInfoSizeW;
    FARPROC GetFileVersionInfoW;
    FARPROC VerFindFileA;
    FARPROC VerFindFileW;
    FARPROC VerInstallFileA;
    FARPROC VerInstallFileW;
    FARPROC VerLanguageNameA;
    FARPROC VerLanguageNameW;
    FARPROC VerQueryValueA;
    FARPROC VerQueryValueW;
} version;

__declspec(naked) void _GetFileVersionInfoA() { _asm { jmp[version.GetFileVersionInfoA] } }
__declspec(naked) void _GetFileVersionInfoByHandle() { _asm { jmp[version.GetFileVersionInfoByHandle] } }
__declspec(naked) void _GetFileVersionInfoExA() { _asm { jmp[version.GetFileVersionInfoExA] } }
__declspec(naked) void _GetFileVersionInfoExW() { _asm { jmp[version.GetFileVersionInfoExW] } }
__declspec(naked) void _GetFileVersionInfoSizeA() { _asm { jmp[version.GetFileVersionInfoSizeA] } }
__declspec(naked) void _GetFileVersionInfoSizeExA() { _asm { jmp[version.GetFileVersionInfoSizeExA] } }
__declspec(naked) void _GetFileVersionInfoSizeExW() { _asm { jmp[version.GetFileVersionInfoSizeExW] } }
__declspec(naked) void _GetFileVersionInfoSizeW() { _asm { jmp[version.GetFileVersionInfoSizeW] } }
__declspec(naked) void _GetFileVersionInfoW() { _asm { jmp[version.GetFileVersionInfoW] } }
__declspec(naked) void _VerFindFileA() { _asm { jmp[version.VerFindFileA] } }
__declspec(naked) void _VerFindFileW() { _asm { jmp[version.VerFindFileW] } }
__declspec(naked) void _VerInstallFileA() { _asm { jmp[version.VerInstallFileA] } }
__declspec(naked) void _VerInstallFileW() { _asm { jmp[version.VerInstallFileW] } }
__declspec(naked) void _VerLanguageNameA() { _asm { jmp[version.VerLanguageNameA] } }
__declspec(naked) void _VerLanguageNameW() { _asm { jmp[version.VerLanguageNameW] } }
__declspec(naked) void _VerQueryValueA() { _asm { jmp[version.VerQueryValueA] } }
__declspec(naked) void _VerQueryValueW() { _asm { jmp[version.VerQueryValueW] } }

struct davhlpr_dll {
    FARPROC DavAddConnection;
    FARPROC DavCheckAndConvertHttpUrlToUncName;
    FARPROC DavDeleteConnection;
    FARPROC DavFlushFile;
    FARPROC DavGetExtendedError;
    FARPROC DavGetHTTPFromUNCPath;
    FARPROC DavGetUNCFromHTTPPath;
    FARPROC DavParseUncServerName;
    FARPROC DavRemoveDummyShareFromFileName;
    FARPROC DavRemoveDummyShareFromFileNameEx;
    FARPROC DavUrlDecodeToNtPath;
    FARPROC DavUrlDecodeUtf8;
    FARPROC DavUrlEncodeNtPath;
} davhlpr;

__declspec(naked) void _DavAddConnection() { _asm { jmp[davhlpr.DavAddConnection] } }
__declspec(naked) void _DavCheckAndConvertHttpUrlToUncName() { _asm { jmp[davhlpr.DavCheckAndConvertHttpUrlToUncName] } }
__declspec(naked) void _DavDeleteConnection() { _asm { jmp[davhlpr.DavDeleteConnection] } }
__declspec(naked) void _DavFlushFile() { _asm { jmp[davhlpr.DavFlushFile] } }
__declspec(naked) void _DavGetExtendedError() { _asm { jmp[davhlpr.DavGetExtendedError] } }
__declspec(naked) void _DavGetHTTPFromUNCPath() { _asm { jmp[davhlpr.DavGetHTTPFromUNCPath] } }
__declspec(naked) void _DavGetUNCFromHTTPPath() { _asm { jmp[davhlpr.DavGetUNCFromHTTPPath] } }
__declspec(naked) void _DavParseUncServerName() { _asm { jmp[davhlpr.DavParseUncServerName] } }
__declspec(naked) void _DavRemoveDummyShareFromFileName() { _asm { jmp[davhlpr.DavRemoveDummyShareFromFileName] } }
__declspec(naked) void _DavRemoveDummyShareFromFileNameEx() { _asm { jmp[davhlpr.DavRemoveDummyShareFromFileNameEx] } }
__declspec(naked) void _DavUrlDecodeToNtPath() { _asm { jmp[davhlpr.DavUrlDecodeToNtPath] } }
__declspec(naked) void _DavUrlDecodeUtf8() { _asm { jmp[davhlpr.DavUrlDecodeUtf8] } }
__declspec(naked) void _DavUrlEncodeNtPath() { _asm { jmp[davhlpr.DavUrlEncodeNtPath] } }

struct msimg32_dll {
    FARPROC AlphaBlend;
    FARPROC DllInitialize;
    FARPROC GradientFill;
    FARPROC TransparentBlt;
    FARPROC vSetDdrawflag;
} msimg32;

__declspec(naked) void _AlphaBlend() { _asm { jmp[msimg32.AlphaBlend] } }
__declspec(naked) void _DllInitialize() { _asm { jmp[msimg32.DllInitialize] } }
__declspec(naked) void _GradientFill() { _asm { jmp[msimg32.GradientFill] } }
__declspec(naked) void _TransparentBlt() { _asm { jmp[msimg32.TransparentBlt] } }
__declspec(naked) void _vSetDdrawflag() { _asm { jmp[msimg32.vSetDdrawflag] } }

struct oledlg_dll {
    FARPROC OleUIAddVerbMenuA;
    FARPROC OleUIAddVerbMenuW;
    FARPROC OleUIBusyA;
    FARPROC OleUIBusyW;
    FARPROC OleUICanConvertOrActivateAs;
    FARPROC OleUIChangeIconA;
    FARPROC OleUIChangeIconW;
    FARPROC OleUIChangeSourceA;
    FARPROC OleUIChangeSourceW;
    FARPROC OleUIConvertA;
    FARPROC OleUIConvertW;
    FARPROC OleUIEditLinksA;
    FARPROC OleUIEditLinksW;
    FARPROC OleUIInsertObjectA;
    FARPROC OleUIInsertObjectW;
    FARPROC OleUIObjectPropertiesA;
    FARPROC OleUIObjectPropertiesW;
    FARPROC OleUIPasteSpecialA;
    FARPROC OleUIPasteSpecialW;
    FARPROC OleUIPromptUserA;
    FARPROC OleUIPromptUserW;
    FARPROC OleUIUpdateLinksA;
    FARPROC OleUIUpdateLinksW;
} oledlg;

__declspec(naked) void _OleUIAddVerbMenuA() { _asm { jmp[oledlg.OleUIAddVerbMenuA] } }
__declspec(naked) void _OleUIAddVerbMenuW() { _asm { jmp[oledlg.OleUIAddVerbMenuW] } }
__declspec(naked) void _OleUIBusyA() { _asm { jmp[oledlg.OleUIBusyA] } }
__declspec(naked) void _OleUIBusyW() { _asm { jmp[oledlg.OleUIBusyW] } }
__declspec(naked) void _OleUICanConvertOrActivateAs() { _asm { jmp[oledlg.OleUICanConvertOrActivateAs] } }
__declspec(naked) void _OleUIChangeIconA() { _asm { jmp[oledlg.OleUIChangeIconA] } }
__declspec(naked) void _OleUIChangeIconW() { _asm { jmp[oledlg.OleUIChangeIconW] } }
__declspec(naked) void _OleUIChangeSourceA() { _asm { jmp[oledlg.OleUIChangeSourceA] } }
__declspec(naked) void _OleUIChangeSourceW() { _asm { jmp[oledlg.OleUIChangeSourceW] } }
__declspec(naked) void _OleUIConvertA() { _asm { jmp[oledlg.OleUIConvertA] } }
__declspec(naked) void _OleUIConvertW() { _asm { jmp[oledlg.OleUIConvertW] } }
__declspec(naked) void _OleUIEditLinksA() { _asm { jmp[oledlg.OleUIEditLinksA] } }
__declspec(naked) void _OleUIEditLinksW() { _asm { jmp[oledlg.OleUIEditLinksW] } }
__declspec(naked) void _OleUIInsertObjectA() { _asm { jmp[oledlg.OleUIInsertObjectA] } }
__declspec(naked) void _OleUIInsertObjectW() { _asm { jmp[oledlg.OleUIInsertObjectW] } }
__declspec(naked) void _OleUIObjectPropertiesA() { _asm { jmp[oledlg.OleUIObjectPropertiesA] } }
__declspec(naked) void _OleUIObjectPropertiesW() { _asm { jmp[oledlg.OleUIObjectPropertiesW] } }
__declspec(naked) void _OleUIPasteSpecialA() { _asm { jmp[oledlg.OleUIPasteSpecialA] } }
__declspec(naked) void _OleUIPasteSpecialW() { _asm { jmp[oledlg.OleUIPasteSpecialW] } }
__declspec(naked) void _OleUIPromptUserA() { _asm { jmp[oledlg.OleUIPromptUserA] } }
__declspec(naked) void _OleUIPromptUserW() { _asm { jmp[oledlg.OleUIPromptUserW] } }
__declspec(naked) void _OleUIUpdateLinksA() { _asm { jmp[oledlg.OleUIUpdateLinksA] } }
__declspec(naked) void _OleUIUpdateLinksW() { _asm { jmp[oledlg.OleUIUpdateLinksW] } }

#undef PlaySound

struct winmm_dll {
    FARPROC CloseDriver;
    FARPROC DefDriverProc;
    FARPROC DriverCallback;
    FARPROC DrvGetModuleHandle;
    FARPROC GetDriverModuleHandle;
    FARPROC NotifyCallbackData;
    FARPROC OpenDriver;
    FARPROC PlaySound;
    FARPROC PlaySoundA;
    FARPROC PlaySoundW;
    FARPROC SendDriverMessage;
    FARPROC WOW32DriverCallback;
    FARPROC WOW32ResolveMultiMediaHandle;
    FARPROC WOWAppExit;
    FARPROC aux32Message;
    FARPROC auxGetDevCapsA;
    FARPROC auxGetDevCapsW;
    FARPROC auxGetNumDevs;
    FARPROC auxGetVolume;
    FARPROC auxOutMessage;
    FARPROC auxSetVolume;
    FARPROC joy32Message;
    FARPROC joyConfigChanged;
    FARPROC joyGetDevCapsA;
    FARPROC joyGetDevCapsW;
    FARPROC joyGetNumDevs;
    FARPROC joyGetPos;
    FARPROC joyGetPosEx;
    FARPROC joyGetThreshold;
    FARPROC joyReleaseCapture;
    FARPROC joySetCapture;
    FARPROC joySetThreshold;
    FARPROC mci32Message;
    FARPROC mciDriverNotify;
    FARPROC mciDriverYield;
    FARPROC mciExecute;
    FARPROC mciFreeCommandResource;
    FARPROC mciGetCreatorTask;
    FARPROC mciGetDeviceIDA;
    FARPROC mciGetDeviceIDFromElementIDA;
    FARPROC mciGetDeviceIDFromElementIDW;
    FARPROC mciGetDeviceIDW;
    FARPROC mciGetDriverData;
    FARPROC mciGetErrorStringA;
    FARPROC mciGetErrorStringW;
    FARPROC mciGetYieldProc;
    FARPROC mciLoadCommandResource;
    FARPROC mciSendCommandA;
    FARPROC mciSendCommandW;
    FARPROC mciSendStringA;
    FARPROC mciSendStringW;
    FARPROC mciSetDriverData;
    FARPROC mciSetYieldProc;
    FARPROC mid32Message;
    FARPROC midiConnect;
    FARPROC midiDisconnect;
    FARPROC midiInAddBuffer;
    FARPROC midiInClose;
    FARPROC midiInGetDevCapsA;
    FARPROC midiInGetDevCapsW;
    FARPROC midiInGetErrorTextA;
    FARPROC midiInGetErrorTextW;
    FARPROC midiInGetID;
    FARPROC midiInGetNumDevs;
    FARPROC midiInMessage;
    FARPROC midiInOpen;
    FARPROC midiInPrepareHeader;
    FARPROC midiInReset;
    FARPROC midiInStart;
    FARPROC midiInStop;
    FARPROC midiInUnprepareHeader;
    FARPROC midiOutCacheDrumPatches;
    FARPROC midiOutCachePatches;
    FARPROC midiOutClose;
    FARPROC midiOutGetDevCapsA;
    FARPROC midiOutGetDevCapsW;
    FARPROC midiOutGetErrorTextA;
    FARPROC midiOutGetErrorTextW;
    FARPROC midiOutGetID;
    FARPROC midiOutGetNumDevs;
    FARPROC midiOutGetVolume;
    FARPROC midiOutLongMsg;
    FARPROC midiOutMessage;
    FARPROC midiOutOpen;
    FARPROC midiOutPrepareHeader;
    FARPROC midiOutReset;
    FARPROC midiOutSetVolume;
    FARPROC midiOutShortMsg;
    FARPROC midiOutUnprepareHeader;
    FARPROC midiStreamClose;
    FARPROC midiStreamOpen;
    FARPROC midiStreamOut;
    FARPROC midiStreamPause;
    FARPROC midiStreamPosition;
    FARPROC midiStreamProperty;
    FARPROC midiStreamRestart;
    FARPROC midiStreamStop;
    FARPROC mixerClose;
    FARPROC mixerGetControlDetailsA;
    FARPROC mixerGetControlDetailsW;
    FARPROC mixerGetDevCapsA;
    FARPROC mixerGetDevCapsW;
    FARPROC mixerGetID;
    FARPROC mixerGetLineControlsA;
    FARPROC mixerGetLineControlsW;
    FARPROC mixerGetLineInfoA;
    FARPROC mixerGetLineInfoW;
    FARPROC mixerGetNumDevs;
    FARPROC mixerMessage;
    FARPROC mixerOpen;
    FARPROC mixerSetControlDetails;
    FARPROC mmDrvInstall;
    FARPROC mmGetCurrentTask;
    FARPROC mmTaskBlock;
    FARPROC mmTaskCreate;
    FARPROC mmTaskSignal;
    FARPROC mmTaskYield;
    FARPROC mmioAdvance;
    FARPROC mmioAscend;
    FARPROC mmioClose;
    FARPROC mmioCreateChunk;
    FARPROC mmioDescend;
    FARPROC mmioFlush;
    FARPROC mmioGetInfo;
    FARPROC mmioInstallIOProcA;
    FARPROC mmioInstallIOProcW;
    FARPROC mmioOpenA;
    FARPROC mmioOpenW;
    FARPROC mmioRead;
    FARPROC mmioRenameA;
    FARPROC mmioRenameW;
    FARPROC mmioSeek;
    FARPROC mmioSendMessage;
    FARPROC mmioSetBuffer;
    FARPROC mmioSetInfo;
    FARPROC mmioStringToFOURCCA;
    FARPROC mmioStringToFOURCCW;
    FARPROC mmioWrite;
    FARPROC mmsystemGetVersion;
    FARPROC mod32Message;
    FARPROC mxd32Message;
    FARPROC sndPlaySoundA;
    FARPROC sndPlaySoundW;
    FARPROC tid32Message;
    FARPROC timeBeginPeriod;
    FARPROC timeEndPeriod;
    FARPROC timeGetDevCaps;
    FARPROC timeGetSystemTime;
    FARPROC timeGetTime;
    FARPROC timeKillEvent;
    FARPROC timeSetEvent;
    FARPROC waveInAddBuffer;
    FARPROC waveInClose;
    FARPROC waveInGetDevCapsA;
    FARPROC waveInGetDevCapsW;
    FARPROC waveInGetErrorTextA;
    FARPROC waveInGetErrorTextW;
    FARPROC waveInGetID;
    FARPROC waveInGetNumDevs;
    FARPROC waveInGetPosition;
    FARPROC waveInMessage;
    FARPROC waveInOpen;
    FARPROC waveInPrepareHeader;
    FARPROC waveInReset;
    FARPROC waveInStart;
    FARPROC waveInStop;
    FARPROC waveInUnprepareHeader;
    FARPROC waveOutBreakLoop;
    FARPROC waveOutClose;
    FARPROC waveOutGetDevCapsA;
    FARPROC waveOutGetDevCapsW;
    FARPROC waveOutGetErrorTextA;
    FARPROC waveOutGetErrorTextW;
    FARPROC waveOutGetID;
    FARPROC waveOutGetNumDevs;
    FARPROC waveOutGetPitch;
    FARPROC waveOutGetPlaybackRate;
    FARPROC waveOutGetPosition;
    FARPROC waveOutGetVolume;
    FARPROC waveOutMessage;
    FARPROC waveOutOpen;
    FARPROC waveOutPause;
    FARPROC waveOutPrepareHeader;
    FARPROC waveOutReset;
    FARPROC waveOutRestart;
    FARPROC waveOutSetPitch;
    FARPROC waveOutSetPlaybackRate;
    FARPROC waveOutSetVolume;
    FARPROC waveOutUnprepareHeader;
    FARPROC waveOutWrite;
    FARPROC wid32Message;
    FARPROC wod32Message;
} winmm;

__declspec(naked) void _CloseDriver() { _asm { jmp[winmm.CloseDriver] } }
__declspec(naked) void _DefDriverProc() { _asm { jmp[winmm.DefDriverProc] } }
__declspec(naked) void _DriverCallback() { _asm { jmp[winmm.DriverCallback] } }
__declspec(naked) void _DrvGetModuleHandle() { _asm { jmp[winmm.DrvGetModuleHandle] } }
__declspec(naked) void _GetDriverModuleHandle() { _asm { jmp[winmm.GetDriverModuleHandle] } }
__declspec(naked) void _NotifyCallbackData() { _asm { jmp[winmm.NotifyCallbackData] } }
__declspec(naked) void _OpenDriver() { _asm { jmp[winmm.OpenDriver] } }
__declspec(naked) void _PlaySound() { _asm { jmp[winmm.PlaySound] } }
__declspec(naked) void _PlaySoundA() { _asm { jmp[winmm.PlaySoundA] } }
__declspec(naked) void _PlaySoundW() { _asm { jmp[winmm.PlaySoundW] } }
__declspec(naked) void _SendDriverMessage() { _asm { jmp[winmm.SendDriverMessage] } }
__declspec(naked) void _WOW32DriverCallback() { _asm { jmp[winmm.WOW32DriverCallback] } }
__declspec(naked) void _WOW32ResolveMultiMediaHandle() { _asm { jmp[winmm.WOW32ResolveMultiMediaHandle] } }
__declspec(naked) void _WOWAppExit() { _asm { jmp[winmm.WOWAppExit] } }
__declspec(naked) void _aux32Message() { _asm { jmp[winmm.aux32Message] } }
__declspec(naked) void _auxGetDevCapsA() { _asm { jmp[winmm.auxGetDevCapsA] } }
__declspec(naked) void _auxGetDevCapsW() { _asm { jmp[winmm.auxGetDevCapsW] } }
__declspec(naked) void _auxGetNumDevs() { _asm { jmp[winmm.auxGetNumDevs] } }
__declspec(naked) void _auxGetVolume() { _asm { jmp[winmm.auxGetVolume] } }
__declspec(naked) void _auxOutMessage() { _asm { jmp[winmm.auxOutMessage] } }
__declspec(naked) void _auxSetVolume() { _asm { jmp[winmm.auxSetVolume] } }
__declspec(naked) void _joy32Message() { _asm { jmp[winmm.joy32Message] } }
__declspec(naked) void _joyConfigChanged() { _asm { jmp[winmm.joyConfigChanged] } }
__declspec(naked) void _joyGetDevCapsA() { _asm { jmp[winmm.joyGetDevCapsA] } }
__declspec(naked) void _joyGetDevCapsW() { _asm { jmp[winmm.joyGetDevCapsW] } }
__declspec(naked) void _joyGetNumDevs() { _asm { jmp[winmm.joyGetNumDevs] } }
__declspec(naked) void _joyGetPos() { _asm { jmp[winmm.joyGetPos] } }
__declspec(naked) void _joyGetPosEx() { _asm { jmp[winmm.joyGetPosEx] } }
__declspec(naked) void _joyGetThreshold() { _asm { jmp[winmm.joyGetThreshold] } }
__declspec(naked) void _joyReleaseCapture() { _asm { jmp[winmm.joyReleaseCapture] } }
__declspec(naked) void _joySetCapture() { _asm { jmp[winmm.joySetCapture] } }
__declspec(naked) void _joySetThreshold() { _asm { jmp[winmm.joySetThreshold] } }
__declspec(naked) void _mci32Message() { _asm { jmp[winmm.mci32Message] } }
__declspec(naked) void _mciDriverNotify() { _asm { jmp[winmm.mciDriverNotify] } }
__declspec(naked) void _mciDriverYield() { _asm { jmp[winmm.mciDriverYield] } }
__declspec(naked) void _mciExecute() { _asm { jmp[winmm.mciExecute] } }
__declspec(naked) void _mciFreeCommandResource() { _asm { jmp[winmm.mciFreeCommandResource] } }
__declspec(naked) void _mciGetCreatorTask() { _asm { jmp[winmm.mciGetCreatorTask] } }
__declspec(naked) void _mciGetDeviceIDA() { _asm { jmp[winmm.mciGetDeviceIDA] } }
__declspec(naked) void _mciGetDeviceIDFromElementIDA() { _asm { jmp[winmm.mciGetDeviceIDFromElementIDA] } }
__declspec(naked) void _mciGetDeviceIDFromElementIDW() { _asm { jmp[winmm.mciGetDeviceIDFromElementIDW] } }
__declspec(naked) void _mciGetDeviceIDW() { _asm { jmp[winmm.mciGetDeviceIDW] } }
__declspec(naked) void _mciGetDriverData() { _asm { jmp[winmm.mciGetDriverData] } }
__declspec(naked) void _mciGetErrorStringA() { _asm { jmp[winmm.mciGetErrorStringA] } }
__declspec(naked) void _mciGetErrorStringW() { _asm { jmp[winmm.mciGetErrorStringW] } }
__declspec(naked) void _mciGetYieldProc() { _asm { jmp[winmm.mciGetYieldProc] } }
__declspec(naked) void _mciLoadCommandResource() { _asm { jmp[winmm.mciLoadCommandResource] } }
__declspec(naked) void _mciSendCommandA() { _asm { jmp[winmm.mciSendCommandA] } }
__declspec(naked) void _mciSendCommandW() { _asm { jmp[winmm.mciSendCommandW] } }
__declspec(naked) void _mciSendStringA() { _asm { jmp[winmm.mciSendStringA] } }
__declspec(naked) void _mciSendStringW() { _asm { jmp[winmm.mciSendStringW] } }
__declspec(naked) void _mciSetDriverData() { _asm { jmp[winmm.mciSetDriverData] } }
__declspec(naked) void _mciSetYieldProc() { _asm { jmp[winmm.mciSetYieldProc] } }
__declspec(naked) void _mid32Message() { _asm { jmp[winmm.mid32Message] } }
__declspec(naked) void _midiConnect() { _asm { jmp[winmm.midiConnect] } }
__declspec(naked) void _midiDisconnect() { _asm { jmp[winmm.midiDisconnect] } }
__declspec(naked) void _midiInAddBuffer() { _asm { jmp[winmm.midiInAddBuffer] } }
__declspec(naked) void _midiInClose() { _asm { jmp[winmm.midiInClose] } }
__declspec(naked) void _midiInGetDevCapsA() { _asm { jmp[winmm.midiInGetDevCapsA] } }
__declspec(naked) void _midiInGetDevCapsW() { _asm { jmp[winmm.midiInGetDevCapsW] } }
__declspec(naked) void _midiInGetErrorTextA() { _asm { jmp[winmm.midiInGetErrorTextA] } }
__declspec(naked) void _midiInGetErrorTextW() { _asm { jmp[winmm.midiInGetErrorTextW] } }
__declspec(naked) void _midiInGetID() { _asm { jmp[winmm.midiInGetID] } }
__declspec(naked) void _midiInGetNumDevs() { _asm { jmp[winmm.midiInGetNumDevs] } }
__declspec(naked) void _midiInMessage() { _asm { jmp[winmm.midiInMessage] } }
__declspec(naked) void _midiInOpen() { _asm { jmp[winmm.midiInOpen] } }
__declspec(naked) void _midiInPrepareHeader() { _asm { jmp[winmm.midiInPrepareHeader] } }
__declspec(naked) void _midiInReset() { _asm { jmp[winmm.midiInReset] } }
__declspec(naked) void _midiInStart() { _asm { jmp[winmm.midiInStart] } }
__declspec(naked) void _midiInStop() { _asm { jmp[winmm.midiInStop] } }
__declspec(naked) void _midiInUnprepareHeader() { _asm { jmp[winmm.midiInUnprepareHeader] } }
__declspec(naked) void _midiOutCacheDrumPatches() { _asm { jmp[winmm.midiOutCacheDrumPatches] } }
__declspec(naked) void _midiOutCachePatches() { _asm { jmp[winmm.midiOutCachePatches] } }
__declspec(naked) void _midiOutClose() { _asm { jmp[winmm.midiOutClose] } }
__declspec(naked) void _midiOutGetDevCapsA() { _asm { jmp[winmm.midiOutGetDevCapsA] } }
__declspec(naked) void _midiOutGetDevCapsW() { _asm { jmp[winmm.midiOutGetDevCapsW] } }
__declspec(naked) void _midiOutGetErrorTextA() { _asm { jmp[winmm.midiOutGetErrorTextA] } }
__declspec(naked) void _midiOutGetErrorTextW() { _asm { jmp[winmm.midiOutGetErrorTextW] } }
__declspec(naked) void _midiOutGetID() { _asm { jmp[winmm.midiOutGetID] } }
__declspec(naked) void _midiOutGetNumDevs() { _asm { jmp[winmm.midiOutGetNumDevs] } }
__declspec(naked) void _midiOutGetVolume() { _asm { jmp[winmm.midiOutGetVolume] } }
__declspec(naked) void _midiOutLongMsg() { _asm { jmp[winmm.midiOutLongMsg] } }
__declspec(naked) void _midiOutMessage() { _asm { jmp[winmm.midiOutMessage] } }
__declspec(naked) void _midiOutOpen() { _asm { jmp[winmm.midiOutOpen] } }
__declspec(naked) void _midiOutPrepareHeader() { _asm { jmp[winmm.midiOutPrepareHeader] } }
__declspec(naked) void _midiOutReset() { _asm { jmp[winmm.midiOutReset] } }
__declspec(naked) void _midiOutSetVolume() { _asm { jmp[winmm.midiOutSetVolume] } }
__declspec(naked) void _midiOutShortMsg() { _asm { jmp[winmm.midiOutShortMsg] } }
__declspec(naked) void _midiOutUnprepareHeader() { _asm { jmp[winmm.midiOutUnprepareHeader] } }
__declspec(naked) void _midiStreamClose() { _asm { jmp[winmm.midiStreamClose] } }
__declspec(naked) void _midiStreamOpen() { _asm { jmp[winmm.midiStreamOpen] } }
__declspec(naked) void _midiStreamOut() { _asm { jmp[winmm.midiStreamOut] } }
__declspec(naked) void _midiStreamPause() { _asm { jmp[winmm.midiStreamPause] } }
__declspec(naked) void _midiStreamPosition() { _asm { jmp[winmm.midiStreamPosition] } }
__declspec(naked) void _midiStreamProperty() { _asm { jmp[winmm.midiStreamProperty] } }
__declspec(naked) void _midiStreamRestart() { _asm { jmp[winmm.midiStreamRestart] } }
__declspec(naked) void _midiStreamStop() { _asm { jmp[winmm.midiStreamStop] } }
__declspec(naked) void _mixerClose() { _asm { jmp[winmm.mixerClose] } }
__declspec(naked) void _mixerGetControlDetailsA() { _asm { jmp[winmm.mixerGetControlDetailsA] } }
__declspec(naked) void _mixerGetControlDetailsW() { _asm { jmp[winmm.mixerGetControlDetailsW] } }
__declspec(naked) void _mixerGetDevCapsA() { _asm { jmp[winmm.mixerGetDevCapsA] } }
__declspec(naked) void _mixerGetDevCapsW() { _asm { jmp[winmm.mixerGetDevCapsW] } }
__declspec(naked) void _mixerGetID() { _asm { jmp[winmm.mixerGetID] } }
__declspec(naked) void _mixerGetLineControlsA() { _asm { jmp[winmm.mixerGetLineControlsA] } }
__declspec(naked) void _mixerGetLineControlsW() { _asm { jmp[winmm.mixerGetLineControlsW] } }
__declspec(naked) void _mixerGetLineInfoA() { _asm { jmp[winmm.mixerGetLineInfoA] } }
__declspec(naked) void _mixerGetLineInfoW() { _asm { jmp[winmm.mixerGetLineInfoW] } }
__declspec(naked) void _mixerGetNumDevs() { _asm { jmp[winmm.mixerGetNumDevs] } }
__declspec(naked) void _mixerMessage() { _asm { jmp[winmm.mixerMessage] } }
__declspec(naked) void _mixerOpen() { _asm { jmp[winmm.mixerOpen] } }
__declspec(naked) void _mixerSetControlDetails() { _asm { jmp[winmm.mixerSetControlDetails] } }
__declspec(naked) void _mmDrvInstall() { _asm { jmp[winmm.mmDrvInstall] } }
__declspec(naked) void _mmGetCurrentTask() { _asm { jmp[winmm.mmGetCurrentTask] } }
__declspec(naked) void _mmTaskBlock() { _asm { jmp[winmm.mmTaskBlock] } }
__declspec(naked) void _mmTaskCreate() { _asm { jmp[winmm.mmTaskCreate] } }
__declspec(naked) void _mmTaskSignal() { _asm { jmp[winmm.mmTaskSignal] } }
__declspec(naked) void _mmTaskYield() { _asm { jmp[winmm.mmTaskYield] } }
__declspec(naked) void _mmioAdvance() { _asm { jmp[winmm.mmioAdvance] } }
__declspec(naked) void _mmioAscend() { _asm { jmp[winmm.mmioAscend] } }
__declspec(naked) void _mmioClose() { _asm { jmp[winmm.mmioClose] } }
__declspec(naked) void _mmioCreateChunk() { _asm { jmp[winmm.mmioCreateChunk] } }
__declspec(naked) void _mmioDescend() { _asm { jmp[winmm.mmioDescend] } }
__declspec(naked) void _mmioFlush() { _asm { jmp[winmm.mmioFlush] } }
__declspec(naked) void _mmioGetInfo() { _asm { jmp[winmm.mmioGetInfo] } }
__declspec(naked) void _mmioInstallIOProcA() { _asm { jmp[winmm.mmioInstallIOProcA] } }
__declspec(naked) void _mmioInstallIOProcW() { _asm { jmp[winmm.mmioInstallIOProcW] } }
__declspec(naked) void _mmioOpenA() { _asm { jmp[winmm.mmioOpenA] } }
__declspec(naked) void _mmioOpenW() { _asm { jmp[winmm.mmioOpenW] } }
__declspec(naked) void _mmioRead() { _asm { jmp[winmm.mmioRead] } }
__declspec(naked) void _mmioRenameA() { _asm { jmp[winmm.mmioRenameA] } }
__declspec(naked) void _mmioRenameW() { _asm { jmp[winmm.mmioRenameW] } }
__declspec(naked) void _mmioSeek() { _asm { jmp[winmm.mmioSeek] } }
__declspec(naked) void _mmioSendMessage() { _asm { jmp[winmm.mmioSendMessage] } }
__declspec(naked) void _mmioSetBuffer() { _asm { jmp[winmm.mmioSetBuffer] } }
__declspec(naked) void _mmioSetInfo() { _asm { jmp[winmm.mmioSetInfo] } }
__declspec(naked) void _mmioStringToFOURCCA() { _asm { jmp[winmm.mmioStringToFOURCCA] } }
__declspec(naked) void _mmioStringToFOURCCW() { _asm { jmp[winmm.mmioStringToFOURCCW] } }
__declspec(naked) void _mmioWrite() { _asm { jmp[winmm.mmioWrite] } }
__declspec(naked) void _mmsystemGetVersion() { _asm { jmp[winmm.mmsystemGetVersion] } }
__declspec(naked) void _mod32Message() { _asm { jmp[winmm.mod32Message] } }
__declspec(naked) void _mxd32Message() { _asm { jmp[winmm.mxd32Message] } }
__declspec(naked) void _sndPlaySoundA() { _asm { jmp[winmm.sndPlaySoundA] } }
__declspec(naked) void _sndPlaySoundW() { _asm { jmp[winmm.sndPlaySoundW] } }
__declspec(naked) void _tid32Message() { _asm { jmp[winmm.tid32Message] } }
__declspec(naked) void _timeBeginPeriod() { _asm { jmp[winmm.timeBeginPeriod] } }
__declspec(naked) void _timeEndPeriod() { _asm { jmp[winmm.timeEndPeriod] } }
__declspec(naked) void _timeGetDevCaps() { _asm { jmp[winmm.timeGetDevCaps] } }
__declspec(naked) void _timeGetSystemTime() { _asm { jmp[winmm.timeGetSystemTime] } }
__declspec(naked) void _timeGetTime() { _asm { jmp[winmm.timeGetTime] } }
__declspec(naked) void _timeKillEvent() { _asm { jmp[winmm.timeKillEvent] } }
__declspec(naked) void _timeSetEvent() { _asm { jmp[winmm.timeSetEvent] } }
__declspec(naked) void _waveInAddBuffer() { _asm { jmp[winmm.waveInAddBuffer] } }
__declspec(naked) void _waveInClose() { _asm { jmp[winmm.waveInClose] } }
__declspec(naked) void _waveInGetDevCapsA() { _asm { jmp[winmm.waveInGetDevCapsA] } }
__declspec(naked) void _waveInGetDevCapsW() { _asm { jmp[winmm.waveInGetDevCapsW] } }
__declspec(naked) void _waveInGetErrorTextA() { _asm { jmp[winmm.waveInGetErrorTextA] } }
__declspec(naked) void _waveInGetErrorTextW() { _asm { jmp[winmm.waveInGetErrorTextW] } }
__declspec(naked) void _waveInGetID() { _asm { jmp[winmm.waveInGetID] } }
__declspec(naked) void _waveInGetNumDevs() { _asm { jmp[winmm.waveInGetNumDevs] } }
__declspec(naked) void _waveInGetPosition() { _asm { jmp[winmm.waveInGetPosition] } }
__declspec(naked) void _waveInMessage() { _asm { jmp[winmm.waveInMessage] } }
__declspec(naked) void _waveInOpen() { _asm { jmp[winmm.waveInOpen] } }
__declspec(naked) void _waveInPrepareHeader() { _asm { jmp[winmm.waveInPrepareHeader] } }
__declspec(naked) void _waveInReset() { _asm { jmp[winmm.waveInReset] } }
__declspec(naked) void _waveInStart() { _asm { jmp[winmm.waveInStart] } }
__declspec(naked) void _waveInStop() { _asm { jmp[winmm.waveInStop] } }
__declspec(naked) void _waveInUnprepareHeader() { _asm { jmp[winmm.waveInUnprepareHeader] } }
__declspec(naked) void _waveOutBreakLoop() { _asm { jmp[winmm.waveOutBreakLoop] } }
__declspec(naked) void _waveOutClose() { _asm { jmp[winmm.waveOutClose] } }
__declspec(naked) void _waveOutGetDevCapsA() { _asm { jmp[winmm.waveOutGetDevCapsA] } }
__declspec(naked) void _waveOutGetDevCapsW() { _asm { jmp[winmm.waveOutGetDevCapsW] } }
__declspec(naked) void _waveOutGetErrorTextA() { _asm { jmp[winmm.waveOutGetErrorTextA] } }
__declspec(naked) void _waveOutGetErrorTextW() { _asm { jmp[winmm.waveOutGetErrorTextW] } }
__declspec(naked) void _waveOutGetID() { _asm { jmp[winmm.waveOutGetID] } }
__declspec(naked) void _waveOutGetNumDevs() { _asm { jmp[winmm.waveOutGetNumDevs] } }
__declspec(naked) void _waveOutGetPitch() { _asm { jmp[winmm.waveOutGetPitch] } }
__declspec(naked) void _waveOutGetPlaybackRate() { _asm { jmp[winmm.waveOutGetPlaybackRate] } }
__declspec(naked) void _waveOutGetPosition() { _asm { jmp[winmm.waveOutGetPosition] } }
__declspec(naked) void _waveOutGetVolume() { _asm { jmp[winmm.waveOutGetVolume] } }
__declspec(naked) void _waveOutMessage() { _asm { jmp[winmm.waveOutMessage] } }
__declspec(naked) void _waveOutOpen() { _asm { jmp[winmm.waveOutOpen] } }
__declspec(naked) void _waveOutPause() { _asm { jmp[winmm.waveOutPause] } }
__declspec(naked) void _waveOutPrepareHeader() { _asm { jmp[winmm.waveOutPrepareHeader] } }
__declspec(naked) void _waveOutReset() { _asm { jmp[winmm.waveOutReset] } }
__declspec(naked) void _waveOutRestart() { _asm { jmp[winmm.waveOutRestart] } }
__declspec(naked) void _waveOutSetPitch() { _asm { jmp[winmm.waveOutSetPitch] } }
__declspec(naked) void _waveOutSetPlaybackRate() { _asm { jmp[winmm.waveOutSetPlaybackRate] } }
__declspec(naked) void _waveOutSetVolume() { _asm { jmp[winmm.waveOutSetVolume] } }
__declspec(naked) void _waveOutUnprepareHeader() { _asm { jmp[winmm.waveOutUnprepareHeader] } }
__declspec(naked) void _waveOutWrite() { _asm { jmp[winmm.waveOutWrite] } }
__declspec(naked) void _wid32Message() { _asm { jmp[winmm.wid32Message] } }
__declspec(naked) void _wod32Message() { _asm { jmp[winmm.wod32Message] } }

struct msvfw32_dll {
    FARPROC DrawDibBegin;
    FARPROC DrawDibChangePalette;
    FARPROC DrawDibClose;
    FARPROC DrawDibDraw;
    FARPROC DrawDibEnd;
    FARPROC DrawDibGetBuffer;
    FARPROC DrawDibGetPalette;
    FARPROC DrawDibOpen;
    FARPROC DrawDibProfileDisplay;
    FARPROC DrawDibRealize;
    FARPROC DrawDibSetPalette;
    FARPROC DrawDibStart;
    FARPROC DrawDibStop;
    FARPROC DrawDibTime;
    FARPROC GetOpenFileNamePreview;
    FARPROC GetOpenFileNamePreviewA;
    FARPROC GetOpenFileNamePreviewW;
    FARPROC GetSaveFileNamePreviewA;
    FARPROC GetSaveFileNamePreviewW;
    FARPROC ICClose;
    FARPROC ICCompress;
    FARPROC ICCompressorChoose;
    FARPROC ICCompressorFree;
    FARPROC ICDecompress;
    FARPROC ICDraw;
    FARPROC ICDrawBegin;
    FARPROC ICGetDisplayFormat;
    FARPROC ICGetInfo;
    FARPROC ICImageCompress;
    FARPROC ICImageDecompress;
    FARPROC ICInfo;
    FARPROC ICInstall;
    FARPROC ICLocate;
    FARPROC ICMThunk32;
    FARPROC ICOpen;
    FARPROC ICOpenFunction;
    FARPROC ICRemove;
    FARPROC ICSendMessage;
    FARPROC ICSeqCompressFrame;
    FARPROC ICSeqCompressFrameEnd;
    FARPROC ICSeqCompressFrameStart;
    FARPROC MCIWndCreate;
    FARPROC MCIWndCreateA;
    FARPROC MCIWndCreateW;
    FARPROC MCIWndRegisterClass;
    FARPROC StretchDIB;
    FARPROC VideoForWindowsVersion;
} msvfw32;

__declspec(naked) void _DrawDibBegin() { _asm { jmp[msvfw32.DrawDibBegin] } }
__declspec(naked) void _DrawDibChangePalette() { _asm { jmp[msvfw32.DrawDibChangePalette] } }
__declspec(naked) void _DrawDibClose() { _asm { jmp[msvfw32.DrawDibClose] } }
__declspec(naked) void _DrawDibDraw() { _asm { jmp[msvfw32.DrawDibDraw] } }
__declspec(naked) void _DrawDibEnd() { _asm { jmp[msvfw32.DrawDibEnd] } }
__declspec(naked) void _DrawDibGetBuffer() { _asm { jmp[msvfw32.DrawDibGetBuffer] } }
__declspec(naked) void _DrawDibGetPalette() { _asm { jmp[msvfw32.DrawDibGetPalette] } }
__declspec(naked) void _DrawDibOpen() { _asm { jmp[msvfw32.DrawDibOpen] } }
__declspec(naked) void _DrawDibProfileDisplay() { _asm { jmp[msvfw32.DrawDibProfileDisplay] } }
__declspec(naked) void _DrawDibRealize() { _asm { jmp[msvfw32.DrawDibRealize] } }
__declspec(naked) void _DrawDibSetPalette() { _asm { jmp[msvfw32.DrawDibSetPalette] } }
__declspec(naked) void _DrawDibStart() { _asm { jmp[msvfw32.DrawDibStart] } }
__declspec(naked) void _DrawDibStop() { _asm { jmp[msvfw32.DrawDibStop] } }
__declspec(naked) void _DrawDibTime() { _asm { jmp[msvfw32.DrawDibTime] } }
__declspec(naked) void _GetOpenFileNamePreview() { _asm { jmp[msvfw32.GetOpenFileNamePreview] } }
__declspec(naked) void _GetOpenFileNamePreviewA() { _asm { jmp[msvfw32.GetOpenFileNamePreviewA] } }
__declspec(naked) void _GetOpenFileNamePreviewW() { _asm { jmp[msvfw32.GetOpenFileNamePreviewW] } }
__declspec(naked) void _GetSaveFileNamePreviewA() { _asm { jmp[msvfw32.GetSaveFileNamePreviewA] } }
__declspec(naked) void _GetSaveFileNamePreviewW() { _asm { jmp[msvfw32.GetSaveFileNamePreviewW] } }
__declspec(naked) void _ICClose() { _asm { jmp[msvfw32.ICClose] } }
__declspec(naked) void _ICCompress() { _asm { jmp[msvfw32.ICCompress] } }
__declspec(naked) void _ICCompressorChoose() { _asm { jmp[msvfw32.ICCompressorChoose] } }
__declspec(naked) void _ICCompressorFree() { _asm { jmp[msvfw32.ICCompressorFree] } }
__declspec(naked) void _ICDecompress() { _asm { jmp[msvfw32.ICDecompress] } }
__declspec(naked) void _ICDraw() { _asm { jmp[msvfw32.ICDraw] } }
__declspec(naked) void _ICDrawBegin() { _asm { jmp[msvfw32.ICDrawBegin] } }
__declspec(naked) void _ICGetDisplayFormat() { _asm { jmp[msvfw32.ICGetDisplayFormat] } }
__declspec(naked) void _ICGetInfo() { _asm { jmp[msvfw32.ICGetInfo] } }
__declspec(naked) void _ICImageCompress() { _asm { jmp[msvfw32.ICImageCompress] } }
__declspec(naked) void _ICImageDecompress() { _asm { jmp[msvfw32.ICImageDecompress] } }
__declspec(naked) void _ICInfo() { _asm { jmp[msvfw32.ICInfo] } }
__declspec(naked) void _ICInstall() { _asm { jmp[msvfw32.ICInstall] } }
__declspec(naked) void _ICLocate() { _asm { jmp[msvfw32.ICLocate] } }
__declspec(naked) void _ICMThunk32() { _asm { jmp[msvfw32.ICMThunk32] } }
__declspec(naked) void _ICOpen() { _asm { jmp[msvfw32.ICOpen] } }
__declspec(naked) void _ICOpenFunction() { _asm { jmp[msvfw32.ICOpenFunction] } }
__declspec(naked) void _ICRemove() { _asm { jmp[msvfw32.ICRemove] } }
__declspec(naked) void _ICSendMessage() { _asm { jmp[msvfw32.ICSendMessage] } }
__declspec(naked) void _ICSeqCompressFrame() { _asm { jmp[msvfw32.ICSeqCompressFrame] } }
__declspec(naked) void _ICSeqCompressFrameEnd() { _asm { jmp[msvfw32.ICSeqCompressFrameEnd] } }
__declspec(naked) void _ICSeqCompressFrameStart() { _asm { jmp[msvfw32.ICSeqCompressFrameStart] } }
__declspec(naked) void _MCIWndCreate() { _asm { jmp[msvfw32.MCIWndCreate] } }
__declspec(naked) void _MCIWndCreateA() { _asm { jmp[msvfw32.MCIWndCreateA] } }
__declspec(naked) void _MCIWndCreateW() { _asm { jmp[msvfw32.MCIWndCreateW] } }
__declspec(naked) void _MCIWndRegisterClass() { _asm { jmp[msvfw32.MCIWndRegisterClass] } }
__declspec(naked) void _StretchDIB() { _asm { jmp[msvfw32.StretchDIB] } }
__declspec(naked) void _VideoForWindowsVersion() { _asm { jmp[msvfw32.VideoForWindowsVersion] } }

struct wsock32_dll {
    FARPROC AcceptEx;
    FARPROC EnumProtocolsA;
    FARPROC EnumProtocolsW;
    FARPROC GetAcceptExSockaddrs;
    FARPROC GetAddressByNameA;
    FARPROC GetAddressByNameW;
    FARPROC GetNameByTypeA;
    FARPROC GetNameByTypeW;
    FARPROC GetServiceA;
    FARPROC GetServiceW;
    FARPROC GetTypeByNameA;
    FARPROC GetTypeByNameW;
    FARPROC MigrateWinsockConfiguration;
    FARPROC NPLoadNameSpaces;
    FARPROC SetServiceA;
    FARPROC SetServiceW;
    FARPROC TransmitFile;
    FARPROC WEP;
    FARPROC WSAAsyncGetHostByAddr;
    FARPROC WSAAsyncGetHostByName;
    FARPROC WSAAsyncGetProtoByName;
    FARPROC WSAAsyncGetProtoByNumber;
    FARPROC WSAAsyncGetServByName;
    FARPROC WSAAsyncGetServByPort;
    FARPROC WSAAsyncSelect;
    FARPROC WSACancelAsyncRequest;
    FARPROC WSACancelBlockingCall;
    FARPROC WSACleanup;
    FARPROC WSAGetLastError;
    FARPROC WSAIsBlocking;
    FARPROC WSARecvEx;
    FARPROC WSASetBlockingHook;
    FARPROC WSASetLastError;
    FARPROC WSAStartup;
    FARPROC WSAUnhookBlockingHook;
    FARPROC WSApSetPostRoutine;
    FARPROC __WSAFDIsSet;
    FARPROC accept;
    FARPROC bind;
    FARPROC closesocket;
    FARPROC connect;
    FARPROC dn_expand;
    FARPROC gethostbyaddr;
    FARPROC gethostbyname;
    FARPROC gethostname;
    FARPROC getnetbyname;
    FARPROC getpeername;
    FARPROC getprotobyname;
    FARPROC getprotobynumber;
    FARPROC getservbyname;
    FARPROC getservbyport;
    FARPROC getsockname;
    FARPROC getsockopt;
    FARPROC htonl;
    FARPROC htons;
    FARPROC inet_addr;
    FARPROC inet_network;
    FARPROC inet_ntoa;
    FARPROC ioctlsocket;
    FARPROC listen;
    FARPROC ntohl;
    FARPROC ntohs;
    FARPROC rcmd;
    FARPROC recv;
    FARPROC recvfrom;
    FARPROC rexec;
    FARPROC rresvport;
    FARPROC s_perror;
    FARPROC select;
    FARPROC send;
    FARPROC sendto;
    FARPROC sethostname;
    FARPROC setsockopt;
    FARPROC shutdown;
    FARPROC socket;
} wsock32;

__declspec(naked) void _AcceptEx() { _asm { jmp[wsock32.AcceptEx] } }
__declspec(naked) void _EnumProtocolsA() { _asm { jmp[wsock32.EnumProtocolsA] } }
__declspec(naked) void _EnumProtocolsW() { _asm { jmp[wsock32.EnumProtocolsW] } }
__declspec(naked) void _GetAcceptExSockaddrs() { _asm { jmp[wsock32.GetAcceptExSockaddrs] } }
__declspec(naked) void _GetAddressByNameA() { _asm { jmp[wsock32.GetAddressByNameA] } }
__declspec(naked) void _GetAddressByNameW() { _asm { jmp[wsock32.GetAddressByNameW] } }
__declspec(naked) void _GetNameByTypeA() { _asm { jmp[wsock32.GetNameByTypeA] } }
__declspec(naked) void _GetNameByTypeW() { _asm { jmp[wsock32.GetNameByTypeW] } }
__declspec(naked) void _GetServiceA() { _asm { jmp[wsock32.GetServiceA] } }
__declspec(naked) void _GetServiceW() { _asm { jmp[wsock32.GetServiceW] } }
__declspec(naked) void _GetTypeByNameA() { _asm { jmp[wsock32.GetTypeByNameA] } }
__declspec(naked) void _GetTypeByNameW() { _asm { jmp[wsock32.GetTypeByNameW] } }
__declspec(naked) void _MigrateWinsockConfiguration() { _asm { jmp[wsock32.MigrateWinsockConfiguration] } }
__declspec(naked) void _NPLoadNameSpaces() { _asm { jmp[wsock32.NPLoadNameSpaces] } }
__declspec(naked) void _SetServiceA() { _asm { jmp[wsock32.SetServiceA] } }
__declspec(naked) void _SetServiceW() { _asm { jmp[wsock32.SetServiceW] } }
__declspec(naked) void _TransmitFile() { _asm { jmp[wsock32.TransmitFile] } }
__declspec(naked) void _WEP() { _asm { jmp[wsock32.WEP] } }
__declspec(naked) void _WSAAsyncGetHostByAddr() { _asm { jmp[wsock32.WSAAsyncGetHostByAddr] } }
__declspec(naked) void _WSAAsyncGetHostByName() { _asm { jmp[wsock32.WSAAsyncGetHostByName] } }
__declspec(naked) void _WSAAsyncGetProtoByName() { _asm { jmp[wsock32.WSAAsyncGetProtoByName] } }
__declspec(naked) void _WSAAsyncGetProtoByNumber() { _asm { jmp[wsock32.WSAAsyncGetProtoByNumber] } }
__declspec(naked) void _WSAAsyncGetServByName() { _asm { jmp[wsock32.WSAAsyncGetServByName] } }
__declspec(naked) void _WSAAsyncGetServByPort() { _asm { jmp[wsock32.WSAAsyncGetServByPort] } }
__declspec(naked) void _WSAAsyncSelect() { _asm { jmp[wsock32.WSAAsyncSelect] } }
__declspec(naked) void _WSACancelAsyncRequest() { _asm { jmp[wsock32.WSACancelAsyncRequest] } }
__declspec(naked) void _WSACancelBlockingCall() { _asm { jmp[wsock32.WSACancelBlockingCall] } }
__declspec(naked) void _WSACleanup() { _asm { jmp[wsock32.WSACleanup] } }
__declspec(naked) void _WSAGetLastError() { _asm { jmp[wsock32.WSAGetLastError] } }
__declspec(naked) void _WSAIsBlocking() { _asm { jmp[wsock32.WSAIsBlocking] } }
__declspec(naked) void _WSARecvEx() { _asm { jmp[wsock32.WSARecvEx] } }
__declspec(naked) void _WSASetBlockingHook() { _asm { jmp[wsock32.WSASetBlockingHook] } }
__declspec(naked) void _WSASetLastError() { _asm { jmp[wsock32.WSASetLastError] } }
__declspec(naked) void _WSAStartup() { _asm { jmp[wsock32.WSAStartup] } }
__declspec(naked) void _WSAUnhookBlockingHook() { _asm { jmp[wsock32.WSAUnhookBlockingHook] } }
__declspec(naked) void _WSApSetPostRoutine() { _asm { jmp[wsock32.WSApSetPostRoutine] } }
__declspec(naked) void ___WSAFDIsSet() { _asm { jmp[wsock32.__WSAFDIsSet] } }
__declspec(naked) void _accept() { _asm { jmp[wsock32.accept] } }
__declspec(naked) void _bind() { _asm { jmp[wsock32.bind] } }
__declspec(naked) void _closesocket() { _asm { jmp[wsock32.closesocket] } }
__declspec(naked) void _connect() { _asm { jmp[wsock32.connect] } }
__declspec(naked) void _dn_expand() { _asm { jmp[wsock32.dn_expand] } }
__declspec(naked) void _gethostbyaddr() { _asm { jmp[wsock32.gethostbyaddr] } }
__declspec(naked) void _gethostbyname() { _asm { jmp[wsock32.gethostbyname] } }
__declspec(naked) void _gethostname() { _asm { jmp[wsock32.gethostname] } }
__declspec(naked) void _getnetbyname() { _asm { jmp[wsock32.getnetbyname] } }
__declspec(naked) void _getpeername() { _asm { jmp[wsock32.getpeername] } }
__declspec(naked) void _getprotobyname() { _asm { jmp[wsock32.getprotobyname] } }
__declspec(naked) void _getprotobynumber() { _asm { jmp[wsock32.getprotobynumber] } }
__declspec(naked) void _getservbyname() { _asm { jmp[wsock32.getservbyname] } }
__declspec(naked) void _getservbyport() { _asm { jmp[wsock32.getservbyport] } }
__declspec(naked) void _getsockname() { _asm { jmp[wsock32.getsockname] } }
__declspec(naked) void _getsockopt() { _asm { jmp[wsock32.getsockopt] } }
__declspec(naked) void _htonl() { _asm { jmp[wsock32.htonl] } }
__declspec(naked) void _htons() { _asm { jmp[wsock32.htons] } }
__declspec(naked) void _inet_addr() { _asm { jmp[wsock32.inet_addr] } }
__declspec(naked) void _inet_network() { _asm { jmp[wsock32.inet_network] } }
__declspec(naked) void _inet_ntoa() { _asm { jmp[wsock32.inet_ntoa] } }
__declspec(naked) void _ioctlsocket() { _asm { jmp[wsock32.ioctlsocket] } }
__declspec(naked) void _listen() { _asm { jmp[wsock32.listen] } }
__declspec(naked) void _ntohl() { _asm { jmp[wsock32.ntohl] } }
__declspec(naked) void _ntohs() { _asm { jmp[wsock32.ntohs] } }
__declspec(naked) void _rcmd() { _asm { jmp[wsock32.rcmd] } }
__declspec(naked) void _recv() { _asm { jmp[wsock32.recv] } }
__declspec(naked) void _recvfrom() { _asm { jmp[wsock32.recvfrom] } }
__declspec(naked) void _rexec() { _asm { jmp[wsock32.rexec] } }
__declspec(naked) void _rresvport() { _asm { jmp[wsock32.rresvport] } }
__declspec(naked) void _s_perror() { _asm { jmp[wsock32.s_perror] } }
__declspec(naked) void _select() { _asm { jmp[wsock32.select] } }
__declspec(naked) void _send() { _asm { jmp[wsock32.send] } }
__declspec(naked) void _sendto() { _asm { jmp[wsock32.sendto] } }
__declspec(naked) void _sethostname() { _asm { jmp[wsock32.sethostname] } }
__declspec(naked) void _setsockopt() { _asm { jmp[wsock32.setsockopt] } }
__declspec(naked) void _shutdown() { _asm { jmp[wsock32.shutdown] } }
__declspec(naked) void _socket() { _asm { jmp[wsock32.socket] } }

struct winspool_drv {
    FARPROC ADVANCEDSETUPDIALOG;
    FARPROC AbortPrinter;
    FARPROC AddFormA;
    FARPROC AddFormW;
    FARPROC AddJobA;
    FARPROC AddJobW;
    FARPROC AddMonitorA;
    FARPROC AddMonitorW;
    FARPROC AddPortA;
    FARPROC AddPortExA;
    FARPROC AddPortExW;
    FARPROC AddPortW;
    FARPROC AddPrintProcessorA;
    FARPROC AddPrintProcessorW;
    FARPROC AddPrintProvidorA;
    FARPROC AddPrintProvidorW;
    FARPROC AddPrinterA;
    FARPROC AddPrinterConnection2A;
    FARPROC AddPrinterConnection2W;
    FARPROC AddPrinterConnectionA;
    FARPROC AddPrinterConnectionW;
    FARPROC AddPrinterDriverA;
    FARPROC AddPrinterDriverExA;
    FARPROC AddPrinterDriverExW;
    FARPROC AddPrinterDriverW;
    FARPROC AddPrinterW;
    FARPROC AdvancedDocumentPropertiesA;
    FARPROC AdvancedDocumentPropertiesW;
    FARPROC AdvancedSetupDialog;
    FARPROC ClosePrinter;
    FARPROC CloseSpoolFileHandle;
    FARPROC CommitSpoolData;
    FARPROC ConfigurePortA;
    FARPROC ConfigurePortW;
    FARPROC ConnectToPrinterDlg;
    FARPROC ConvertAnsiDevModeToUnicodeDevmode;
    FARPROC ConvertUnicodeDevModeToAnsiDevmode;
    FARPROC CorePrinterDriverInstalledA;
    FARPROC CorePrinterDriverInstalledW;
    FARPROC CreatePrintAsyncNotifyChannel;
    FARPROC CreatePrinterIC;
    FARPROC DEVICECAPABILITIES;
    FARPROC DEVICEMODE;
    FARPROC DeleteFormA;
    FARPROC DeleteFormW;
    FARPROC DeleteJobNamedProperty;
    FARPROC DeleteMonitorA;
    FARPROC DeleteMonitorW;
    FARPROC DeletePortA;
    FARPROC DeletePortW;
    FARPROC DeletePrintProcessorA;
    FARPROC DeletePrintProcessorW;
    FARPROC DeletePrintProvidorA;
    FARPROC DeletePrintProvidorW;
    FARPROC DeletePrinter;
    FARPROC DeletePrinterConnectionA;
    FARPROC DeletePrinterConnectionW;
    FARPROC DeletePrinterDataA;
    FARPROC DeletePrinterDataExA;
    FARPROC DeletePrinterDataExW;
    FARPROC DeletePrinterDataW;
    FARPROC DeletePrinterDriverA;
    FARPROC DeletePrinterDriverExA;
    FARPROC DeletePrinterDriverExW;
    FARPROC DeletePrinterDriverPackageA;
    FARPROC DeletePrinterDriverPackageW;
    FARPROC DeletePrinterDriverW;
    FARPROC DeletePrinterIC;
    FARPROC DeletePrinterKeyA;
    FARPROC DeletePrinterKeyW;
    FARPROC DevQueryPrint;
    FARPROC DevQueryPrintEx;
#undef DeviceCapabilities
    FARPROC DeviceCapabilities;
    FARPROC DeviceCapabilitiesA;
    FARPROC DeviceCapabilitiesW;
    FARPROC DeviceMode;
    FARPROC DevicePropertySheets;
    FARPROC DocumentEvent;
    FARPROC DocumentPropertiesA;
    FARPROC DocumentPropertiesW;
    FARPROC DocumentPropertySheets;
    FARPROC EXTDEVICEMODE;
    FARPROC EndDocPrinter;
    FARPROC EndPagePrinter;
    FARPROC EnumFormsA;
    FARPROC EnumFormsW;
    FARPROC EnumJobNamedProperties;
    FARPROC EnumJobsA;
    FARPROC EnumJobsW;
    FARPROC EnumMonitorsA;
    FARPROC EnumMonitorsW;
    FARPROC EnumPortsA;
    FARPROC EnumPortsW;
    FARPROC EnumPrintProcessorDatatypesA;
    FARPROC EnumPrintProcessorDatatypesW;
    FARPROC EnumPrintProcessorsA;
    FARPROC EnumPrintProcessorsW;
    FARPROC EnumPrinterDataA;
    FARPROC EnumPrinterDataExA;
    FARPROC EnumPrinterDataExW;
    FARPROC EnumPrinterDataW;
    FARPROC EnumPrinterDriversA;
    FARPROC EnumPrinterDriversW;
    FARPROC EnumPrinterKeyA;
    FARPROC EnumPrinterKeyW;
    FARPROC EnumPrintersA;
    FARPROC EnumPrintersW;
    FARPROC ExtDeviceMode;
    FARPROC FindClosePrinterChangeNotification;
    FARPROC FindFirstPrinterChangeNotification;
    FARPROC FindNextPrinterChangeNotification;
    FARPROC FlushPrinter;
    FARPROC FreePrintNamedPropertyArray;
    FARPROC FreePrintPropertyValue;
    FARPROC FreePrinterNotifyInfo;
    FARPROC GetCorePrinterDriversA;
    FARPROC GetCorePrinterDriversW;
    FARPROC GetDefaultPrinterA;
    FARPROC GetDefaultPrinterW;
    FARPROC GetFormA;
    FARPROC GetFormW;
    FARPROC GetJobA;
    FARPROC GetJobNamedPropertyValue;
    FARPROC GetJobW;
    FARPROC GetPrintExecutionData;
    FARPROC GetPrintOutputInfo;
    FARPROC GetPrintProcessorDirectoryA;
    FARPROC GetPrintProcessorDirectoryW;
    FARPROC GetPrinterA;
    FARPROC GetPrinterDataA;
    FARPROC GetPrinterDataExA;
    FARPROC GetPrinterDataExW;
    FARPROC GetPrinterDataW;
    FARPROC GetPrinterDriver2A;
    FARPROC GetPrinterDriver2W;
    FARPROC GetPrinterDriverA;
    FARPROC GetPrinterDriverDirectoryA;
    FARPROC GetPrinterDriverDirectoryW;
    FARPROC GetPrinterDriverPackagePathA;
    FARPROC GetPrinterDriverPackagePathW;
    FARPROC GetPrinterDriverW;
    FARPROC GetPrinterW;
    FARPROC GetSpoolFileHandle;
    FARPROC InstallPrinterDriverFromPackageA;
    FARPROC InstallPrinterDriverFromPackageW;
    FARPROC IsValidDevmodeA;
    FARPROC IsValidDevmodeW;
    FARPROC OpenPrinter2A;
    FARPROC OpenPrinter2W;
    FARPROC OpenPrinterA;
    FARPROC OpenPrinterW;
    FARPROC PerfClose;
    FARPROC PerfCollect;
    FARPROC PerfOpen;
    FARPROC PlayGdiScriptOnPrinterIC;
    FARPROC PrinterMessageBoxA;
    FARPROC PrinterMessageBoxW;
    FARPROC PrinterProperties;
    FARPROC QueryColorProfile;
    FARPROC QueryRemoteFonts;
    FARPROC QuerySpoolMode;
    FARPROC ReadPrinter;
    FARPROC RegisterForPrintAsyncNotifications;
    FARPROC ReportJobProcessingProgress;
    FARPROC ResetPrinterA;
    FARPROC ResetPrinterW;
    FARPROC ScheduleJob;
    FARPROC SeekPrinter;
    FARPROC SetDefaultPrinterA;
    FARPROC SetDefaultPrinterW;
    FARPROC SetFormA;
    FARPROC SetFormW;
    FARPROC SetJobA;
    FARPROC SetJobNamedProperty;
    FARPROC SetJobW;
    FARPROC SetPortA;
    FARPROC SetPortW;
    FARPROC SetPrinterA;
    FARPROC SetPrinterDataA;
    FARPROC SetPrinterDataExA;
    FARPROC SetPrinterDataExW;
    FARPROC SetPrinterDataW;
    FARPROC SetPrinterW;
    FARPROC SplDriverUnloadComplete;
    FARPROC SpoolerDevQueryPrintW;
    FARPROC SpoolerPrinterEvent;
    FARPROC StartDocDlgA;
    FARPROC StartDocDlgW;
    FARPROC StartDocPrinterA;
    FARPROC StartDocPrinterW;
    FARPROC StartPagePrinter;
    FARPROC UnRegisterForPrintAsyncNotifications;
    FARPROC UploadPrinterDriverPackageA;
    FARPROC UploadPrinterDriverPackageW;
    FARPROC WaitForPrinterChange;
    FARPROC WritePrinter;
    FARPROC XcvDataW;
} winspool;

__declspec(naked) void _ADVANCEDSETUPDIALOG() { _asm { jmp[winspool.ADVANCEDSETUPDIALOG] } }
__declspec(naked) void _AbortPrinter() { _asm { jmp[winspool.AbortPrinter] } }
__declspec(naked) void _AddFormA() { _asm { jmp[winspool.AddFormA] } }
__declspec(naked) void _AddFormW() { _asm { jmp[winspool.AddFormW] } }
__declspec(naked) void _AddJobA() { _asm { jmp[winspool.AddJobA] } }
__declspec(naked) void _AddJobW() { _asm { jmp[winspool.AddJobW] } }
__declspec(naked) void _AddMonitorA() { _asm { jmp[winspool.AddMonitorA] } }
__declspec(naked) void _AddMonitorW() { _asm { jmp[winspool.AddMonitorW] } }
__declspec(naked) void _AddPortA() { _asm { jmp[winspool.AddPortA] } }
__declspec(naked) void _AddPortExA() { _asm { jmp[winspool.AddPortExA] } }
__declspec(naked) void _AddPortExW() { _asm { jmp[winspool.AddPortExW] } }
__declspec(naked) void _AddPortW() { _asm { jmp[winspool.AddPortW] } }
__declspec(naked) void _AddPrintProcessorA() { _asm { jmp[winspool.AddPrintProcessorA] } }
__declspec(naked) void _AddPrintProcessorW() { _asm { jmp[winspool.AddPrintProcessorW] } }
__declspec(naked) void _AddPrintProvidorA() { _asm { jmp[winspool.AddPrintProvidorA] } }
__declspec(naked) void _AddPrintProvidorW() { _asm { jmp[winspool.AddPrintProvidorW] } }
__declspec(naked) void _AddPrinterA() { _asm { jmp[winspool.AddPrinterA] } }
__declspec(naked) void _AddPrinterConnection2A() { _asm { jmp[winspool.AddPrinterConnection2A] } }
__declspec(naked) void _AddPrinterConnection2W() { _asm { jmp[winspool.AddPrinterConnection2W] } }
__declspec(naked) void _AddPrinterConnectionA() { _asm { jmp[winspool.AddPrinterConnectionA] } }
__declspec(naked) void _AddPrinterConnectionW() { _asm { jmp[winspool.AddPrinterConnectionW] } }
__declspec(naked) void _AddPrinterDriverA() { _asm { jmp[winspool.AddPrinterDriverA] } }
__declspec(naked) void _AddPrinterDriverExA() { _asm { jmp[winspool.AddPrinterDriverExA] } }
__declspec(naked) void _AddPrinterDriverExW() { _asm { jmp[winspool.AddPrinterDriverExW] } }
__declspec(naked) void _AddPrinterDriverW() { _asm { jmp[winspool.AddPrinterDriverW] } }
__declspec(naked) void _AddPrinterW() { _asm { jmp[winspool.AddPrinterW] } }
__declspec(naked) void _AdvancedDocumentPropertiesA() { _asm { jmp[winspool.AdvancedDocumentPropertiesA] } }
__declspec(naked) void _AdvancedDocumentPropertiesW() { _asm { jmp[winspool.AdvancedDocumentPropertiesW] } }
__declspec(naked) void _AdvancedSetupDialog() { _asm { jmp[winspool.AdvancedSetupDialog] } }
__declspec(naked) void _ClosePrinter() { _asm { jmp[winspool.ClosePrinter] } }
__declspec(naked) void _CloseSpoolFileHandle() { _asm { jmp[winspool.CloseSpoolFileHandle] } }
__declspec(naked) void _CommitSpoolData() { _asm { jmp[winspool.CommitSpoolData] } }
__declspec(naked) void _ConfigurePortA() { _asm { jmp[winspool.ConfigurePortA] } }
__declspec(naked) void _ConfigurePortW() { _asm { jmp[winspool.ConfigurePortW] } }
__declspec(naked) void _ConnectToPrinterDlg() { _asm { jmp[winspool.ConnectToPrinterDlg] } }
__declspec(naked) void _ConvertAnsiDevModeToUnicodeDevmode() { _asm { jmp[winspool.ConvertAnsiDevModeToUnicodeDevmode] } }
__declspec(naked) void _ConvertUnicodeDevModeToAnsiDevmode() { _asm { jmp[winspool.ConvertUnicodeDevModeToAnsiDevmode] } }
__declspec(naked) void _CorePrinterDriverInstalledA() { _asm { jmp[winspool.CorePrinterDriverInstalledA] } }
__declspec(naked) void _CorePrinterDriverInstalledW() { _asm { jmp[winspool.CorePrinterDriverInstalledW] } }
__declspec(naked) void _CreatePrintAsyncNotifyChannel() { _asm { jmp[winspool.CreatePrintAsyncNotifyChannel] } }
__declspec(naked) void _CreatePrinterIC() { _asm { jmp[winspool.CreatePrinterIC] } }
__declspec(naked) void _DEVICECAPABILITIES() { _asm { jmp[winspool.DEVICECAPABILITIES] } }
__declspec(naked) void _DEVICEMODE() { _asm { jmp[winspool.DEVICEMODE] } }
__declspec(naked) void _DeleteFormA() { _asm { jmp[winspool.DeleteFormA] } }
__declspec(naked) void _DeleteFormW() { _asm { jmp[winspool.DeleteFormW] } }
__declspec(naked) void _DeleteJobNamedProperty() { _asm { jmp[winspool.DeleteJobNamedProperty] } }
__declspec(naked) void _DeleteMonitorA() { _asm { jmp[winspool.DeleteMonitorA] } }
__declspec(naked) void _DeleteMonitorW() { _asm { jmp[winspool.DeleteMonitorW] } }
__declspec(naked) void _DeletePortA() { _asm { jmp[winspool.DeletePortA] } }
__declspec(naked) void _DeletePortW() { _asm { jmp[winspool.DeletePortW] } }
__declspec(naked) void _DeletePrintProcessorA() { _asm { jmp[winspool.DeletePrintProcessorA] } }
__declspec(naked) void _DeletePrintProcessorW() { _asm { jmp[winspool.DeletePrintProcessorW] } }
__declspec(naked) void _DeletePrintProvidorA() { _asm { jmp[winspool.DeletePrintProvidorA] } }
__declspec(naked) void _DeletePrintProvidorW() { _asm { jmp[winspool.DeletePrintProvidorW] } }
__declspec(naked) void _DeletePrinter() { _asm { jmp[winspool.DeletePrinter] } }
__declspec(naked) void _DeletePrinterConnectionA() { _asm { jmp[winspool.DeletePrinterConnectionA] } }
__declspec(naked) void _DeletePrinterConnectionW() { _asm { jmp[winspool.DeletePrinterConnectionW] } }
__declspec(naked) void _DeletePrinterDataA() { _asm { jmp[winspool.DeletePrinterDataA] } }
__declspec(naked) void _DeletePrinterDataExA() { _asm { jmp[winspool.DeletePrinterDataExA] } }
__declspec(naked) void _DeletePrinterDataExW() { _asm { jmp[winspool.DeletePrinterDataExW] } }
__declspec(naked) void _DeletePrinterDataW() { _asm { jmp[winspool.DeletePrinterDataW] } }
__declspec(naked) void _DeletePrinterDriverA() { _asm { jmp[winspool.DeletePrinterDriverA] } }
__declspec(naked) void _DeletePrinterDriverExA() { _asm { jmp[winspool.DeletePrinterDriverExA] } }
__declspec(naked) void _DeletePrinterDriverExW() { _asm { jmp[winspool.DeletePrinterDriverExW] } }
__declspec(naked) void _DeletePrinterDriverPackageA() { _asm { jmp[winspool.DeletePrinterDriverPackageA] } }
__declspec(naked) void _DeletePrinterDriverPackageW() { _asm { jmp[winspool.DeletePrinterDriverPackageW] } }
__declspec(naked) void _DeletePrinterDriverW() { _asm { jmp[winspool.DeletePrinterDriverW] } }
__declspec(naked) void _DeletePrinterIC() { _asm { jmp[winspool.DeletePrinterIC] } }
__declspec(naked) void _DeletePrinterKeyA() { _asm { jmp[winspool.DeletePrinterKeyA] } }
__declspec(naked) void _DeletePrinterKeyW() { _asm { jmp[winspool.DeletePrinterKeyW] } }
__declspec(naked) void _DevQueryPrint() { _asm { jmp[winspool.DevQueryPrint] } }
__declspec(naked) void _DevQueryPrintEx() { _asm { jmp[winspool.DevQueryPrintEx] } }
__declspec(naked) void _DeviceCapabilities() { _asm { jmp[winspool.DeviceCapabilities] } }
__declspec(naked) void _DeviceCapabilitiesA() { _asm { jmp[winspool.DeviceCapabilitiesA] } }
__declspec(naked) void _DeviceCapabilitiesW() { _asm { jmp[winspool.DeviceCapabilitiesW] } }
__declspec(naked) void _DeviceMode() { _asm { jmp[winspool.DeviceMode] } }
__declspec(naked) void _DevicePropertySheets() { _asm { jmp[winspool.DevicePropertySheets] } }
__declspec(naked) void _DocumentEvent() { _asm { jmp[winspool.DocumentEvent] } }
__declspec(naked) void _DocumentPropertiesA() { _asm { jmp[winspool.DocumentPropertiesA] } }
__declspec(naked) void _DocumentPropertiesW() { _asm { jmp[winspool.DocumentPropertiesW] } }
__declspec(naked) void _DocumentPropertySheets() { _asm { jmp[winspool.DocumentPropertySheets] } }
__declspec(naked) void _EXTDEVICEMODE() { _asm { jmp[winspool.EXTDEVICEMODE] } }
__declspec(naked) void _EndDocPrinter() { _asm { jmp[winspool.EndDocPrinter] } }
__declspec(naked) void _EndPagePrinter() { _asm { jmp[winspool.EndPagePrinter] } }
__declspec(naked) void _EnumFormsA() { _asm { jmp[winspool.EnumFormsA] } }
__declspec(naked) void _EnumFormsW() { _asm { jmp[winspool.EnumFormsW] } }
__declspec(naked) void _EnumJobNamedProperties() { _asm { jmp[winspool.EnumJobNamedProperties] } }
__declspec(naked) void _EnumJobsA() { _asm { jmp[winspool.EnumJobsA] } }
__declspec(naked) void _EnumJobsW() { _asm { jmp[winspool.EnumJobsW] } }
__declspec(naked) void _EnumMonitorsA() { _asm { jmp[winspool.EnumMonitorsA] } }
__declspec(naked) void _EnumMonitorsW() { _asm { jmp[winspool.EnumMonitorsW] } }
__declspec(naked) void _EnumPortsA() { _asm { jmp[winspool.EnumPortsA] } }
__declspec(naked) void _EnumPortsW() { _asm { jmp[winspool.EnumPortsW] } }
__declspec(naked) void _EnumPrintProcessorDatatypesA() { _asm { jmp[winspool.EnumPrintProcessorDatatypesA] } }
__declspec(naked) void _EnumPrintProcessorDatatypesW() { _asm { jmp[winspool.EnumPrintProcessorDatatypesW] } }
__declspec(naked) void _EnumPrintProcessorsA() { _asm { jmp[winspool.EnumPrintProcessorsA] } }
__declspec(naked) void _EnumPrintProcessorsW() { _asm { jmp[winspool.EnumPrintProcessorsW] } }
__declspec(naked) void _EnumPrinterDataA() { _asm { jmp[winspool.EnumPrinterDataA] } }
__declspec(naked) void _EnumPrinterDataExA() { _asm { jmp[winspool.EnumPrinterDataExA] } }
__declspec(naked) void _EnumPrinterDataExW() { _asm { jmp[winspool.EnumPrinterDataExW] } }
__declspec(naked) void _EnumPrinterDataW() { _asm { jmp[winspool.EnumPrinterDataW] } }
__declspec(naked) void _EnumPrinterDriversA() { _asm { jmp[winspool.EnumPrinterDriversA] } }
__declspec(naked) void _EnumPrinterDriversW() { _asm { jmp[winspool.EnumPrinterDriversW] } }
__declspec(naked) void _EnumPrinterKeyA() { _asm { jmp[winspool.EnumPrinterKeyA] } }
__declspec(naked) void _EnumPrinterKeyW() { _asm { jmp[winspool.EnumPrinterKeyW] } }
__declspec(naked) void _EnumPrintersA() { _asm { jmp[winspool.EnumPrintersA] } }
__declspec(naked) void _EnumPrintersW() { _asm { jmp[winspool.EnumPrintersW] } }
__declspec(naked) void _ExtDeviceMode() { _asm { jmp[winspool.ExtDeviceMode] } }
__declspec(naked) void _FindClosePrinterChangeNotification() { _asm { jmp[winspool.FindClosePrinterChangeNotification] } }
__declspec(naked) void _FindFirstPrinterChangeNotification() { _asm { jmp[winspool.FindFirstPrinterChangeNotification] } }
__declspec(naked) void _FindNextPrinterChangeNotification() { _asm { jmp[winspool.FindNextPrinterChangeNotification] } }
__declspec(naked) void _FlushPrinter() { _asm { jmp[winspool.FlushPrinter] } }
__declspec(naked) void _FreePrintNamedPropertyArray() { _asm { jmp[winspool.FreePrintNamedPropertyArray] } }
__declspec(naked) void _FreePrintPropertyValue() { _asm { jmp[winspool.FreePrintPropertyValue] } }
__declspec(naked) void _FreePrinterNotifyInfo() { _asm { jmp[winspool.FreePrinterNotifyInfo] } }
__declspec(naked) void _GetCorePrinterDriversA() { _asm { jmp[winspool.GetCorePrinterDriversA] } }
__declspec(naked) void _GetCorePrinterDriversW() { _asm { jmp[winspool.GetCorePrinterDriversW] } }
__declspec(naked) void _GetDefaultPrinterA() { _asm { jmp[winspool.GetDefaultPrinterA] } }
__declspec(naked) void _GetDefaultPrinterW() { _asm { jmp[winspool.GetDefaultPrinterW] } }
__declspec(naked) void _GetFormA() { _asm { jmp[winspool.GetFormA] } }
__declspec(naked) void _GetFormW() { _asm { jmp[winspool.GetFormW] } }
__declspec(naked) void _GetJobA() { _asm { jmp[winspool.GetJobA] } }
__declspec(naked) void _GetJobNamedPropertyValue() { _asm { jmp[winspool.GetJobNamedPropertyValue] } }
__declspec(naked) void _GetJobW() { _asm { jmp[winspool.GetJobW] } }
__declspec(naked) void _GetPrintExecutionData() { _asm { jmp[winspool.GetPrintExecutionData] } }
__declspec(naked) void _GetPrintOutputInfo() { _asm { jmp[winspool.GetPrintOutputInfo] } }
__declspec(naked) void _GetPrintProcessorDirectoryA() { _asm { jmp[winspool.GetPrintProcessorDirectoryA] } }
__declspec(naked) void _GetPrintProcessorDirectoryW() { _asm { jmp[winspool.GetPrintProcessorDirectoryW] } }
__declspec(naked) void _GetPrinterA() { _asm { jmp[winspool.GetPrinterA] } }
__declspec(naked) void _GetPrinterDataA() { _asm { jmp[winspool.GetPrinterDataA] } }
__declspec(naked) void _GetPrinterDataExA() { _asm { jmp[winspool.GetPrinterDataExA] } }
__declspec(naked) void _GetPrinterDataExW() { _asm { jmp[winspool.GetPrinterDataExW] } }
__declspec(naked) void _GetPrinterDataW() { _asm { jmp[winspool.GetPrinterDataW] } }
__declspec(naked) void _GetPrinterDriver2A() { _asm { jmp[winspool.GetPrinterDriver2A] } }
__declspec(naked) void _GetPrinterDriver2W() { _asm { jmp[winspool.GetPrinterDriver2W] } }
__declspec(naked) void _GetPrinterDriverA() { _asm { jmp[winspool.GetPrinterDriverA] } }
__declspec(naked) void _GetPrinterDriverDirectoryA() { _asm { jmp[winspool.GetPrinterDriverDirectoryA] } }
__declspec(naked) void _GetPrinterDriverDirectoryW() { _asm { jmp[winspool.GetPrinterDriverDirectoryW] } }
__declspec(naked) void _GetPrinterDriverPackagePathA() { _asm { jmp[winspool.GetPrinterDriverPackagePathA] } }
__declspec(naked) void _GetPrinterDriverPackagePathW() { _asm { jmp[winspool.GetPrinterDriverPackagePathW] } }
__declspec(naked) void _GetPrinterDriverW() { _asm { jmp[winspool.GetPrinterDriverW] } }
__declspec(naked) void _GetPrinterW() { _asm { jmp[winspool.GetPrinterW] } }
__declspec(naked) void _GetSpoolFileHandle() { _asm { jmp[winspool.GetSpoolFileHandle] } }
__declspec(naked) void _InstallPrinterDriverFromPackageA() { _asm { jmp[winspool.InstallPrinterDriverFromPackageA] } }
__declspec(naked) void _InstallPrinterDriverFromPackageW() { _asm { jmp[winspool.InstallPrinterDriverFromPackageW] } }
__declspec(naked) void _IsValidDevmodeA() { _asm { jmp[winspool.IsValidDevmodeA] } }
__declspec(naked) void _IsValidDevmodeW() { _asm { jmp[winspool.IsValidDevmodeW] } }
__declspec(naked) void _OpenPrinter2A() { _asm { jmp[winspool.OpenPrinter2A] } }
__declspec(naked) void _OpenPrinter2W() { _asm { jmp[winspool.OpenPrinter2W] } }
__declspec(naked) void _OpenPrinterA() { _asm { jmp[winspool.OpenPrinterA] } }
__declspec(naked) void _OpenPrinterW() { _asm { jmp[winspool.OpenPrinterW] } }
__declspec(naked) void _PerfClose() { _asm { jmp[winspool.PerfClose] } }
__declspec(naked) void _PerfCollect() { _asm { jmp[winspool.PerfCollect] } }
__declspec(naked) void _PerfOpen() { _asm { jmp[winspool.PerfOpen] } }
__declspec(naked) void _PlayGdiScriptOnPrinterIC() { _asm { jmp[winspool.PlayGdiScriptOnPrinterIC] } }
__declspec(naked) void _PrinterMessageBoxA() { _asm { jmp[winspool.PrinterMessageBoxA] } }
__declspec(naked) void _PrinterMessageBoxW() { _asm { jmp[winspool.PrinterMessageBoxW] } }
__declspec(naked) void _PrinterProperties() { _asm { jmp[winspool.PrinterProperties] } }
__declspec(naked) void _QueryColorProfile() { _asm { jmp[winspool.QueryColorProfile] } }
__declspec(naked) void _QueryRemoteFonts() { _asm { jmp[winspool.QueryRemoteFonts] } }
__declspec(naked) void _QuerySpoolMode() { _asm { jmp[winspool.QuerySpoolMode] } }
__declspec(naked) void _ReadPrinter() { _asm { jmp[winspool.ReadPrinter] } }
__declspec(naked) void _RegisterForPrintAsyncNotifications() { _asm { jmp[winspool.RegisterForPrintAsyncNotifications] } }
__declspec(naked) void _ReportJobProcessingProgress() { _asm { jmp[winspool.ReportJobProcessingProgress] } }
__declspec(naked) void _ResetPrinterA() { _asm { jmp[winspool.ResetPrinterA] } }
__declspec(naked) void _ResetPrinterW() { _asm { jmp[winspool.ResetPrinterW] } }
__declspec(naked) void _ScheduleJob() { _asm { jmp[winspool.ScheduleJob] } }
__declspec(naked) void _SeekPrinter() { _asm { jmp[winspool.SeekPrinter] } }
__declspec(naked) void _SetDefaultPrinterA() { _asm { jmp[winspool.SetDefaultPrinterA] } }
__declspec(naked) void _SetDefaultPrinterW() { _asm { jmp[winspool.SetDefaultPrinterW] } }
__declspec(naked) void _SetFormA() { _asm { jmp[winspool.SetFormA] } }
__declspec(naked) void _SetFormW() { _asm { jmp[winspool.SetFormW] } }
__declspec(naked) void _SetJobA() { _asm { jmp[winspool.SetJobA] } }
__declspec(naked) void _SetJobNamedProperty() { _asm { jmp[winspool.SetJobNamedProperty] } }
__declspec(naked) void _SetJobW() { _asm { jmp[winspool.SetJobW] } }
__declspec(naked) void _SetPortA() { _asm { jmp[winspool.SetPortA] } }
__declspec(naked) void _SetPortW() { _asm { jmp[winspool.SetPortW] } }
__declspec(naked) void _SetPrinterA() { _asm { jmp[winspool.SetPrinterA] } }
__declspec(naked) void _SetPrinterDataA() { _asm { jmp[winspool.SetPrinterDataA] } }
__declspec(naked) void _SetPrinterDataExA() { _asm { jmp[winspool.SetPrinterDataExA] } }
__declspec(naked) void _SetPrinterDataExW() { _asm { jmp[winspool.SetPrinterDataExW] } }
__declspec(naked) void _SetPrinterDataW() { _asm { jmp[winspool.SetPrinterDataW] } }
__declspec(naked) void _SetPrinterW() { _asm { jmp[winspool.SetPrinterW] } }
__declspec(naked) void _SplDriverUnloadComplete() { _asm { jmp[winspool.SplDriverUnloadComplete] } }
__declspec(naked) void _SpoolerDevQueryPrintW() { _asm { jmp[winspool.SpoolerDevQueryPrintW] } }
__declspec(naked) void _SpoolerPrinterEvent() { _asm { jmp[winspool.SpoolerPrinterEvent] } }
__declspec(naked) void _StartDocDlgA() { _asm { jmp[winspool.StartDocDlgA] } }
__declspec(naked) void _StartDocDlgW() { _asm { jmp[winspool.StartDocDlgW] } }
__declspec(naked) void _StartDocPrinterA() { _asm { jmp[winspool.StartDocPrinterA] } }
__declspec(naked) void _StartDocPrinterW() { _asm { jmp[winspool.StartDocPrinterW] } }
__declspec(naked) void _StartPagePrinter() { _asm { jmp[winspool.StartPagePrinter] } }
__declspec(naked) void _UnRegisterForPrintAsyncNotifications() { _asm { jmp[winspool.UnRegisterForPrintAsyncNotifications] } }
__declspec(naked) void _UploadPrinterDriverPackageA() { _asm { jmp[winspool.UploadPrinterDriverPackageA] } }
__declspec(naked) void _UploadPrinterDriverPackageW() { _asm { jmp[winspool.UploadPrinterDriverPackageW] } }
__declspec(naked) void _WaitForPrinterChange() { _asm { jmp[winspool.WaitForPrinterChange] } }
__declspec(naked) void _WritePrinter() { _asm { jmp[winspool.WritePrinter] } }
__declspec(naked) void _XcvDataW() { _asm { jmp[winspool.XcvDataW] } }

struct dbghelp_dll {
    FARPROC DbgHelpCreateUserDump;
    FARPROC DbgHelpCreateUserDumpW;
    FARPROC EnumDirTree;
    FARPROC EnumDirTreeW;
    FARPROC EnumerateLoadedModules;
    FARPROC EnumerateLoadedModules64;
    FARPROC EnumerateLoadedModulesEx;
    FARPROC EnumerateLoadedModulesExW;
    FARPROC EnumerateLoadedModulesW64;
    FARPROC ExtensionApiVersion;
    FARPROC FindDebugInfoFile;
    FARPROC FindDebugInfoFileEx;
    FARPROC FindDebugInfoFileExW;
    FARPROC FindExecutableImage;
    FARPROC FindExecutableImageEx;
    FARPROC FindExecutableImageExW;
    FARPROC FindFileInPath;
    FARPROC FindFileInSearchPath;
    FARPROC GetTimestampForLoadedLibrary;
    FARPROC ImageDirectoryEntryToData;
    FARPROC ImageDirectoryEntryToDataEx;
    FARPROC ImageNtHeader;
    FARPROC ImageRvaToSection;
    FARPROC ImageRvaToVa;
    FARPROC ImagehlpApiVersion;
    FARPROC ImagehlpApiVersionEx;
    FARPROC MakeSureDirectoryPathExists;
    FARPROC MiniDumpReadDumpStream;
    FARPROC MiniDumpWriteDump;
    FARPROC SearchTreeForFile;
    FARPROC SearchTreeForFileW;
    FARPROC StackWalk;
    FARPROC StackWalk64;
    FARPROC SymAddSourceStream;
    FARPROC SymAddSourceStreamA;
    FARPROC SymAddSourceStreamW;
    FARPROC SymAddSymbol;
    FARPROC SymAddSymbolW;
    FARPROC SymCleanup;
    FARPROC SymDeleteSymbol;
    FARPROC SymDeleteSymbolW;
    FARPROC SymEnumLines;
    FARPROC SymEnumLinesW;
    FARPROC SymEnumProcesses;
    FARPROC SymEnumSourceFileTokens;
    FARPROC SymEnumSourceFiles;
    FARPROC SymEnumSourceFilesW;
    FARPROC SymEnumSourceLines;
    FARPROC SymEnumSourceLinesW;
    FARPROC SymEnumSym;
    FARPROC SymEnumSymbols;
    FARPROC SymEnumSymbolsForAddr;
    FARPROC SymEnumSymbolsForAddrW;
    FARPROC SymEnumSymbolsW;
    FARPROC SymEnumTypes;
    FARPROC SymEnumTypesByName;
    FARPROC SymEnumTypesByNameW;
    FARPROC SymEnumTypesW;
    FARPROC SymEnumerateModules;
    FARPROC SymEnumerateModules64;
    FARPROC SymEnumerateModulesW64;
    FARPROC SymEnumerateSymbols;
    FARPROC SymEnumerateSymbols64;
    FARPROC SymEnumerateSymbolsW;
    FARPROC SymEnumerateSymbolsW64;
    FARPROC SymFindDebugInfoFile;
    FARPROC SymFindDebugInfoFileW;
    FARPROC SymFindExecutableImage;
    FARPROC SymFindExecutableImageW;
    FARPROC SymFindFileInPath;
    FARPROC SymFindFileInPathW;
    FARPROC SymFromAddr;
    FARPROC SymFromAddrW;
    FARPROC SymFromIndex;
    FARPROC SymFromIndexW;
    FARPROC SymFromName;
    FARPROC SymFromNameW;
    FARPROC SymFromToken;
    FARPROC SymFromTokenW;
    FARPROC SymFunctionTableAccess;
    FARPROC SymFunctionTableAccess64;
    FARPROC SymGetFileLineOffsets64;
    FARPROC SymGetHomeDirectory;
    FARPROC SymGetHomeDirectoryW;
    FARPROC SymGetLineFromAddr;
    FARPROC SymGetLineFromAddr64;
    FARPROC SymGetLineFromAddrW64;
    FARPROC SymGetLineFromName;
    FARPROC SymGetLineFromName64;
    FARPROC SymGetLineFromNameW64;
    FARPROC SymGetLineNext;
    FARPROC SymGetLineNext64;
    FARPROC SymGetLineNextW64;
    FARPROC SymGetLinePrev;
    FARPROC SymGetLinePrev64;
    FARPROC SymGetLinePrevW64;
    FARPROC SymGetModuleBase;
    FARPROC SymGetModuleBase64;
    FARPROC SymGetModuleInfo;
    FARPROC SymGetModuleInfo64;
    FARPROC SymGetModuleInfoW;
    FARPROC SymGetModuleInfoW64;
    FARPROC SymGetOmapBlockBase;
    FARPROC SymGetOmaps;
    FARPROC SymGetOptions;
    FARPROC SymGetScope;
    FARPROC SymGetScopeW;
    FARPROC SymGetSearchPath;
    FARPROC SymGetSearchPathW;
    FARPROC SymGetSourceFile;
    FARPROC SymGetSourceFileFromToken;
    FARPROC SymGetSourceFileFromTokenW;
    FARPROC SymGetSourceFileToken;
    FARPROC SymGetSourceFileTokenW;
    FARPROC SymGetSourceFileW;
    FARPROC SymGetSourceVarFromToken;
    FARPROC SymGetSourceVarFromTokenW;
    FARPROC SymGetSymFromAddr;
    FARPROC SymGetSymFromAddr64;
    FARPROC SymGetSymFromName;
    FARPROC SymGetSymFromName64;
    FARPROC SymGetSymNext;
    FARPROC SymGetSymNext64;
    FARPROC SymGetSymPrev;
    FARPROC SymGetSymPrev64;
    FARPROC SymGetSymbolFile;
    FARPROC SymGetSymbolFileW;
    FARPROC SymGetTypeFromName;
    FARPROC SymGetTypeFromNameW;
    FARPROC SymGetTypeInfo;
    FARPROC SymGetTypeInfoEx;
    FARPROC SymGetUnwindInfo;
    FARPROC SymInitialize;
    FARPROC SymInitializeW;
    FARPROC SymLoadModule;
    FARPROC SymLoadModule64;
    FARPROC SymLoadModuleEx;
    FARPROC SymLoadModuleExW;
    FARPROC SymMatchFileName;
    FARPROC SymMatchFileNameW;
    FARPROC SymMatchString;
    FARPROC SymMatchStringA;
    FARPROC SymMatchStringW;
    FARPROC SymNext;
    FARPROC SymNextW;
    FARPROC SymPrev;
    FARPROC SymPrevW;
    FARPROC SymRefreshModuleList;
    FARPROC SymRegisterCallback;
    FARPROC SymRegisterCallback64;
    FARPROC SymRegisterCallbackW64;
    FARPROC SymRegisterFunctionEntryCallback;
    FARPROC SymRegisterFunctionEntryCallback64;
    FARPROC SymSearch;
    FARPROC SymSearchW;
    FARPROC SymSetContext;
    FARPROC SymSetHomeDirectory;
    FARPROC SymSetHomeDirectoryW;
    FARPROC SymSetOptions;
    FARPROC SymSetParentWindow;
    FARPROC SymSetScopeFromAddr;
    FARPROC SymSetScopeFromIndex;
    FARPROC SymSetSearchPath;
    FARPROC SymSetSearchPathW;
    FARPROC SymSrvDeltaName;
    FARPROC SymSrvDeltaNameW;
    FARPROC SymSrvGetFileIndexInfo;
    FARPROC SymSrvGetFileIndexInfoW;
    FARPROC SymSrvGetFileIndexString;
    FARPROC SymSrvGetFileIndexStringW;
    FARPROC SymSrvGetFileIndexes;
    FARPROC SymSrvGetFileIndexesW;
    FARPROC SymSrvGetSupplement;
    FARPROC SymSrvGetSupplementW;
    FARPROC SymSrvIsStore;
    FARPROC SymSrvIsStoreW;
    FARPROC SymSrvStoreFile;
    FARPROC SymSrvStoreFileW;
    FARPROC SymSrvStoreSupplement;
    FARPROC SymSrvStoreSupplementW;
    FARPROC SymUnDName;
    FARPROC SymUnDName64;
    FARPROC SymUnloadModule;
    FARPROC SymUnloadModule64;
    FARPROC UnDecorateSymbolName;
    FARPROC UnDecorateSymbolNameW;
    FARPROC WinDbgExtensionDllInit;
    FARPROC block;
    FARPROC chksym;
    FARPROC dbghelp;
    FARPROC dh;
    FARPROC fptr;
    FARPROC homedir;
    FARPROC itoldyouso;
    FARPROC lmi;
    FARPROC lminfo;
    FARPROC omap;
    FARPROC srcfiles;
    FARPROC stack_force_ebp;
    FARPROC stackdbg;
    FARPROC sym;
    FARPROC symsrv;
    FARPROC vc7fpo;
} dbghelp;

__declspec(naked) void _DbgHelpCreateUserDump() { _asm { jmp[dbghelp.DbgHelpCreateUserDump] } }
__declspec(naked) void _DbgHelpCreateUserDumpW() { _asm { jmp[dbghelp.DbgHelpCreateUserDumpW] } }
__declspec(naked) void _EnumDirTree() { _asm { jmp[dbghelp.EnumDirTree] } }
__declspec(naked) void _EnumDirTreeW() { _asm { jmp[dbghelp.EnumDirTreeW] } }
__declspec(naked) void _EnumerateLoadedModules() { _asm { jmp[dbghelp.EnumerateLoadedModules] } }
__declspec(naked) void _EnumerateLoadedModules64() { _asm { jmp[dbghelp.EnumerateLoadedModules64] } }
__declspec(naked) void _EnumerateLoadedModulesEx() { _asm { jmp[dbghelp.EnumerateLoadedModulesEx] } }
__declspec(naked) void _EnumerateLoadedModulesExW() { _asm { jmp[dbghelp.EnumerateLoadedModulesExW] } }
__declspec(naked) void _EnumerateLoadedModulesW64() { _asm { jmp[dbghelp.EnumerateLoadedModulesW64] } }
__declspec(naked) void _ExtensionApiVersion() { _asm { jmp[dbghelp.ExtensionApiVersion] } }
__declspec(naked) void _FindDebugInfoFile() { _asm { jmp[dbghelp.FindDebugInfoFile] } }
__declspec(naked) void _FindDebugInfoFileEx() { _asm { jmp[dbghelp.FindDebugInfoFileEx] } }
__declspec(naked) void _FindDebugInfoFileExW() { _asm { jmp[dbghelp.FindDebugInfoFileExW] } }
__declspec(naked) void _FindExecutableImage() { _asm { jmp[dbghelp.FindExecutableImage] } }
__declspec(naked) void _FindExecutableImageEx() { _asm { jmp[dbghelp.FindExecutableImageEx] } }
__declspec(naked) void _FindExecutableImageExW() { _asm { jmp[dbghelp.FindExecutableImageExW] } }
__declspec(naked) void _FindFileInPath() { _asm { jmp[dbghelp.FindFileInPath] } }
__declspec(naked) void _FindFileInSearchPath() { _asm { jmp[dbghelp.FindFileInSearchPath] } }
__declspec(naked) void _GetTimestampForLoadedLibrary() { _asm { jmp[dbghelp.GetTimestampForLoadedLibrary] } }
__declspec(naked) void _ImageDirectoryEntryToData() { _asm { jmp[dbghelp.ImageDirectoryEntryToData] } }
__declspec(naked) void _ImageDirectoryEntryToDataEx() { _asm { jmp[dbghelp.ImageDirectoryEntryToDataEx] } }
__declspec(naked) void _ImageNtHeader() { _asm { jmp[dbghelp.ImageNtHeader] } }
__declspec(naked) void _ImageRvaToSection() { _asm { jmp[dbghelp.ImageRvaToSection] } }
__declspec(naked) void _ImageRvaToVa() { _asm { jmp[dbghelp.ImageRvaToVa] } }
__declspec(naked) void _ImagehlpApiVersion() { _asm { jmp[dbghelp.ImagehlpApiVersion] } }
__declspec(naked) void _ImagehlpApiVersionEx() { _asm { jmp[dbghelp.ImagehlpApiVersionEx] } }
__declspec(naked) void _MakeSureDirectoryPathExists() { _asm { jmp[dbghelp.MakeSureDirectoryPathExists] } }
__declspec(naked) void _MiniDumpReadDumpStream() { _asm { jmp[dbghelp.MiniDumpReadDumpStream] } }
__declspec(naked) void _MiniDumpWriteDump() { _asm { jmp[dbghelp.MiniDumpWriteDump] } }
__declspec(naked) void _SearchTreeForFile() { _asm { jmp[dbghelp.SearchTreeForFile] } }
__declspec(naked) void _SearchTreeForFileW() { _asm { jmp[dbghelp.SearchTreeForFileW] } }
__declspec(naked) void _StackWalk() { _asm { jmp[dbghelp.StackWalk] } }
__declspec(naked) void _StackWalk64() { _asm { jmp[dbghelp.StackWalk64] } }
__declspec(naked) void _SymAddSourceStream() { _asm { jmp[dbghelp.SymAddSourceStream] } }
__declspec(naked) void _SymAddSourceStreamA() { _asm { jmp[dbghelp.SymAddSourceStreamA] } }
__declspec(naked) void _SymAddSourceStreamW() { _asm { jmp[dbghelp.SymAddSourceStreamW] } }
__declspec(naked) void _SymAddSymbol() { _asm { jmp[dbghelp.SymAddSymbol] } }
__declspec(naked) void _SymAddSymbolW() { _asm { jmp[dbghelp.SymAddSymbolW] } }
__declspec(naked) void _SymCleanup() { _asm { jmp[dbghelp.SymCleanup] } }
__declspec(naked) void _SymDeleteSymbol() { _asm { jmp[dbghelp.SymDeleteSymbol] } }
__declspec(naked) void _SymDeleteSymbolW() { _asm { jmp[dbghelp.SymDeleteSymbolW] } }
__declspec(naked) void _SymEnumLines() { _asm { jmp[dbghelp.SymEnumLines] } }
__declspec(naked) void _SymEnumLinesW() { _asm { jmp[dbghelp.SymEnumLinesW] } }
__declspec(naked) void _SymEnumProcesses() { _asm { jmp[dbghelp.SymEnumProcesses] } }
__declspec(naked) void _SymEnumSourceFileTokens() { _asm { jmp[dbghelp.SymEnumSourceFileTokens] } }
__declspec(naked) void _SymEnumSourceFiles() { _asm { jmp[dbghelp.SymEnumSourceFiles] } }
__declspec(naked) void _SymEnumSourceFilesW() { _asm { jmp[dbghelp.SymEnumSourceFilesW] } }
__declspec(naked) void _SymEnumSourceLines() { _asm { jmp[dbghelp.SymEnumSourceLines] } }
__declspec(naked) void _SymEnumSourceLinesW() { _asm { jmp[dbghelp.SymEnumSourceLinesW] } }
__declspec(naked) void _SymEnumSym() { _asm { jmp[dbghelp.SymEnumSym] } }
__declspec(naked) void _SymEnumSymbols() { _asm { jmp[dbghelp.SymEnumSymbols] } }
__declspec(naked) void _SymEnumSymbolsForAddr() { _asm { jmp[dbghelp.SymEnumSymbolsForAddr] } }
__declspec(naked) void _SymEnumSymbolsForAddrW() { _asm { jmp[dbghelp.SymEnumSymbolsForAddrW] } }
__declspec(naked) void _SymEnumSymbolsW() { _asm { jmp[dbghelp.SymEnumSymbolsW] } }
__declspec(naked) void _SymEnumTypes() { _asm { jmp[dbghelp.SymEnumTypes] } }
__declspec(naked) void _SymEnumTypesByName() { _asm { jmp[dbghelp.SymEnumTypesByName] } }
__declspec(naked) void _SymEnumTypesByNameW() { _asm { jmp[dbghelp.SymEnumTypesByNameW] } }
__declspec(naked) void _SymEnumTypesW() { _asm { jmp[dbghelp.SymEnumTypesW] } }
__declspec(naked) void _SymEnumerateModules() { _asm { jmp[dbghelp.SymEnumerateModules] } }
__declspec(naked) void _SymEnumerateModules64() { _asm { jmp[dbghelp.SymEnumerateModules64] } }
__declspec(naked) void _SymEnumerateModulesW64() { _asm { jmp[dbghelp.SymEnumerateModulesW64] } }
__declspec(naked) void _SymEnumerateSymbols() { _asm { jmp[dbghelp.SymEnumerateSymbols] } }
__declspec(naked) void _SymEnumerateSymbols64() { _asm { jmp[dbghelp.SymEnumerateSymbols64] } }
__declspec(naked) void _SymEnumerateSymbolsW() { _asm { jmp[dbghelp.SymEnumerateSymbolsW] } }
__declspec(naked) void _SymEnumerateSymbolsW64() { _asm { jmp[dbghelp.SymEnumerateSymbolsW64] } }
__declspec(naked) void _SymFindDebugInfoFile() { _asm { jmp[dbghelp.SymFindDebugInfoFile] } }
__declspec(naked) void _SymFindDebugInfoFileW() { _asm { jmp[dbghelp.SymFindDebugInfoFileW] } }
__declspec(naked) void _SymFindExecutableImage() { _asm { jmp[dbghelp.SymFindExecutableImage] } }
__declspec(naked) void _SymFindExecutableImageW() { _asm { jmp[dbghelp.SymFindExecutableImageW] } }
__declspec(naked) void _SymFindFileInPath() { _asm { jmp[dbghelp.SymFindFileInPath] } }
__declspec(naked) void _SymFindFileInPathW() { _asm { jmp[dbghelp.SymFindFileInPathW] } }
__declspec(naked) void _SymFromAddr() { _asm { jmp[dbghelp.SymFromAddr] } }
__declspec(naked) void _SymFromAddrW() { _asm { jmp[dbghelp.SymFromAddrW] } }
__declspec(naked) void _SymFromIndex() { _asm { jmp[dbghelp.SymFromIndex] } }
__declspec(naked) void _SymFromIndexW() { _asm { jmp[dbghelp.SymFromIndexW] } }
__declspec(naked) void _SymFromName() { _asm { jmp[dbghelp.SymFromName] } }
__declspec(naked) void _SymFromNameW() { _asm { jmp[dbghelp.SymFromNameW] } }
__declspec(naked) void _SymFromToken() { _asm { jmp[dbghelp.SymFromToken] } }
__declspec(naked) void _SymFromTokenW() { _asm { jmp[dbghelp.SymFromTokenW] } }
__declspec(naked) void _SymFunctionTableAccess() { _asm { jmp[dbghelp.SymFunctionTableAccess] } }
__declspec(naked) void _SymFunctionTableAccess64() { _asm { jmp[dbghelp.SymFunctionTableAccess64] } }
__declspec(naked) void _SymGetFileLineOffsets64() { _asm { jmp[dbghelp.SymGetFileLineOffsets64] } }
__declspec(naked) void _SymGetHomeDirectory() { _asm { jmp[dbghelp.SymGetHomeDirectory] } }
__declspec(naked) void _SymGetHomeDirectoryW() { _asm { jmp[dbghelp.SymGetHomeDirectoryW] } }
__declspec(naked) void _SymGetLineFromAddr() { _asm { jmp[dbghelp.SymGetLineFromAddr] } }
__declspec(naked) void _SymGetLineFromAddr64() { _asm { jmp[dbghelp.SymGetLineFromAddr64] } }
__declspec(naked) void _SymGetLineFromAddrW64() { _asm { jmp[dbghelp.SymGetLineFromAddrW64] } }
__declspec(naked) void _SymGetLineFromName() { _asm { jmp[dbghelp.SymGetLineFromName] } }
__declspec(naked) void _SymGetLineFromName64() { _asm { jmp[dbghelp.SymGetLineFromName64] } }
__declspec(naked) void _SymGetLineFromNameW64() { _asm { jmp[dbghelp.SymGetLineFromNameW64] } }
__declspec(naked) void _SymGetLineNext() { _asm { jmp[dbghelp.SymGetLineNext] } }
__declspec(naked) void _SymGetLineNext64() { _asm { jmp[dbghelp.SymGetLineNext64] } }
__declspec(naked) void _SymGetLineNextW64() { _asm { jmp[dbghelp.SymGetLineNextW64] } }
__declspec(naked) void _SymGetLinePrev() { _asm { jmp[dbghelp.SymGetLinePrev] } }
__declspec(naked) void _SymGetLinePrev64() { _asm { jmp[dbghelp.SymGetLinePrev64] } }
__declspec(naked) void _SymGetLinePrevW64() { _asm { jmp[dbghelp.SymGetLinePrevW64] } }
__declspec(naked) void _SymGetModuleBase() { _asm { jmp[dbghelp.SymGetModuleBase] } }
__declspec(naked) void _SymGetModuleBase64() { _asm { jmp[dbghelp.SymGetModuleBase64] } }
__declspec(naked) void _SymGetModuleInfo() { _asm { jmp[dbghelp.SymGetModuleInfo] } }
__declspec(naked) void _SymGetModuleInfo64() { _asm { jmp[dbghelp.SymGetModuleInfo64] } }
__declspec(naked) void _SymGetModuleInfoW() { _asm { jmp[dbghelp.SymGetModuleInfoW] } }
__declspec(naked) void _SymGetModuleInfoW64() { _asm { jmp[dbghelp.SymGetModuleInfoW64] } }
__declspec(naked) void _SymGetOmapBlockBase() { _asm { jmp[dbghelp.SymGetOmapBlockBase] } }
__declspec(naked) void _SymGetOmaps() { _asm { jmp[dbghelp.SymGetOmaps] } }
__declspec(naked) void _SymGetOptions() { _asm { jmp[dbghelp.SymGetOptions] } }
__declspec(naked) void _SymGetScope() { _asm { jmp[dbghelp.SymGetScope] } }
__declspec(naked) void _SymGetScopeW() { _asm { jmp[dbghelp.SymGetScopeW] } }
__declspec(naked) void _SymGetSearchPath() { _asm { jmp[dbghelp.SymGetSearchPath] } }
__declspec(naked) void _SymGetSearchPathW() { _asm { jmp[dbghelp.SymGetSearchPathW] } }
__declspec(naked) void _SymGetSourceFile() { _asm { jmp[dbghelp.SymGetSourceFile] } }
__declspec(naked) void _SymGetSourceFileFromToken() { _asm { jmp[dbghelp.SymGetSourceFileFromToken] } }
__declspec(naked) void _SymGetSourceFileFromTokenW() { _asm { jmp[dbghelp.SymGetSourceFileFromTokenW] } }
__declspec(naked) void _SymGetSourceFileToken() { _asm { jmp[dbghelp.SymGetSourceFileToken] } }
__declspec(naked) void _SymGetSourceFileTokenW() { _asm { jmp[dbghelp.SymGetSourceFileTokenW] } }
__declspec(naked) void _SymGetSourceFileW() { _asm { jmp[dbghelp.SymGetSourceFileW] } }
__declspec(naked) void _SymGetSourceVarFromToken() { _asm { jmp[dbghelp.SymGetSourceVarFromToken] } }
__declspec(naked) void _SymGetSourceVarFromTokenW() { _asm { jmp[dbghelp.SymGetSourceVarFromTokenW] } }
__declspec(naked) void _SymGetSymFromAddr() { _asm { jmp[dbghelp.SymGetSymFromAddr] } }
__declspec(naked) void _SymGetSymFromAddr64() { _asm { jmp[dbghelp.SymGetSymFromAddr64] } }
__declspec(naked) void _SymGetSymFromName() { _asm { jmp[dbghelp.SymGetSymFromName] } }
__declspec(naked) void _SymGetSymFromName64() { _asm { jmp[dbghelp.SymGetSymFromName64] } }
__declspec(naked) void _SymGetSymNext() { _asm { jmp[dbghelp.SymGetSymNext] } }
__declspec(naked) void _SymGetSymNext64() { _asm { jmp[dbghelp.SymGetSymNext64] } }
__declspec(naked) void _SymGetSymPrev() { _asm { jmp[dbghelp.SymGetSymPrev] } }
__declspec(naked) void _SymGetSymPrev64() { _asm { jmp[dbghelp.SymGetSymPrev64] } }
__declspec(naked) void _SymGetSymbolFile() { _asm { jmp[dbghelp.SymGetSymbolFile] } }
__declspec(naked) void _SymGetSymbolFileW() { _asm { jmp[dbghelp.SymGetSymbolFileW] } }
__declspec(naked) void _SymGetTypeFromName() { _asm { jmp[dbghelp.SymGetTypeFromName] } }
__declspec(naked) void _SymGetTypeFromNameW() { _asm { jmp[dbghelp.SymGetTypeFromNameW] } }
__declspec(naked) void _SymGetTypeInfo() { _asm { jmp[dbghelp.SymGetTypeInfo] } }
__declspec(naked) void _SymGetTypeInfoEx() { _asm { jmp[dbghelp.SymGetTypeInfoEx] } }
__declspec(naked) void _SymGetUnwindInfo() { _asm { jmp[dbghelp.SymGetUnwindInfo] } }
__declspec(naked) void _SymInitialize() { _asm { jmp[dbghelp.SymInitialize] } }
__declspec(naked) void _SymInitializeW() { _asm { jmp[dbghelp.SymInitializeW] } }
__declspec(naked) void _SymLoadModule() { _asm { jmp[dbghelp.SymLoadModule] } }
__declspec(naked) void _SymLoadModule64() { _asm { jmp[dbghelp.SymLoadModule64] } }
__declspec(naked) void _SymLoadModuleEx() { _asm { jmp[dbghelp.SymLoadModuleEx] } }
__declspec(naked) void _SymLoadModuleExW() { _asm { jmp[dbghelp.SymLoadModuleExW] } }
__declspec(naked) void _SymMatchFileName() { _asm { jmp[dbghelp.SymMatchFileName] } }
__declspec(naked) void _SymMatchFileNameW() { _asm { jmp[dbghelp.SymMatchFileNameW] } }
__declspec(naked) void _SymMatchString() { _asm { jmp[dbghelp.SymMatchString] } }
__declspec(naked) void _SymMatchStringA() { _asm { jmp[dbghelp.SymMatchStringA] } }
__declspec(naked) void _SymMatchStringW() { _asm { jmp[dbghelp.SymMatchStringW] } }
__declspec(naked) void _SymNext() { _asm { jmp[dbghelp.SymNext] } }
__declspec(naked) void _SymNextW() { _asm { jmp[dbghelp.SymNextW] } }
__declspec(naked) void _SymPrev() { _asm { jmp[dbghelp.SymPrev] } }
__declspec(naked) void _SymPrevW() { _asm { jmp[dbghelp.SymPrevW] } }
__declspec(naked) void _SymRefreshModuleList() { _asm { jmp[dbghelp.SymRefreshModuleList] } }
__declspec(naked) void _SymRegisterCallback() { _asm { jmp[dbghelp.SymRegisterCallback] } }
__declspec(naked) void _SymRegisterCallback64() { _asm { jmp[dbghelp.SymRegisterCallback64] } }
__declspec(naked) void _SymRegisterCallbackW64() { _asm { jmp[dbghelp.SymRegisterCallbackW64] } }
__declspec(naked) void _SymRegisterFunctionEntryCallback() { _asm { jmp[dbghelp.SymRegisterFunctionEntryCallback] } }
__declspec(naked) void _SymRegisterFunctionEntryCallback64() { _asm { jmp[dbghelp.SymRegisterFunctionEntryCallback64] } }
__declspec(naked) void _SymSearch() { _asm { jmp[dbghelp.SymSearch] } }
__declspec(naked) void _SymSearchW() { _asm { jmp[dbghelp.SymSearchW] } }
__declspec(naked) void _SymSetContext() { _asm { jmp[dbghelp.SymSetContext] } }
__declspec(naked) void _SymSetHomeDirectory() { _asm { jmp[dbghelp.SymSetHomeDirectory] } }
__declspec(naked) void _SymSetHomeDirectoryW() { _asm { jmp[dbghelp.SymSetHomeDirectoryW] } }
__declspec(naked) void _SymSetOptions() { _asm { jmp[dbghelp.SymSetOptions] } }
__declspec(naked) void _SymSetParentWindow() { _asm { jmp[dbghelp.SymSetParentWindow] } }
__declspec(naked) void _SymSetScopeFromAddr() { _asm { jmp[dbghelp.SymSetScopeFromAddr] } }
__declspec(naked) void _SymSetScopeFromIndex() { _asm { jmp[dbghelp.SymSetScopeFromIndex] } }
__declspec(naked) void _SymSetSearchPath() { _asm { jmp[dbghelp.SymSetSearchPath] } }
__declspec(naked) void _SymSetSearchPathW() { _asm { jmp[dbghelp.SymSetSearchPathW] } }
__declspec(naked) void _SymSrvDeltaName() { _asm { jmp[dbghelp.SymSrvDeltaName] } }
__declspec(naked) void _SymSrvDeltaNameW() { _asm { jmp[dbghelp.SymSrvDeltaNameW] } }
__declspec(naked) void _SymSrvGetFileIndexInfo() { _asm { jmp[dbghelp.SymSrvGetFileIndexInfo] } }
__declspec(naked) void _SymSrvGetFileIndexInfoW() { _asm { jmp[dbghelp.SymSrvGetFileIndexInfoW] } }
__declspec(naked) void _SymSrvGetFileIndexString() { _asm { jmp[dbghelp.SymSrvGetFileIndexString] } }
__declspec(naked) void _SymSrvGetFileIndexStringW() { _asm { jmp[dbghelp.SymSrvGetFileIndexStringW] } }
__declspec(naked) void _SymSrvGetFileIndexes() { _asm { jmp[dbghelp.SymSrvGetFileIndexes] } }
__declspec(naked) void _SymSrvGetFileIndexesW() { _asm { jmp[dbghelp.SymSrvGetFileIndexesW] } }
__declspec(naked) void _SymSrvGetSupplement() { _asm { jmp[dbghelp.SymSrvGetSupplement] } }
__declspec(naked) void _SymSrvGetSupplementW() { _asm { jmp[dbghelp.SymSrvGetSupplementW] } }
__declspec(naked) void _SymSrvIsStore() { _asm { jmp[dbghelp.SymSrvIsStore] } }
__declspec(naked) void _SymSrvIsStoreW() { _asm { jmp[dbghelp.SymSrvIsStoreW] } }
__declspec(naked) void _SymSrvStoreFile() { _asm { jmp[dbghelp.SymSrvStoreFile] } }
__declspec(naked) void _SymSrvStoreFileW() { _asm { jmp[dbghelp.SymSrvStoreFileW] } }
__declspec(naked) void _SymSrvStoreSupplement() { _asm { jmp[dbghelp.SymSrvStoreSupplement] } }
__declspec(naked) void _SymSrvStoreSupplementW() { _asm { jmp[dbghelp.SymSrvStoreSupplementW] } }
__declspec(naked) void _SymUnDName() { _asm { jmp[dbghelp.SymUnDName] } }
__declspec(naked) void _SymUnDName64() { _asm { jmp[dbghelp.SymUnDName64] } }
__declspec(naked) void _SymUnloadModule() { _asm { jmp[dbghelp.SymUnloadModule] } }
__declspec(naked) void _SymUnloadModule64() { _asm { jmp[dbghelp.SymUnloadModule64] } }
__declspec(naked) void _UnDecorateSymbolName() { _asm { jmp[dbghelp.UnDecorateSymbolName] } }
__declspec(naked) void _UnDecorateSymbolNameW() { _asm { jmp[dbghelp.UnDecorateSymbolNameW] } }
__declspec(naked) void _WinDbgExtensionDllInit() { _asm { jmp[dbghelp.WinDbgExtensionDllInit] } }
__declspec(naked) void _block() { _asm { jmp[dbghelp.block] } }
__declspec(naked) void _chksym() { _asm { jmp[dbghelp.chksym] } }
__declspec(naked) void _dbghelp() { _asm { jmp[dbghelp.dbghelp] } }
__declspec(naked) void _dh() { _asm { jmp[dbghelp.dh] } }
__declspec(naked) void _fptr() { _asm { jmp[dbghelp.fptr] } }
__declspec(naked) void _homedir() { _asm { jmp[dbghelp.homedir] } }
__declspec(naked) void _itoldyouso() { _asm { jmp[dbghelp.itoldyouso] } }
__declspec(naked) void _lmi() { _asm { jmp[dbghelp.lmi] } }
__declspec(naked) void _lminfo() { _asm { jmp[dbghelp.lminfo] } }
__declspec(naked) void _omap() { _asm { jmp[dbghelp.omap] } }
__declspec(naked) void _srcfiles() { _asm { jmp[dbghelp.srcfiles] } }
__declspec(naked) void _stack_force_ebp() { _asm { jmp[dbghelp.stack_force_ebp] } }
__declspec(naked) void _stackdbg() { _asm { jmp[dbghelp.stackdbg] } }
__declspec(naked) void _sym() { _asm { jmp[dbghelp.sym] } }
__declspec(naked) void _symsrv() { _asm { jmp[dbghelp.symsrv] } }
__declspec(naked) void _vc7fpo() { _asm { jmp[dbghelp.vc7fpo] } }

struct ddraw_dll {
    FARPROC AcquireDDThreadLock;
    FARPROC CompleteCreateSysmemSurface;
    FARPROC D3DParseUnknownCommand;
    FARPROC DDGetAttachedSurfaceLcl;
    FARPROC DDInternalLock;
    FARPROC DDInternalUnlock;
    FARPROC DSoundHelp;
    FARPROC DirectDrawCreate;
    FARPROC DirectDrawCreateClipper;
    FARPROC DirectDrawCreateEx;
    FARPROC DirectDrawEnumerateA;
    FARPROC DirectDrawEnumerateExA;
    FARPROC DirectDrawEnumerateExW;
    FARPROC DirectDrawEnumerateW;
    FARPROC DllCanUnloadNow;
    FARPROC DllGetClassObject;
    FARPROC GetDDSurfaceLocal;
    FARPROC GetOLEThunkData;
    FARPROC GetSurfaceFromDC;
    FARPROC RegisterSpecialCase;
    FARPROC ReleaseDDThreadLock;
    FARPROC SetAppCompatData;
} ddraw;

__declspec(naked) void _AcquireDDThreadLock() { _asm { jmp[ddraw.AcquireDDThreadLock] } }
__declspec(naked) void _CompleteCreateSysmemSurface() { _asm { jmp[ddraw.CompleteCreateSysmemSurface] } }
__declspec(naked) void _D3DParseUnknownCommand() { _asm { jmp[ddraw.D3DParseUnknownCommand] } }
__declspec(naked) void _DDGetAttachedSurfaceLcl() { _asm { jmp[ddraw.DDGetAttachedSurfaceLcl] } }
__declspec(naked) void _DDInternalLock() { _asm { jmp[ddraw.DDInternalLock] } }
__declspec(naked) void _DDInternalUnlock() { _asm { jmp[ddraw.DDInternalUnlock] } }
__declspec(naked) void _DSoundHelp() { _asm { jmp[ddraw.DSoundHelp] } }
__declspec(naked) void _DirectDrawCreate() { _asm { jmp[ddraw.DirectDrawCreate] } }
__declspec(naked) void _DirectDrawCreateClipper() { _asm { jmp[ddraw.DirectDrawCreateClipper] } }
__declspec(naked) void _DirectDrawCreateEx() { _asm { jmp[ddraw.DirectDrawCreateEx] } }
__declspec(naked) void _DirectDrawEnumerateA() { _asm { jmp[ddraw.DirectDrawEnumerateA] } }
__declspec(naked) void _DirectDrawEnumerateExA() { _asm { jmp[ddraw.DirectDrawEnumerateExA] } }
__declspec(naked) void _DirectDrawEnumerateExW() { _asm { jmp[ddraw.DirectDrawEnumerateExW] } }
__declspec(naked) void _DirectDrawEnumerateW() { _asm { jmp[ddraw.DirectDrawEnumerateW] } }
__declspec(naked) void _DllCanUnloadNow() { _asm { jmp[ddraw.DllCanUnloadNow] } }
__declspec(naked) void _DllGetClassObject() { _asm { jmp[ddraw.DllGetClassObject] } }
__declspec(naked) void _GetDDSurfaceLocal() { _asm { jmp[ddraw.GetDDSurfaceLocal] } }
__declspec(naked) void _GetOLEThunkData() { _asm { jmp[ddraw.GetOLEThunkData] } }
__declspec(naked) void _GetSurfaceFromDC() { _asm { jmp[ddraw.GetSurfaceFromDC] } }
__declspec(naked) void _RegisterSpecialCase() { _asm { jmp[ddraw.RegisterSpecialCase] } }
__declspec(naked) void _ReleaseDDThreadLock() { _asm { jmp[ddraw.ReleaseDDThreadLock] } }
__declspec(naked) void _SetAppCompatData() { _asm { jmp[ddraw.SetAppCompatData] } }

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        std::wstring gameDir = loader::GetModuleDir(NULL);
        std::wstring moduleName = loader::GetModuleName(hModule);
        std::transform(moduleName.begin(), moduleName.end(), moduleName.begin(), tolower);
        bool loadingResult = false;
        bool isLibraryForGameOnly = false;
        bool isLibraryForEditorOnly = false;
        if (moduleName == L"d3d9.dll") {
            isLibraryForGameOnly = true;
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            d3d9.D3DPERF_BeginEvent = GetProcAddress(dll.handle, "D3DPERF_BeginEvent");
            d3d9.D3DPERF_EndEvent = GetProcAddress(dll.handle, "D3DPERF_EndEvent");
            d3d9.D3DPERF_GetStatus = GetProcAddress(dll.handle, "D3DPERF_GetStatus");
            d3d9.D3DPERF_QueryRepeatFrame = GetProcAddress(dll.handle, "D3DPERF_QueryRepeatFrame");
            d3d9.D3DPERF_SetMarker = GetProcAddress(dll.handle, "D3DPERF_SetMarker");
            d3d9.D3DPERF_SetOptions = GetProcAddress(dll.handle, "D3DPERF_SetOptions");
            d3d9.D3DPERF_SetRegion = GetProcAddress(dll.handle, "D3DPERF_SetRegion");
            d3d9.DebugSetLevel = GetProcAddress(dll.handle, "DebugSetLevel");
            d3d9.DebugSetMute = GetProcAddress(dll.handle, "DebugSetMute");
            d3d9.Direct3D9EnableMaximizedWindowedModeShim = GetProcAddress(dll.handle, "Direct3D9EnableMaximizedWindowedModeShim");
            d3d9.Direct3DCreate9 = GetProcAddress(dll.handle, "Direct3DCreate9");
            d3d9.Direct3DCreate9Ex = GetProcAddress(dll.handle, "Direct3DCreate9Ex");
            d3d9.Direct3DShaderValidatorCreate9 = GetProcAddress(dll.handle, "Direct3DShaderValidatorCreate9");
            d3d9.PSGPError = GetProcAddress(dll.handle, "PSGPError");
            d3d9.PSGPSampleTexture = GetProcAddress(dll.handle, "PSGPSampleTexture");
        }
        else if (moduleName == L"ddraw.dll") {
            isLibraryForGameOnly = true;
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            ddraw.AcquireDDThreadLock = GetProcAddress(dll.handle, "AcquireDDThreadLock");
            ddraw.CompleteCreateSysmemSurface = GetProcAddress(dll.handle, "CompleteCreateSysmemSurface");
            ddraw.D3DParseUnknownCommand = GetProcAddress(dll.handle, "D3DParseUnknownCommand");
            ddraw.DDGetAttachedSurfaceLcl = GetProcAddress(dll.handle, "DDGetAttachedSurfaceLcl");
            ddraw.DDInternalLock = GetProcAddress(dll.handle, "DDInternalLock");
            ddraw.DDInternalUnlock = GetProcAddress(dll.handle, "DDInternalUnlock");
            ddraw.DSoundHelp = GetProcAddress(dll.handle, "DSoundHelp");
            ddraw.DirectDrawCreate = GetProcAddress(dll.handle, "DirectDrawCreate");
            ddraw.DirectDrawCreateClipper = GetProcAddress(dll.handle, "DirectDrawCreateClipper");
            ddraw.DirectDrawCreateEx = GetProcAddress(dll.handle, "DirectDrawCreateEx");
            ddraw.DirectDrawEnumerateA = GetProcAddress(dll.handle, "DirectDrawEnumerateA");
            ddraw.DirectDrawEnumerateExA = GetProcAddress(dll.handle, "DirectDrawEnumerateExA");
            ddraw.DirectDrawEnumerateExW = GetProcAddress(dll.handle, "DirectDrawEnumerateExW");
            ddraw.DirectDrawEnumerateW = GetProcAddress(dll.handle, "DirectDrawEnumerateW");
            ddraw.DllCanUnloadNow = GetProcAddress(dll.handle, "DllCanUnloadNow");
            ddraw.DllGetClassObject = GetProcAddress(dll.handle, "DllGetClassObject");
            ddraw.GetDDSurfaceLocal = GetProcAddress(dll.handle, "GetDDSurfaceLocal");
            ddraw.GetOLEThunkData = GetProcAddress(dll.handle, "GetOLEThunkData");
            ddraw.GetSurfaceFromDC = GetProcAddress(dll.handle, "GetSurfaceFromDC");
            ddraw.RegisterSpecialCase = GetProcAddress(dll.handle, "RegisterSpecialCase");
            ddraw.ReleaseDDThreadLock = GetProcAddress(dll.handle, "ReleaseDDThreadLock");
            ddraw.SetAppCompatData = GetProcAddress(dll.handle, "SetAppCompatData");
        }
        else if (moduleName == L"winmm.dll") {
            isLibraryForGameOnly = true;
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            winmm.CloseDriver = GetProcAddress(dll.handle, "CloseDriver");
            winmm.DefDriverProc = GetProcAddress(dll.handle, "DefDriverProc");
            winmm.DriverCallback = GetProcAddress(dll.handle, "DriverCallback");
            winmm.DrvGetModuleHandle = GetProcAddress(dll.handle, "DrvGetModuleHandle");
            winmm.GetDriverModuleHandle = GetProcAddress(dll.handle, "GetDriverModuleHandle");
            winmm.NotifyCallbackData = GetProcAddress(dll.handle, "NotifyCallbackData");
            winmm.OpenDriver = GetProcAddress(dll.handle, "OpenDriver");
            winmm.PlaySound = GetProcAddress(dll.handle, "PlaySound");
            winmm.PlaySoundA = GetProcAddress(dll.handle, "PlaySoundA");
            winmm.PlaySoundW = GetProcAddress(dll.handle, "PlaySoundW");
            winmm.SendDriverMessage = GetProcAddress(dll.handle, "SendDriverMessage");
            winmm.WOW32DriverCallback = GetProcAddress(dll.handle, "WOW32DriverCallback");
            winmm.WOW32ResolveMultiMediaHandle = GetProcAddress(dll.handle, "WOW32ResolveMultiMediaHandle");
            winmm.WOWAppExit = GetProcAddress(dll.handle, "WOWAppExit");
            winmm.aux32Message = GetProcAddress(dll.handle, "aux32Message");
            winmm.auxGetDevCapsA = GetProcAddress(dll.handle, "auxGetDevCapsA");
            winmm.auxGetDevCapsW = GetProcAddress(dll.handle, "auxGetDevCapsW");
            winmm.auxGetNumDevs = GetProcAddress(dll.handle, "auxGetNumDevs");
            winmm.auxGetVolume = GetProcAddress(dll.handle, "auxGetVolume");
            winmm.auxOutMessage = GetProcAddress(dll.handle, "auxOutMessage");
            winmm.auxSetVolume = GetProcAddress(dll.handle, "auxSetVolume");
            winmm.joy32Message = GetProcAddress(dll.handle, "joy32Message");
            winmm.joyConfigChanged = GetProcAddress(dll.handle, "joyConfigChanged");
            winmm.joyGetDevCapsA = GetProcAddress(dll.handle, "joyGetDevCapsA");
            winmm.joyGetDevCapsW = GetProcAddress(dll.handle, "joyGetDevCapsW");
            winmm.joyGetNumDevs = GetProcAddress(dll.handle, "joyGetNumDevs");
            winmm.joyGetPos = GetProcAddress(dll.handle, "joyGetPos");
            winmm.joyGetPosEx = GetProcAddress(dll.handle, "joyGetPosEx");
            winmm.joyGetThreshold = GetProcAddress(dll.handle, "joyGetThreshold");
            winmm.joyReleaseCapture = GetProcAddress(dll.handle, "joyReleaseCapture");
            winmm.joySetCapture = GetProcAddress(dll.handle, "joySetCapture");
            winmm.joySetThreshold = GetProcAddress(dll.handle, "joySetThreshold");
            winmm.mci32Message = GetProcAddress(dll.handle, "mci32Message");
            winmm.mciDriverNotify = GetProcAddress(dll.handle, "mciDriverNotify");
            winmm.mciDriverYield = GetProcAddress(dll.handle, "mciDriverYield");
            winmm.mciExecute = GetProcAddress(dll.handle, "mciExecute");
            winmm.mciFreeCommandResource = GetProcAddress(dll.handle, "mciFreeCommandResource");
            winmm.mciGetCreatorTask = GetProcAddress(dll.handle, "mciGetCreatorTask");
            winmm.mciGetDeviceIDA = GetProcAddress(dll.handle, "mciGetDeviceIDA");
            winmm.mciGetDeviceIDFromElementIDA = GetProcAddress(dll.handle, "mciGetDeviceIDFromElementIDA");
            winmm.mciGetDeviceIDFromElementIDW = GetProcAddress(dll.handle, "mciGetDeviceIDFromElementIDW");
            winmm.mciGetDeviceIDW = GetProcAddress(dll.handle, "mciGetDeviceIDW");
            winmm.mciGetDriverData = GetProcAddress(dll.handle, "mciGetDriverData");
            winmm.mciGetErrorStringA = GetProcAddress(dll.handle, "mciGetErrorStringA");
            winmm.mciGetErrorStringW = GetProcAddress(dll.handle, "mciGetErrorStringW");
            winmm.mciGetYieldProc = GetProcAddress(dll.handle, "mciGetYieldProc");
            winmm.mciLoadCommandResource = GetProcAddress(dll.handle, "mciLoadCommandResource");
            winmm.mciSendCommandA = GetProcAddress(dll.handle, "mciSendCommandA");
            winmm.mciSendCommandW = GetProcAddress(dll.handle, "mciSendCommandW");
            winmm.mciSendStringA = GetProcAddress(dll.handle, "mciSendStringA");
            winmm.mciSendStringW = GetProcAddress(dll.handle, "mciSendStringW");
            winmm.mciSetDriverData = GetProcAddress(dll.handle, "mciSetDriverData");
            winmm.mciSetYieldProc = GetProcAddress(dll.handle, "mciSetYieldProc");
            winmm.mid32Message = GetProcAddress(dll.handle, "mid32Message");
            winmm.midiConnect = GetProcAddress(dll.handle, "midiConnect");
            winmm.midiDisconnect = GetProcAddress(dll.handle, "midiDisconnect");
            winmm.midiInAddBuffer = GetProcAddress(dll.handle, "midiInAddBuffer");
            winmm.midiInClose = GetProcAddress(dll.handle, "midiInClose");
            winmm.midiInGetDevCapsA = GetProcAddress(dll.handle, "midiInGetDevCapsA");
            winmm.midiInGetDevCapsW = GetProcAddress(dll.handle, "midiInGetDevCapsW");
            winmm.midiInGetErrorTextA = GetProcAddress(dll.handle, "midiInGetErrorTextA");
            winmm.midiInGetErrorTextW = GetProcAddress(dll.handle, "midiInGetErrorTextW");
            winmm.midiInGetID = GetProcAddress(dll.handle, "midiInGetID");
            winmm.midiInGetNumDevs = GetProcAddress(dll.handle, "midiInGetNumDevs");
            winmm.midiInMessage = GetProcAddress(dll.handle, "midiInMessage");
            winmm.midiInOpen = GetProcAddress(dll.handle, "midiInOpen");
            winmm.midiInPrepareHeader = GetProcAddress(dll.handle, "midiInPrepareHeader");
            winmm.midiInReset = GetProcAddress(dll.handle, "midiInReset");
            winmm.midiInStart = GetProcAddress(dll.handle, "midiInStart");
            winmm.midiInStop = GetProcAddress(dll.handle, "midiInStop");
            winmm.midiInUnprepareHeader = GetProcAddress(dll.handle, "midiInUnprepareHeader");
            winmm.midiOutCacheDrumPatches = GetProcAddress(dll.handle, "midiOutCacheDrumPatches");
            winmm.midiOutCachePatches = GetProcAddress(dll.handle, "midiOutCachePatches");
            winmm.midiOutClose = GetProcAddress(dll.handle, "midiOutClose");
            winmm.midiOutGetDevCapsA = GetProcAddress(dll.handle, "midiOutGetDevCapsA");
            winmm.midiOutGetDevCapsW = GetProcAddress(dll.handle, "midiOutGetDevCapsW");
            winmm.midiOutGetErrorTextA = GetProcAddress(dll.handle, "midiOutGetErrorTextA");
            winmm.midiOutGetErrorTextW = GetProcAddress(dll.handle, "midiOutGetErrorTextW");
            winmm.midiOutGetID = GetProcAddress(dll.handle, "midiOutGetID");
            winmm.midiOutGetNumDevs = GetProcAddress(dll.handle, "midiOutGetNumDevs");
            winmm.midiOutGetVolume = GetProcAddress(dll.handle, "midiOutGetVolume");
            winmm.midiOutLongMsg = GetProcAddress(dll.handle, "midiOutLongMsg");
            winmm.midiOutMessage = GetProcAddress(dll.handle, "midiOutMessage");
            winmm.midiOutOpen = GetProcAddress(dll.handle, "midiOutOpen");
            winmm.midiOutPrepareHeader = GetProcAddress(dll.handle, "midiOutPrepareHeader");
            winmm.midiOutReset = GetProcAddress(dll.handle, "midiOutReset");
            winmm.midiOutSetVolume = GetProcAddress(dll.handle, "midiOutSetVolume");
            winmm.midiOutShortMsg = GetProcAddress(dll.handle, "midiOutShortMsg");
            winmm.midiOutUnprepareHeader = GetProcAddress(dll.handle, "midiOutUnprepareHeader");
            winmm.midiStreamClose = GetProcAddress(dll.handle, "midiStreamClose");
            winmm.midiStreamOpen = GetProcAddress(dll.handle, "midiStreamOpen");
            winmm.midiStreamOut = GetProcAddress(dll.handle, "midiStreamOut");
            winmm.midiStreamPause = GetProcAddress(dll.handle, "midiStreamPause");
            winmm.midiStreamPosition = GetProcAddress(dll.handle, "midiStreamPosition");
            winmm.midiStreamProperty = GetProcAddress(dll.handle, "midiStreamProperty");
            winmm.midiStreamRestart = GetProcAddress(dll.handle, "midiStreamRestart");
            winmm.midiStreamStop = GetProcAddress(dll.handle, "midiStreamStop");
            winmm.mixerClose = GetProcAddress(dll.handle, "mixerClose");
            winmm.mixerGetControlDetailsA = GetProcAddress(dll.handle, "mixerGetControlDetailsA");
            winmm.mixerGetControlDetailsW = GetProcAddress(dll.handle, "mixerGetControlDetailsW");
            winmm.mixerGetDevCapsA = GetProcAddress(dll.handle, "mixerGetDevCapsA");
            winmm.mixerGetDevCapsW = GetProcAddress(dll.handle, "mixerGetDevCapsW");
            winmm.mixerGetID = GetProcAddress(dll.handle, "mixerGetID");
            winmm.mixerGetLineControlsA = GetProcAddress(dll.handle, "mixerGetLineControlsA");
            winmm.mixerGetLineControlsW = GetProcAddress(dll.handle, "mixerGetLineControlsW");
            winmm.mixerGetLineInfoA = GetProcAddress(dll.handle, "mixerGetLineInfoA");
            winmm.mixerGetLineInfoW = GetProcAddress(dll.handle, "mixerGetLineInfoW");
            winmm.mixerGetNumDevs = GetProcAddress(dll.handle, "mixerGetNumDevs");
            winmm.mixerMessage = GetProcAddress(dll.handle, "mixerMessage");
            winmm.mixerOpen = GetProcAddress(dll.handle, "mixerOpen");
            winmm.mixerSetControlDetails = GetProcAddress(dll.handle, "mixerSetControlDetails");
            winmm.mmDrvInstall = GetProcAddress(dll.handle, "mmDrvInstall");
            winmm.mmGetCurrentTask = GetProcAddress(dll.handle, "mmGetCurrentTask");
            winmm.mmTaskBlock = GetProcAddress(dll.handle, "mmTaskBlock");
            winmm.mmTaskCreate = GetProcAddress(dll.handle, "mmTaskCreate");
            winmm.mmTaskSignal = GetProcAddress(dll.handle, "mmTaskSignal");
            winmm.mmTaskYield = GetProcAddress(dll.handle, "mmTaskYield");
            winmm.mmioAdvance = GetProcAddress(dll.handle, "mmioAdvance");
            winmm.mmioAscend = GetProcAddress(dll.handle, "mmioAscend");
            winmm.mmioClose = GetProcAddress(dll.handle, "mmioClose");
            winmm.mmioCreateChunk = GetProcAddress(dll.handle, "mmioCreateChunk");
            winmm.mmioDescend = GetProcAddress(dll.handle, "mmioDescend");
            winmm.mmioFlush = GetProcAddress(dll.handle, "mmioFlush");
            winmm.mmioGetInfo = GetProcAddress(dll.handle, "mmioGetInfo");
            winmm.mmioInstallIOProcA = GetProcAddress(dll.handle, "mmioInstallIOProcA");
            winmm.mmioInstallIOProcW = GetProcAddress(dll.handle, "mmioInstallIOProcW");
            winmm.mmioOpenA = GetProcAddress(dll.handle, "mmioOpenA");
            winmm.mmioOpenW = GetProcAddress(dll.handle, "mmioOpenW");
            winmm.mmioRead = GetProcAddress(dll.handle, "mmioRead");
            winmm.mmioRenameA = GetProcAddress(dll.handle, "mmioRenameA");
            winmm.mmioRenameW = GetProcAddress(dll.handle, "mmioRenameW");
            winmm.mmioSeek = GetProcAddress(dll.handle, "mmioSeek");
            winmm.mmioSendMessage = GetProcAddress(dll.handle, "mmioSendMessage");
            winmm.mmioSetBuffer = GetProcAddress(dll.handle, "mmioSetBuffer");
            winmm.mmioSetInfo = GetProcAddress(dll.handle, "mmioSetInfo");
            winmm.mmioStringToFOURCCA = GetProcAddress(dll.handle, "mmioStringToFOURCCA");
            winmm.mmioStringToFOURCCW = GetProcAddress(dll.handle, "mmioStringToFOURCCW");
            winmm.mmioWrite = GetProcAddress(dll.handle, "mmioWrite");
            winmm.mmsystemGetVersion = GetProcAddress(dll.handle, "mmsystemGetVersion");
            winmm.mod32Message = GetProcAddress(dll.handle, "mod32Message");
            winmm.mxd32Message = GetProcAddress(dll.handle, "mxd32Message");
            winmm.sndPlaySoundA = GetProcAddress(dll.handle, "sndPlaySoundA");
            winmm.sndPlaySoundW = GetProcAddress(dll.handle, "sndPlaySoundW");
            winmm.tid32Message = GetProcAddress(dll.handle, "tid32Message");
            winmm.timeBeginPeriod = GetProcAddress(dll.handle, "timeBeginPeriod");
            winmm.timeEndPeriod = GetProcAddress(dll.handle, "timeEndPeriod");
            winmm.timeGetDevCaps = GetProcAddress(dll.handle, "timeGetDevCaps");
            winmm.timeGetSystemTime = GetProcAddress(dll.handle, "timeGetSystemTime");
            winmm.timeGetTime = GetProcAddress(dll.handle, "timeGetTime");
            winmm.timeKillEvent = GetProcAddress(dll.handle, "timeKillEvent");
            winmm.timeSetEvent = GetProcAddress(dll.handle, "timeSetEvent");
            winmm.waveInAddBuffer = GetProcAddress(dll.handle, "waveInAddBuffer");
            winmm.waveInClose = GetProcAddress(dll.handle, "waveInClose");
            winmm.waveInGetDevCapsA = GetProcAddress(dll.handle, "waveInGetDevCapsA");
            winmm.waveInGetDevCapsW = GetProcAddress(dll.handle, "waveInGetDevCapsW");
            winmm.waveInGetErrorTextA = GetProcAddress(dll.handle, "waveInGetErrorTextA");
            winmm.waveInGetErrorTextW = GetProcAddress(dll.handle, "waveInGetErrorTextW");
            winmm.waveInGetID = GetProcAddress(dll.handle, "waveInGetID");
            winmm.waveInGetNumDevs = GetProcAddress(dll.handle, "waveInGetNumDevs");
            winmm.waveInGetPosition = GetProcAddress(dll.handle, "waveInGetPosition");
            winmm.waveInMessage = GetProcAddress(dll.handle, "waveInMessage");
            winmm.waveInOpen = GetProcAddress(dll.handle, "waveInOpen");
            winmm.waveInPrepareHeader = GetProcAddress(dll.handle, "waveInPrepareHeader");
            winmm.waveInReset = GetProcAddress(dll.handle, "waveInReset");
            winmm.waveInStart = GetProcAddress(dll.handle, "waveInStart");
            winmm.waveInStop = GetProcAddress(dll.handle, "waveInStop");
            winmm.waveInUnprepareHeader = GetProcAddress(dll.handle, "waveInUnprepareHeader");
            winmm.waveOutBreakLoop = GetProcAddress(dll.handle, "waveOutBreakLoop");
            winmm.waveOutClose = GetProcAddress(dll.handle, "waveOutClose");
            winmm.waveOutGetDevCapsA = GetProcAddress(dll.handle, "waveOutGetDevCapsA");
            winmm.waveOutGetDevCapsW = GetProcAddress(dll.handle, "waveOutGetDevCapsW");
            winmm.waveOutGetErrorTextA = GetProcAddress(dll.handle, "waveOutGetErrorTextA");
            winmm.waveOutGetErrorTextW = GetProcAddress(dll.handle, "waveOutGetErrorTextW");
            winmm.waveOutGetID = GetProcAddress(dll.handle, "waveOutGetID");
            winmm.waveOutGetNumDevs = GetProcAddress(dll.handle, "waveOutGetNumDevs");
            winmm.waveOutGetPitch = GetProcAddress(dll.handle, "waveOutGetPitch");
            winmm.waveOutGetPlaybackRate = GetProcAddress(dll.handle, "waveOutGetPlaybackRate");
            winmm.waveOutGetPosition = GetProcAddress(dll.handle, "waveOutGetPosition");
            winmm.waveOutGetVolume = GetProcAddress(dll.handle, "waveOutGetVolume");
            winmm.waveOutMessage = GetProcAddress(dll.handle, "waveOutMessage");
            winmm.waveOutOpen = GetProcAddress(dll.handle, "waveOutOpen");
            winmm.waveOutPause = GetProcAddress(dll.handle, "waveOutPause");
            winmm.waveOutPrepareHeader = GetProcAddress(dll.handle, "waveOutPrepareHeader");
            winmm.waveOutReset = GetProcAddress(dll.handle, "waveOutReset");
            winmm.waveOutRestart = GetProcAddress(dll.handle, "waveOutRestart");
            winmm.waveOutSetPitch = GetProcAddress(dll.handle, "waveOutSetPitch");
            winmm.waveOutSetPlaybackRate = GetProcAddress(dll.handle, "waveOutSetPlaybackRate");
            winmm.waveOutSetVolume = GetProcAddress(dll.handle, "waveOutSetVolume");
            winmm.waveOutUnprepareHeader = GetProcAddress(dll.handle, "waveOutUnprepareHeader");
            winmm.waveOutWrite = GetProcAddress(dll.handle, "waveOutWrite");
            winmm.wid32Message = GetProcAddress(dll.handle, "wid32Message");
            winmm.wod32Message = GetProcAddress(dll.handle, "wod32Message");
        }
        else if (moduleName == L"oledlg.dll") {
            isLibraryForEditorOnly = true;
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            loadingResult = true; // always load for oledlg.dll
            oledlg.OleUIAddVerbMenuA = GetProcAddress(dll.handle, "OleUIAddVerbMenuA");
            oledlg.OleUIAddVerbMenuW = GetProcAddress(dll.handle, "OleUIAddVerbMenuW");
            oledlg.OleUIBusyA = GetProcAddress(dll.handle, "OleUIBusyA");
            oledlg.OleUIBusyW = GetProcAddress(dll.handle, "OleUIBusyW");
            oledlg.OleUICanConvertOrActivateAs = GetProcAddress(dll.handle, "OleUICanConvertOrActivateAs");
            oledlg.OleUIChangeIconA = GetProcAddress(dll.handle, "OleUIChangeIconA");
            oledlg.OleUIChangeIconW = GetProcAddress(dll.handle, "OleUIChangeIconW");
            oledlg.OleUIChangeSourceA = GetProcAddress(dll.handle, "OleUIChangeSourceA");
            oledlg.OleUIChangeSourceW = GetProcAddress(dll.handle, "OleUIChangeSourceW");
            oledlg.OleUIConvertA = GetProcAddress(dll.handle, "OleUIConvertA");
            oledlg.OleUIConvertW = GetProcAddress(dll.handle, "OleUIConvertW");
            oledlg.OleUIEditLinksA = GetProcAddress(dll.handle, "OleUIEditLinksA");
            oledlg.OleUIEditLinksW = GetProcAddress(dll.handle, "OleUIEditLinksW");
            oledlg.OleUIInsertObjectA = GetProcAddress(dll.handle, "OleUIInsertObjectA");
            oledlg.OleUIInsertObjectW = GetProcAddress(dll.handle, "OleUIInsertObjectW");
            oledlg.OleUIObjectPropertiesA = GetProcAddress(dll.handle, "OleUIObjectPropertiesA");
            oledlg.OleUIObjectPropertiesW = GetProcAddress(dll.handle, "OleUIObjectPropertiesW");
            oledlg.OleUIPasteSpecialA = GetProcAddress(dll.handle, "OleUIPasteSpecialA");
            oledlg.OleUIPasteSpecialW = GetProcAddress(dll.handle, "OleUIPasteSpecialW");
            oledlg.OleUIPromptUserA = GetProcAddress(dll.handle, "OleUIPromptUserA");
            oledlg.OleUIPromptUserW = GetProcAddress(dll.handle, "OleUIPromptUserW");
            oledlg.OleUIUpdateLinksA = GetProcAddress(dll.handle, "OleUIUpdateLinksA");
            oledlg.OleUIUpdateLinksW = GetProcAddress(dll.handle, "OleUIUpdateLinksW");
        }
        else if (moduleName == L"winspool.drv") {
            isLibraryForEditorOnly = true;
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            winspool.ADVANCEDSETUPDIALOG = GetProcAddress(dll.handle, "ADVANCEDSETUPDIALOG");
            winspool.AbortPrinter = GetProcAddress(dll.handle, "AbortPrinter");
            winspool.AddFormA = GetProcAddress(dll.handle, "AddFormA");
            winspool.AddFormW = GetProcAddress(dll.handle, "AddFormW");
            winspool.AddJobA = GetProcAddress(dll.handle, "AddJobA");
            winspool.AddJobW = GetProcAddress(dll.handle, "AddJobW");
            winspool.AddMonitorA = GetProcAddress(dll.handle, "AddMonitorA");
            winspool.AddMonitorW = GetProcAddress(dll.handle, "AddMonitorW");
            winspool.AddPortA = GetProcAddress(dll.handle, "AddPortA");
            winspool.AddPortExA = GetProcAddress(dll.handle, "AddPortExA");
            winspool.AddPortExW = GetProcAddress(dll.handle, "AddPortExW");
            winspool.AddPortW = GetProcAddress(dll.handle, "AddPortW");
            winspool.AddPrintProcessorA = GetProcAddress(dll.handle, "AddPrintProcessorA");
            winspool.AddPrintProcessorW = GetProcAddress(dll.handle, "AddPrintProcessorW");
            winspool.AddPrintProvidorA = GetProcAddress(dll.handle, "AddPrintProvidorA");
            winspool.AddPrintProvidorW = GetProcAddress(dll.handle, "AddPrintProvidorW");
            winspool.AddPrinterA = GetProcAddress(dll.handle, "AddPrinterA");
            winspool.AddPrinterConnection2A = GetProcAddress(dll.handle, "AddPrinterConnection2A");
            winspool.AddPrinterConnection2W = GetProcAddress(dll.handle, "AddPrinterConnection2W");
            winspool.AddPrinterConnectionA = GetProcAddress(dll.handle, "AddPrinterConnectionA");
            winspool.AddPrinterConnectionW = GetProcAddress(dll.handle, "AddPrinterConnectionW");
            winspool.AddPrinterDriverA = GetProcAddress(dll.handle, "AddPrinterDriverA");
            winspool.AddPrinterDriverExA = GetProcAddress(dll.handle, "AddPrinterDriverExA");
            winspool.AddPrinterDriverExW = GetProcAddress(dll.handle, "AddPrinterDriverExW");
            winspool.AddPrinterDriverW = GetProcAddress(dll.handle, "AddPrinterDriverW");
            winspool.AddPrinterW = GetProcAddress(dll.handle, "AddPrinterW");
            winspool.AdvancedDocumentPropertiesA = GetProcAddress(dll.handle, "AdvancedDocumentPropertiesA");
            winspool.AdvancedDocumentPropertiesW = GetProcAddress(dll.handle, "AdvancedDocumentPropertiesW");
            winspool.AdvancedSetupDialog = GetProcAddress(dll.handle, "AdvancedSetupDialog");
            winspool.ClosePrinter = GetProcAddress(dll.handle, "ClosePrinter");
            winspool.CloseSpoolFileHandle = GetProcAddress(dll.handle, "CloseSpoolFileHandle");
            winspool.CommitSpoolData = GetProcAddress(dll.handle, "CommitSpoolData");
            winspool.ConfigurePortA = GetProcAddress(dll.handle, "ConfigurePortA");
            winspool.ConfigurePortW = GetProcAddress(dll.handle, "ConfigurePortW");
            winspool.ConnectToPrinterDlg = GetProcAddress(dll.handle, "ConnectToPrinterDlg");
            winspool.ConvertAnsiDevModeToUnicodeDevmode = GetProcAddress(dll.handle, "ConvertAnsiDevModeToUnicodeDevmode");
            winspool.ConvertUnicodeDevModeToAnsiDevmode = GetProcAddress(dll.handle, "ConvertUnicodeDevModeToAnsiDevmode");
            winspool.CorePrinterDriverInstalledA = GetProcAddress(dll.handle, "CorePrinterDriverInstalledA");
            winspool.CorePrinterDriverInstalledW = GetProcAddress(dll.handle, "CorePrinterDriverInstalledW");
            winspool.CreatePrintAsyncNotifyChannel = GetProcAddress(dll.handle, "CreatePrintAsyncNotifyChannel");
            winspool.CreatePrinterIC = GetProcAddress(dll.handle, "CreatePrinterIC");
            winspool.DEVICECAPABILITIES = GetProcAddress(dll.handle, "DEVICECAPABILITIES");
            winspool.DEVICEMODE = GetProcAddress(dll.handle, "DEVICEMODE");
            winspool.DeleteFormA = GetProcAddress(dll.handle, "DeleteFormA");
            winspool.DeleteFormW = GetProcAddress(dll.handle, "DeleteFormW");
            winspool.DeleteJobNamedProperty = GetProcAddress(dll.handle, "DeleteJobNamedProperty");
            winspool.DeleteMonitorA = GetProcAddress(dll.handle, "DeleteMonitorA");
            winspool.DeleteMonitorW = GetProcAddress(dll.handle, "DeleteMonitorW");
            winspool.DeletePortA = GetProcAddress(dll.handle, "DeletePortA");
            winspool.DeletePortW = GetProcAddress(dll.handle, "DeletePortW");
            winspool.DeletePrintProcessorA = GetProcAddress(dll.handle, "DeletePrintProcessorA");
            winspool.DeletePrintProcessorW = GetProcAddress(dll.handle, "DeletePrintProcessorW");
            winspool.DeletePrintProvidorA = GetProcAddress(dll.handle, "DeletePrintProvidorA");
            winspool.DeletePrintProvidorW = GetProcAddress(dll.handle, "DeletePrintProvidorW");
            winspool.DeletePrinter = GetProcAddress(dll.handle, "DeletePrinter");
            winspool.DeletePrinterConnectionA = GetProcAddress(dll.handle, "DeletePrinterConnectionA");
            winspool.DeletePrinterConnectionW = GetProcAddress(dll.handle, "DeletePrinterConnectionW");
            winspool.DeletePrinterDataA = GetProcAddress(dll.handle, "DeletePrinterDataA");
            winspool.DeletePrinterDataExA = GetProcAddress(dll.handle, "DeletePrinterDataExA");
            winspool.DeletePrinterDataExW = GetProcAddress(dll.handle, "DeletePrinterDataExW");
            winspool.DeletePrinterDataW = GetProcAddress(dll.handle, "DeletePrinterDataW");
            winspool.DeletePrinterDriverA = GetProcAddress(dll.handle, "DeletePrinterDriverA");
            winspool.DeletePrinterDriverExA = GetProcAddress(dll.handle, "DeletePrinterDriverExA");
            winspool.DeletePrinterDriverExW = GetProcAddress(dll.handle, "DeletePrinterDriverExW");
            winspool.DeletePrinterDriverPackageA = GetProcAddress(dll.handle, "DeletePrinterDriverPackageA");
            winspool.DeletePrinterDriverPackageW = GetProcAddress(dll.handle, "DeletePrinterDriverPackageW");
            winspool.DeletePrinterDriverW = GetProcAddress(dll.handle, "DeletePrinterDriverW");
            winspool.DeletePrinterIC = GetProcAddress(dll.handle, "DeletePrinterIC");
            winspool.DeletePrinterKeyA = GetProcAddress(dll.handle, "DeletePrinterKeyA");
            winspool.DeletePrinterKeyW = GetProcAddress(dll.handle, "DeletePrinterKeyW");
            winspool.DevQueryPrint = GetProcAddress(dll.handle, "DevQueryPrint");
            winspool.DevQueryPrintEx = GetProcAddress(dll.handle, "DevQueryPrintEx");
            winspool.DeviceCapabilities = GetProcAddress(dll.handle, "DeviceCapabilities");
            winspool.DeviceCapabilitiesA = GetProcAddress(dll.handle, "DeviceCapabilitiesA");
            winspool.DeviceCapabilitiesW = GetProcAddress(dll.handle, "DeviceCapabilitiesW");
            winspool.DeviceMode = GetProcAddress(dll.handle, "DeviceMode");
            winspool.DevicePropertySheets = GetProcAddress(dll.handle, "DevicePropertySheets");
            winspool.DocumentEvent = GetProcAddress(dll.handle, "DocumentEvent");
            winspool.DocumentPropertiesA = GetProcAddress(dll.handle, "DocumentPropertiesA");
            winspool.DocumentPropertiesW = GetProcAddress(dll.handle, "DocumentPropertiesW");
            winspool.DocumentPropertySheets = GetProcAddress(dll.handle, "DocumentPropertySheets");
            winspool.EXTDEVICEMODE = GetProcAddress(dll.handle, "EXTDEVICEMODE");
            winspool.EndDocPrinter = GetProcAddress(dll.handle, "EndDocPrinter");
            winspool.EndPagePrinter = GetProcAddress(dll.handle, "EndPagePrinter");
            winspool.EnumFormsA = GetProcAddress(dll.handle, "EnumFormsA");
            winspool.EnumFormsW = GetProcAddress(dll.handle, "EnumFormsW");
            winspool.EnumJobNamedProperties = GetProcAddress(dll.handle, "EnumJobNamedProperties");
            winspool.EnumJobsA = GetProcAddress(dll.handle, "EnumJobsA");
            winspool.EnumJobsW = GetProcAddress(dll.handle, "EnumJobsW");
            winspool.EnumMonitorsA = GetProcAddress(dll.handle, "EnumMonitorsA");
            winspool.EnumMonitorsW = GetProcAddress(dll.handle, "EnumMonitorsW");
            winspool.EnumPortsA = GetProcAddress(dll.handle, "EnumPortsA");
            winspool.EnumPortsW = GetProcAddress(dll.handle, "EnumPortsW");
            winspool.EnumPrintProcessorDatatypesA = GetProcAddress(dll.handle, "EnumPrintProcessorDatatypesA");
            winspool.EnumPrintProcessorDatatypesW = GetProcAddress(dll.handle, "EnumPrintProcessorDatatypesW");
            winspool.EnumPrintProcessorsA = GetProcAddress(dll.handle, "EnumPrintProcessorsA");
            winspool.EnumPrintProcessorsW = GetProcAddress(dll.handle, "EnumPrintProcessorsW");
            winspool.EnumPrinterDataA = GetProcAddress(dll.handle, "EnumPrinterDataA");
            winspool.EnumPrinterDataExA = GetProcAddress(dll.handle, "EnumPrinterDataExA");
            winspool.EnumPrinterDataExW = GetProcAddress(dll.handle, "EnumPrinterDataExW");
            winspool.EnumPrinterDataW = GetProcAddress(dll.handle, "EnumPrinterDataW");
            winspool.EnumPrinterDriversA = GetProcAddress(dll.handle, "EnumPrinterDriversA");
            winspool.EnumPrinterDriversW = GetProcAddress(dll.handle, "EnumPrinterDriversW");
            winspool.EnumPrinterKeyA = GetProcAddress(dll.handle, "EnumPrinterKeyA");
            winspool.EnumPrinterKeyW = GetProcAddress(dll.handle, "EnumPrinterKeyW");
            winspool.EnumPrintersA = GetProcAddress(dll.handle, "EnumPrintersA");
            winspool.EnumPrintersW = GetProcAddress(dll.handle, "EnumPrintersW");
            winspool.ExtDeviceMode = GetProcAddress(dll.handle, "ExtDeviceMode");
            winspool.FindClosePrinterChangeNotification = GetProcAddress(dll.handle, "FindClosePrinterChangeNotification");
            winspool.FindFirstPrinterChangeNotification = GetProcAddress(dll.handle, "FindFirstPrinterChangeNotification");
            winspool.FindNextPrinterChangeNotification = GetProcAddress(dll.handle, "FindNextPrinterChangeNotification");
            winspool.FlushPrinter = GetProcAddress(dll.handle, "FlushPrinter");
            winspool.FreePrintNamedPropertyArray = GetProcAddress(dll.handle, "FreePrintNamedPropertyArray");
            winspool.FreePrintPropertyValue = GetProcAddress(dll.handle, "FreePrintPropertyValue");
            winspool.FreePrinterNotifyInfo = GetProcAddress(dll.handle, "FreePrinterNotifyInfo");
            winspool.GetCorePrinterDriversA = GetProcAddress(dll.handle, "GetCorePrinterDriversA");
            winspool.GetCorePrinterDriversW = GetProcAddress(dll.handle, "GetCorePrinterDriversW");
            winspool.GetDefaultPrinterA = GetProcAddress(dll.handle, "GetDefaultPrinterA");
            winspool.GetDefaultPrinterW = GetProcAddress(dll.handle, "GetDefaultPrinterW");
            winspool.GetFormA = GetProcAddress(dll.handle, "GetFormA");
            winspool.GetFormW = GetProcAddress(dll.handle, "GetFormW");
            winspool.GetJobA = GetProcAddress(dll.handle, "GetJobA");
            winspool.GetJobNamedPropertyValue = GetProcAddress(dll.handle, "GetJobNamedPropertyValue");
            winspool.GetJobW = GetProcAddress(dll.handle, "GetJobW");
            winspool.GetPrintExecutionData = GetProcAddress(dll.handle, "GetPrintExecutionData");
            winspool.GetPrintOutputInfo = GetProcAddress(dll.handle, "GetPrintOutputInfo");
            winspool.GetPrintProcessorDirectoryA = GetProcAddress(dll.handle, "GetPrintProcessorDirectoryA");
            winspool.GetPrintProcessorDirectoryW = GetProcAddress(dll.handle, "GetPrintProcessorDirectoryW");
            winspool.GetPrinterA = GetProcAddress(dll.handle, "GetPrinterA");
            winspool.GetPrinterDataA = GetProcAddress(dll.handle, "GetPrinterDataA");
            winspool.GetPrinterDataExA = GetProcAddress(dll.handle, "GetPrinterDataExA");
            winspool.GetPrinterDataExW = GetProcAddress(dll.handle, "GetPrinterDataExW");
            winspool.GetPrinterDataW = GetProcAddress(dll.handle, "GetPrinterDataW");
            winspool.GetPrinterDriver2A = GetProcAddress(dll.handle, "GetPrinterDriver2A");
            winspool.GetPrinterDriver2W = GetProcAddress(dll.handle, "GetPrinterDriver2W");
            winspool.GetPrinterDriverA = GetProcAddress(dll.handle, "GetPrinterDriverA");
            winspool.GetPrinterDriverDirectoryA = GetProcAddress(dll.handle, "GetPrinterDriverDirectoryA");
            winspool.GetPrinterDriverDirectoryW = GetProcAddress(dll.handle, "GetPrinterDriverDirectoryW");
            winspool.GetPrinterDriverPackagePathA = GetProcAddress(dll.handle, "GetPrinterDriverPackagePathA");
            winspool.GetPrinterDriverPackagePathW = GetProcAddress(dll.handle, "GetPrinterDriverPackagePathW");
            winspool.GetPrinterDriverW = GetProcAddress(dll.handle, "GetPrinterDriverW");
            winspool.GetPrinterW = GetProcAddress(dll.handle, "GetPrinterW");
            winspool.GetSpoolFileHandle = GetProcAddress(dll.handle, "GetSpoolFileHandle");
            winspool.InstallPrinterDriverFromPackageA = GetProcAddress(dll.handle, "InstallPrinterDriverFromPackageA");
            winspool.InstallPrinterDriverFromPackageW = GetProcAddress(dll.handle, "InstallPrinterDriverFromPackageW");
            winspool.IsValidDevmodeA = GetProcAddress(dll.handle, "IsValidDevmodeA");
            winspool.IsValidDevmodeW = GetProcAddress(dll.handle, "IsValidDevmodeW");
            winspool.OpenPrinter2A = GetProcAddress(dll.handle, "OpenPrinter2A");
            winspool.OpenPrinter2W = GetProcAddress(dll.handle, "OpenPrinter2W");
            winspool.OpenPrinterA = GetProcAddress(dll.handle, "OpenPrinterA");
            winspool.OpenPrinterW = GetProcAddress(dll.handle, "OpenPrinterW");
            winspool.PerfClose = GetProcAddress(dll.handle, "PerfClose");
            winspool.PerfCollect = GetProcAddress(dll.handle, "PerfCollect");
            winspool.PerfOpen = GetProcAddress(dll.handle, "PerfOpen");
            winspool.PlayGdiScriptOnPrinterIC = GetProcAddress(dll.handle, "PlayGdiScriptOnPrinterIC");
            winspool.PrinterMessageBoxA = GetProcAddress(dll.handle, "PrinterMessageBoxA");
            winspool.PrinterMessageBoxW = GetProcAddress(dll.handle, "PrinterMessageBoxW");
            winspool.PrinterProperties = GetProcAddress(dll.handle, "PrinterProperties");
            winspool.QueryColorProfile = GetProcAddress(dll.handle, "QueryColorProfile");
            winspool.QueryRemoteFonts = GetProcAddress(dll.handle, "QueryRemoteFonts");
            winspool.QuerySpoolMode = GetProcAddress(dll.handle, "QuerySpoolMode");
            winspool.ReadPrinter = GetProcAddress(dll.handle, "ReadPrinter");
            winspool.RegisterForPrintAsyncNotifications = GetProcAddress(dll.handle, "RegisterForPrintAsyncNotifications");
            winspool.ReportJobProcessingProgress = GetProcAddress(dll.handle, "ReportJobProcessingProgress");
            winspool.ResetPrinterA = GetProcAddress(dll.handle, "ResetPrinterA");
            winspool.ResetPrinterW = GetProcAddress(dll.handle, "ResetPrinterW");
            winspool.ScheduleJob = GetProcAddress(dll.handle, "ScheduleJob");
            winspool.SeekPrinter = GetProcAddress(dll.handle, "SeekPrinter");
            winspool.SetDefaultPrinterA = GetProcAddress(dll.handle, "SetDefaultPrinterA");
            winspool.SetDefaultPrinterW = GetProcAddress(dll.handle, "SetDefaultPrinterW");
            winspool.SetFormA = GetProcAddress(dll.handle, "SetFormA");
            winspool.SetFormW = GetProcAddress(dll.handle, "SetFormW");
            winspool.SetJobA = GetProcAddress(dll.handle, "SetJobA");
            winspool.SetJobNamedProperty = GetProcAddress(dll.handle, "SetJobNamedProperty");
            winspool.SetJobW = GetProcAddress(dll.handle, "SetJobW");
            winspool.SetPortA = GetProcAddress(dll.handle, "SetPortA");
            winspool.SetPortW = GetProcAddress(dll.handle, "SetPortW");
            winspool.SetPrinterA = GetProcAddress(dll.handle, "SetPrinterA");
            winspool.SetPrinterDataA = GetProcAddress(dll.handle, "SetPrinterDataA");
            winspool.SetPrinterDataExA = GetProcAddress(dll.handle, "SetPrinterDataExA");
            winspool.SetPrinterDataExW = GetProcAddress(dll.handle, "SetPrinterDataExW");
            winspool.SetPrinterDataW = GetProcAddress(dll.handle, "SetPrinterDataW");
            winspool.SetPrinterW = GetProcAddress(dll.handle, "SetPrinterW");
            winspool.SplDriverUnloadComplete = GetProcAddress(dll.handle, "SplDriverUnloadComplete");
            winspool.SpoolerDevQueryPrintW = GetProcAddress(dll.handle, "SpoolerDevQueryPrintW");
            winspool.SpoolerPrinterEvent = GetProcAddress(dll.handle, "SpoolerPrinterEvent");
            winspool.StartDocDlgA = GetProcAddress(dll.handle, "StartDocDlgA");
            winspool.StartDocDlgW = GetProcAddress(dll.handle, "StartDocDlgW");
            winspool.StartDocPrinterA = GetProcAddress(dll.handle, "StartDocPrinterA");
            winspool.StartDocPrinterW = GetProcAddress(dll.handle, "StartDocPrinterW");
            winspool.StartPagePrinter = GetProcAddress(dll.handle, "StartPagePrinter");
            winspool.UnRegisterForPrintAsyncNotifications = GetProcAddress(dll.handle, "UnRegisterForPrintAsyncNotifications");
            winspool.UploadPrinterDriverPackageA = GetProcAddress(dll.handle, "UploadPrinterDriverPackageA");
            winspool.UploadPrinterDriverPackageW = GetProcAddress(dll.handle, "UploadPrinterDriverPackageW");
            winspool.WaitForPrinterChange = GetProcAddress(dll.handle, "WaitForPrinterChange");
            winspool.WritePrinter = GetProcAddress(dll.handle, "WritePrinter");
            winspool.XcvDataW = GetProcAddress(dll.handle, "XcvDataW");
        }
        else if (moduleName == L"version.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            version.GetFileVersionInfoA = GetProcAddress(dll.handle, "GetFileVersionInfoA");
            version.GetFileVersionInfoByHandle = GetProcAddress(dll.handle, "GetFileVersionInfoByHandle");
            version.GetFileVersionInfoExA = GetProcAddress(dll.handle, "GetFileVersionInfoExA");
            version.GetFileVersionInfoExW = GetProcAddress(dll.handle, "GetFileVersionInfoExW");
            version.GetFileVersionInfoSizeA = GetProcAddress(dll.handle, "GetFileVersionInfoSizeA");
            version.GetFileVersionInfoSizeExA = GetProcAddress(dll.handle, "GetFileVersionInfoSizeExA");
            version.GetFileVersionInfoSizeExW = GetProcAddress(dll.handle, "GetFileVersionInfoSizeExW");
            version.GetFileVersionInfoSizeW = GetProcAddress(dll.handle, "GetFileVersionInfoSizeW");
            version.GetFileVersionInfoW = GetProcAddress(dll.handle, "GetFileVersionInfoW");
            version.VerFindFileA = GetProcAddress(dll.handle, "VerFindFileA");
            version.VerFindFileW = GetProcAddress(dll.handle, "VerFindFileW");
            version.VerInstallFileA = GetProcAddress(dll.handle, "VerInstallFileA");
            version.VerInstallFileW = GetProcAddress(dll.handle, "VerInstallFileW");
            version.VerLanguageNameA = GetProcAddress(dll.handle, "VerLanguageNameA");
            version.VerLanguageNameW = GetProcAddress(dll.handle, "VerLanguageNameW");
            version.VerQueryValueA = GetProcAddress(dll.handle, "VerQueryValueA");
            version.VerQueryValueW = GetProcAddress(dll.handle, "VerQueryValueW");
        }
        else if (moduleName == L"davhlpr.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            davhlpr.DavAddConnection = GetProcAddress(dll.handle, "DavAddConnection");
            davhlpr.DavCheckAndConvertHttpUrlToUncName = GetProcAddress(dll.handle, "DavCheckAndConvertHttpUrlToUncName");
            davhlpr.DavDeleteConnection = GetProcAddress(dll.handle, "DavDeleteConnection");
            davhlpr.DavFlushFile = GetProcAddress(dll.handle, "DavFlushFile");
            davhlpr.DavGetExtendedError = GetProcAddress(dll.handle, "DavGetExtendedError");
            davhlpr.DavGetHTTPFromUNCPath = GetProcAddress(dll.handle, "DavGetHTTPFromUNCPath");
            davhlpr.DavGetUNCFromHTTPPath = GetProcAddress(dll.handle, "DavGetUNCFromHTTPPath");
            davhlpr.DavParseUncServerName = GetProcAddress(dll.handle, "DavParseUncServerName");
            davhlpr.DavRemoveDummyShareFromFileName = GetProcAddress(dll.handle, "DavRemoveDummyShareFromFileName");
            davhlpr.DavRemoveDummyShareFromFileNameEx = GetProcAddress(dll.handle, "DavRemoveDummyShareFromFileNameEx");
            davhlpr.DavUrlDecodeToNtPath = GetProcAddress(dll.handle, "DavUrlDecodeToNtPath");
            davhlpr.DavUrlDecodeUtf8 = GetProcAddress(dll.handle, "DavUrlDecodeUtf8");
            davhlpr.DavUrlEncodeNtPath = GetProcAddress(dll.handle, "DavUrlEncodeNtPath");
        }
        else if (moduleName == L"msimg32.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            msimg32.AlphaBlend = GetProcAddress(dll.handle, "AlphaBlend");
            msimg32.DllInitialize = GetProcAddress(dll.handle, "DllInitialize");
            msimg32.GradientFill = GetProcAddress(dll.handle, "GradientFill");
            msimg32.TransparentBlt = GetProcAddress(dll.handle, "TransparentBlt");
            msimg32.vSetDdrawflag = GetProcAddress(dll.handle, "vSetDdrawflag");
        }
        else if (moduleName == L"msvfw32.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            msvfw32.DrawDibBegin = GetProcAddress(dll.handle, "DrawDibBegin");
            msvfw32.DrawDibChangePalette = GetProcAddress(dll.handle, "DrawDibChangePalette");
            msvfw32.DrawDibClose = GetProcAddress(dll.handle, "DrawDibClose");
            msvfw32.DrawDibDraw = GetProcAddress(dll.handle, "DrawDibDraw");
            msvfw32.DrawDibEnd = GetProcAddress(dll.handle, "DrawDibEnd");
            msvfw32.DrawDibGetBuffer = GetProcAddress(dll.handle, "DrawDibGetBuffer");
            msvfw32.DrawDibGetPalette = GetProcAddress(dll.handle, "DrawDibGetPalette");
            msvfw32.DrawDibOpen = GetProcAddress(dll.handle, "DrawDibOpen");
            msvfw32.DrawDibProfileDisplay = GetProcAddress(dll.handle, "DrawDibProfileDisplay");
            msvfw32.DrawDibRealize = GetProcAddress(dll.handle, "DrawDibRealize");
            msvfw32.DrawDibSetPalette = GetProcAddress(dll.handle, "DrawDibSetPalette");
            msvfw32.DrawDibStart = GetProcAddress(dll.handle, "DrawDibStart");
            msvfw32.DrawDibStop = GetProcAddress(dll.handle, "DrawDibStop");
            msvfw32.DrawDibTime = GetProcAddress(dll.handle, "DrawDibTime");
            msvfw32.GetOpenFileNamePreview = GetProcAddress(dll.handle, "GetOpenFileNamePreview");
            msvfw32.GetOpenFileNamePreviewA = GetProcAddress(dll.handle, "GetOpenFileNamePreviewA");
            msvfw32.GetOpenFileNamePreviewW = GetProcAddress(dll.handle, "GetOpenFileNamePreviewW");
            msvfw32.GetSaveFileNamePreviewA = GetProcAddress(dll.handle, "GetSaveFileNamePreviewA");
            msvfw32.GetSaveFileNamePreviewW = GetProcAddress(dll.handle, "GetSaveFileNamePreviewW");
            msvfw32.ICClose = GetProcAddress(dll.handle, "ICClose");
            msvfw32.ICCompress = GetProcAddress(dll.handle, "ICCompress");
            msvfw32.ICCompressorChoose = GetProcAddress(dll.handle, "ICCompressorChoose");
            msvfw32.ICCompressorFree = GetProcAddress(dll.handle, "ICCompressorFree");
            msvfw32.ICDecompress = GetProcAddress(dll.handle, "ICDecompress");
            msvfw32.ICDraw = GetProcAddress(dll.handle, "ICDraw");
            msvfw32.ICDrawBegin = GetProcAddress(dll.handle, "ICDrawBegin");
            msvfw32.ICGetDisplayFormat = GetProcAddress(dll.handle, "ICGetDisplayFormat");
            msvfw32.ICGetInfo = GetProcAddress(dll.handle, "ICGetInfo");
            msvfw32.ICImageCompress = GetProcAddress(dll.handle, "ICImageCompress");
            msvfw32.ICImageDecompress = GetProcAddress(dll.handle, "ICImageDecompress");
            msvfw32.ICInfo = GetProcAddress(dll.handle, "ICInfo");
            msvfw32.ICInstall = GetProcAddress(dll.handle, "ICInstall");
            msvfw32.ICLocate = GetProcAddress(dll.handle, "ICLocate");
            msvfw32.ICMThunk32 = GetProcAddress(dll.handle, "ICMThunk32");
            msvfw32.ICOpen = GetProcAddress(dll.handle, "ICOpen");
            msvfw32.ICOpenFunction = GetProcAddress(dll.handle, "ICOpenFunction");
            msvfw32.ICRemove = GetProcAddress(dll.handle, "ICRemove");
            msvfw32.ICSendMessage = GetProcAddress(dll.handle, "ICSendMessage");
            msvfw32.ICSeqCompressFrame = GetProcAddress(dll.handle, "ICSeqCompressFrame");
            msvfw32.ICSeqCompressFrameEnd = GetProcAddress(dll.handle, "ICSeqCompressFrameEnd");
            msvfw32.ICSeqCompressFrameStart = GetProcAddress(dll.handle, "ICSeqCompressFrameStart");
            msvfw32.MCIWndCreate = GetProcAddress(dll.handle, "MCIWndCreate");
            msvfw32.MCIWndCreateA = GetProcAddress(dll.handle, "MCIWndCreateA");
            msvfw32.MCIWndCreateW = GetProcAddress(dll.handle, "MCIWndCreateW");
            msvfw32.MCIWndRegisterClass = GetProcAddress(dll.handle, "MCIWndRegisterClass");
            msvfw32.StretchDIB = GetProcAddress(dll.handle, "StretchDIB");
            msvfw32.VideoForWindowsVersion = GetProcAddress(dll.handle, "VideoForWindowsVersion");
        }
        else if (moduleName == L"wsock32.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            wsock32.AcceptEx = GetProcAddress(dll.handle, "AcceptEx");
            wsock32.EnumProtocolsA = GetProcAddress(dll.handle, "EnumProtocolsA");
            wsock32.EnumProtocolsW = GetProcAddress(dll.handle, "EnumProtocolsW");
            wsock32.GetAcceptExSockaddrs = GetProcAddress(dll.handle, "GetAcceptExSockaddrs");
            wsock32.GetAddressByNameA = GetProcAddress(dll.handle, "GetAddressByNameA");
            wsock32.GetAddressByNameW = GetProcAddress(dll.handle, "GetAddressByNameW");
            wsock32.GetNameByTypeA = GetProcAddress(dll.handle, "GetNameByTypeA");
            wsock32.GetNameByTypeW = GetProcAddress(dll.handle, "GetNameByTypeW");
            wsock32.GetServiceA = GetProcAddress(dll.handle, "GetServiceA");
            wsock32.GetServiceW = GetProcAddress(dll.handle, "GetServiceW");
            wsock32.GetTypeByNameA = GetProcAddress(dll.handle, "GetTypeByNameA");
            wsock32.GetTypeByNameW = GetProcAddress(dll.handle, "GetTypeByNameW");
            wsock32.MigrateWinsockConfiguration = GetProcAddress(dll.handle, "MigrateWinsockConfiguration");
            wsock32.NPLoadNameSpaces = GetProcAddress(dll.handle, "NPLoadNameSpaces");
            wsock32.SetServiceA = GetProcAddress(dll.handle, "SetServiceA");
            wsock32.SetServiceW = GetProcAddress(dll.handle, "SetServiceW");
            wsock32.TransmitFile = GetProcAddress(dll.handle, "TransmitFile");
            wsock32.WEP = GetProcAddress(dll.handle, "WEP");
            wsock32.WSAAsyncGetHostByAddr = GetProcAddress(dll.handle, "WSAAsyncGetHostByAddr");
            wsock32.WSAAsyncGetHostByName = GetProcAddress(dll.handle, "WSAAsyncGetHostByName");
            wsock32.WSAAsyncGetProtoByName = GetProcAddress(dll.handle, "WSAAsyncGetProtoByName");
            wsock32.WSAAsyncGetProtoByNumber = GetProcAddress(dll.handle, "WSAAsyncGetProtoByNumber");
            wsock32.WSAAsyncGetServByName = GetProcAddress(dll.handle, "WSAAsyncGetServByName");
            wsock32.WSAAsyncGetServByPort = GetProcAddress(dll.handle, "WSAAsyncGetServByPort");
            wsock32.WSAAsyncSelect = GetProcAddress(dll.handle, "WSAAsyncSelect");
            wsock32.WSACancelAsyncRequest = GetProcAddress(dll.handle, "WSACancelAsyncRequest");
            wsock32.WSACancelBlockingCall = GetProcAddress(dll.handle, "WSACancelBlockingCall");
            wsock32.WSACleanup = GetProcAddress(dll.handle, "WSACleanup");
            wsock32.WSAGetLastError = GetProcAddress(dll.handle, "WSAGetLastError");
            wsock32.WSAIsBlocking = GetProcAddress(dll.handle, "WSAIsBlocking");
            wsock32.WSARecvEx = GetProcAddress(dll.handle, "WSARecvEx");
            wsock32.WSASetBlockingHook = GetProcAddress(dll.handle, "WSASetBlockingHook");
            wsock32.WSASetLastError = GetProcAddress(dll.handle, "WSASetLastError");
            wsock32.WSAStartup = GetProcAddress(dll.handle, "WSAStartup");
            wsock32.WSAUnhookBlockingHook = GetProcAddress(dll.handle, "WSAUnhookBlockingHook");
            wsock32.WSApSetPostRoutine = GetProcAddress(dll.handle, "WSApSetPostRoutine");
            wsock32.__WSAFDIsSet = GetProcAddress(dll.handle, "__WSAFDIsSet");
            wsock32.accept = GetProcAddress(dll.handle, "accept");
            wsock32.bind = GetProcAddress(dll.handle, "bind");
            wsock32.closesocket = GetProcAddress(dll.handle, "closesocket");
            wsock32.connect = GetProcAddress(dll.handle, "connect");
            wsock32.dn_expand = GetProcAddress(dll.handle, "dn_expand");
            wsock32.gethostbyaddr = GetProcAddress(dll.handle, "gethostbyaddr");
            wsock32.gethostbyname = GetProcAddress(dll.handle, "gethostbyname");
            wsock32.gethostname = GetProcAddress(dll.handle, "gethostname");
            wsock32.getnetbyname = GetProcAddress(dll.handle, "getnetbyname");
            wsock32.getpeername = GetProcAddress(dll.handle, "getpeername");
            wsock32.getprotobyname = GetProcAddress(dll.handle, "getprotobyname");
            wsock32.getprotobynumber = GetProcAddress(dll.handle, "getprotobynumber");
            wsock32.getservbyname = GetProcAddress(dll.handle, "getservbyname");
            wsock32.getservbyport = GetProcAddress(dll.handle, "getservbyport");
            wsock32.getsockname = GetProcAddress(dll.handle, "getsockname");
            wsock32.getsockopt = GetProcAddress(dll.handle, "getsockopt");
            wsock32.htonl = GetProcAddress(dll.handle, "htonl");
            wsock32.htons = GetProcAddress(dll.handle, "htons");
            wsock32.inet_addr = GetProcAddress(dll.handle, "inet_addr");
            wsock32.inet_network = GetProcAddress(dll.handle, "inet_network");
            wsock32.inet_ntoa = GetProcAddress(dll.handle, "inet_ntoa");
            wsock32.ioctlsocket = GetProcAddress(dll.handle, "ioctlsocket");
            wsock32.listen = GetProcAddress(dll.handle, "listen");
            wsock32.ntohl = GetProcAddress(dll.handle, "ntohl");
            wsock32.ntohs = GetProcAddress(dll.handle, "ntohs");
            wsock32.rcmd = GetProcAddress(dll.handle, "rcmd");
            wsock32.recv = GetProcAddress(dll.handle, "recv");
            wsock32.recvfrom = GetProcAddress(dll.handle, "recvfrom");
            wsock32.rexec = GetProcAddress(dll.handle, "rexec");
            wsock32.rresvport = GetProcAddress(dll.handle, "rresvport");
            wsock32.s_perror = GetProcAddress(dll.handle, "s_perror");
            wsock32.select = GetProcAddress(dll.handle, "select");
            wsock32.send = GetProcAddress(dll.handle, "send");
            wsock32.sendto = GetProcAddress(dll.handle, "sendto");
            wsock32.sethostname = GetProcAddress(dll.handle, "sethostname");
            wsock32.setsockopt = GetProcAddress(dll.handle, "setsockopt");
            wsock32.shutdown = GetProcAddress(dll.handle, "shutdown");
            wsock32.socket = GetProcAddress(dll.handle, "socket");
        }
        else if (moduleName == L"dbghelp.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            dbghelp.DbgHelpCreateUserDump = GetProcAddress(dll.handle, "DbgHelpCreateUserDump");
            dbghelp.DbgHelpCreateUserDumpW = GetProcAddress(dll.handle, "DbgHelpCreateUserDumpW");
            dbghelp.EnumDirTree = GetProcAddress(dll.handle, "EnumDirTree");
            dbghelp.EnumDirTreeW = GetProcAddress(dll.handle, "EnumDirTreeW");
            dbghelp.EnumerateLoadedModules = GetProcAddress(dll.handle, "EnumerateLoadedModules");
            dbghelp.EnumerateLoadedModules64 = GetProcAddress(dll.handle, "EnumerateLoadedModules64");
            dbghelp.EnumerateLoadedModulesEx = GetProcAddress(dll.handle, "EnumerateLoadedModulesEx");
            dbghelp.EnumerateLoadedModulesExW = GetProcAddress(dll.handle, "EnumerateLoadedModulesExW");
            dbghelp.EnumerateLoadedModulesW64 = GetProcAddress(dll.handle, "EnumerateLoadedModulesW64");
            dbghelp.ExtensionApiVersion = GetProcAddress(dll.handle, "ExtensionApiVersion");
            dbghelp.FindDebugInfoFile = GetProcAddress(dll.handle, "FindDebugInfoFile");
            dbghelp.FindDebugInfoFileEx = GetProcAddress(dll.handle, "FindDebugInfoFileEx");
            dbghelp.FindDebugInfoFileExW = GetProcAddress(dll.handle, "FindDebugInfoFileExW");
            dbghelp.FindExecutableImage = GetProcAddress(dll.handle, "FindExecutableImage");
            dbghelp.FindExecutableImageEx = GetProcAddress(dll.handle, "FindExecutableImageEx");
            dbghelp.FindExecutableImageExW = GetProcAddress(dll.handle, "FindExecutableImageExW");
            dbghelp.FindFileInPath = GetProcAddress(dll.handle, "FindFileInPath");
            dbghelp.FindFileInSearchPath = GetProcAddress(dll.handle, "FindFileInSearchPath");
            dbghelp.GetTimestampForLoadedLibrary = GetProcAddress(dll.handle, "GetTimestampForLoadedLibrary");
            dbghelp.ImageDirectoryEntryToData = GetProcAddress(dll.handle, "ImageDirectoryEntryToData");
            dbghelp.ImageDirectoryEntryToDataEx = GetProcAddress(dll.handle, "ImageDirectoryEntryToDataEx");
            dbghelp.ImageNtHeader = GetProcAddress(dll.handle, "ImageNtHeader");
            dbghelp.ImageRvaToSection = GetProcAddress(dll.handle, "ImageRvaToSection");
            dbghelp.ImageRvaToVa = GetProcAddress(dll.handle, "ImageRvaToVa");
            dbghelp.ImagehlpApiVersion = GetProcAddress(dll.handle, "ImagehlpApiVersion");
            dbghelp.ImagehlpApiVersionEx = GetProcAddress(dll.handle, "ImagehlpApiVersionEx");
            dbghelp.MakeSureDirectoryPathExists = GetProcAddress(dll.handle, "MakeSureDirectoryPathExists");
            dbghelp.MiniDumpReadDumpStream = GetProcAddress(dll.handle, "MiniDumpReadDumpStream");
            dbghelp.MiniDumpWriteDump = GetProcAddress(dll.handle, "MiniDumpWriteDump");
            dbghelp.SearchTreeForFile = GetProcAddress(dll.handle, "SearchTreeForFile");
            dbghelp.SearchTreeForFileW = GetProcAddress(dll.handle, "SearchTreeForFileW");
            dbghelp.StackWalk = GetProcAddress(dll.handle, "StackWalk");
            dbghelp.StackWalk64 = GetProcAddress(dll.handle, "StackWalk64");
            dbghelp.SymAddSourceStream = GetProcAddress(dll.handle, "SymAddSourceStream");
            dbghelp.SymAddSourceStreamA = GetProcAddress(dll.handle, "SymAddSourceStreamA");
            dbghelp.SymAddSourceStreamW = GetProcAddress(dll.handle, "SymAddSourceStreamW");
            dbghelp.SymAddSymbol = GetProcAddress(dll.handle, "SymAddSymbol");
            dbghelp.SymAddSymbolW = GetProcAddress(dll.handle, "SymAddSymbolW");
            dbghelp.SymCleanup = GetProcAddress(dll.handle, "SymCleanup");
            dbghelp.SymDeleteSymbol = GetProcAddress(dll.handle, "SymDeleteSymbol");
            dbghelp.SymDeleteSymbolW = GetProcAddress(dll.handle, "SymDeleteSymbolW");
            dbghelp.SymEnumLines = GetProcAddress(dll.handle, "SymEnumLines");
            dbghelp.SymEnumLinesW = GetProcAddress(dll.handle, "SymEnumLinesW");
            dbghelp.SymEnumProcesses = GetProcAddress(dll.handle, "SymEnumProcesses");
            dbghelp.SymEnumSourceFileTokens = GetProcAddress(dll.handle, "SymEnumSourceFileTokens");
            dbghelp.SymEnumSourceFiles = GetProcAddress(dll.handle, "SymEnumSourceFiles");
            dbghelp.SymEnumSourceFilesW = GetProcAddress(dll.handle, "SymEnumSourceFilesW");
            dbghelp.SymEnumSourceLines = GetProcAddress(dll.handle, "SymEnumSourceLines");
            dbghelp.SymEnumSourceLinesW = GetProcAddress(dll.handle, "SymEnumSourceLinesW");
            dbghelp.SymEnumSym = GetProcAddress(dll.handle, "SymEnumSym");
            dbghelp.SymEnumSymbols = GetProcAddress(dll.handle, "SymEnumSymbols");
            dbghelp.SymEnumSymbolsForAddr = GetProcAddress(dll.handle, "SymEnumSymbolsForAddr");
            dbghelp.SymEnumSymbolsForAddrW = GetProcAddress(dll.handle, "SymEnumSymbolsForAddrW");
            dbghelp.SymEnumSymbolsW = GetProcAddress(dll.handle, "SymEnumSymbolsW");
            dbghelp.SymEnumTypes = GetProcAddress(dll.handle, "SymEnumTypes");
            dbghelp.SymEnumTypesByName = GetProcAddress(dll.handle, "SymEnumTypesByName");
            dbghelp.SymEnumTypesByNameW = GetProcAddress(dll.handle, "SymEnumTypesByNameW");
            dbghelp.SymEnumTypesW = GetProcAddress(dll.handle, "SymEnumTypesW");
            dbghelp.SymEnumerateModules = GetProcAddress(dll.handle, "SymEnumerateModules");
            dbghelp.SymEnumerateModules64 = GetProcAddress(dll.handle, "SymEnumerateModules64");
            dbghelp.SymEnumerateModulesW64 = GetProcAddress(dll.handle, "SymEnumerateModulesW64");
            dbghelp.SymEnumerateSymbols = GetProcAddress(dll.handle, "SymEnumerateSymbols");
            dbghelp.SymEnumerateSymbols64 = GetProcAddress(dll.handle, "SymEnumerateSymbols64");
            dbghelp.SymEnumerateSymbolsW = GetProcAddress(dll.handle, "SymEnumerateSymbolsW");
            dbghelp.SymEnumerateSymbolsW64 = GetProcAddress(dll.handle, "SymEnumerateSymbolsW64");
            dbghelp.SymFindDebugInfoFile = GetProcAddress(dll.handle, "SymFindDebugInfoFile");
            dbghelp.SymFindDebugInfoFileW = GetProcAddress(dll.handle, "SymFindDebugInfoFileW");
            dbghelp.SymFindExecutableImage = GetProcAddress(dll.handle, "SymFindExecutableImage");
            dbghelp.SymFindExecutableImageW = GetProcAddress(dll.handle, "SymFindExecutableImageW");
            dbghelp.SymFindFileInPath = GetProcAddress(dll.handle, "SymFindFileInPath");
            dbghelp.SymFindFileInPathW = GetProcAddress(dll.handle, "SymFindFileInPathW");
            dbghelp.SymFromAddr = GetProcAddress(dll.handle, "SymFromAddr");
            dbghelp.SymFromAddrW = GetProcAddress(dll.handle, "SymFromAddrW");
            dbghelp.SymFromIndex = GetProcAddress(dll.handle, "SymFromIndex");
            dbghelp.SymFromIndexW = GetProcAddress(dll.handle, "SymFromIndexW");
            dbghelp.SymFromName = GetProcAddress(dll.handle, "SymFromName");
            dbghelp.SymFromNameW = GetProcAddress(dll.handle, "SymFromNameW");
            dbghelp.SymFromToken = GetProcAddress(dll.handle, "SymFromToken");
            dbghelp.SymFromTokenW = GetProcAddress(dll.handle, "SymFromTokenW");
            dbghelp.SymFunctionTableAccess = GetProcAddress(dll.handle, "SymFunctionTableAccess");
            dbghelp.SymFunctionTableAccess64 = GetProcAddress(dll.handle, "SymFunctionTableAccess64");
            dbghelp.SymGetFileLineOffsets64 = GetProcAddress(dll.handle, "SymGetFileLineOffsets64");
            dbghelp.SymGetHomeDirectory = GetProcAddress(dll.handle, "SymGetHomeDirectory");
            dbghelp.SymGetHomeDirectoryW = GetProcAddress(dll.handle, "SymGetHomeDirectoryW");
            dbghelp.SymGetLineFromAddr = GetProcAddress(dll.handle, "SymGetLineFromAddr");
            dbghelp.SymGetLineFromAddr64 = GetProcAddress(dll.handle, "SymGetLineFromAddr64");
            dbghelp.SymGetLineFromAddrW64 = GetProcAddress(dll.handle, "SymGetLineFromAddrW64");
            dbghelp.SymGetLineFromName = GetProcAddress(dll.handle, "SymGetLineFromName");
            dbghelp.SymGetLineFromName64 = GetProcAddress(dll.handle, "SymGetLineFromName64");
            dbghelp.SymGetLineFromNameW64 = GetProcAddress(dll.handle, "SymGetLineFromNameW64");
            dbghelp.SymGetLineNext = GetProcAddress(dll.handle, "SymGetLineNext");
            dbghelp.SymGetLineNext64 = GetProcAddress(dll.handle, "SymGetLineNext64");
            dbghelp.SymGetLineNextW64 = GetProcAddress(dll.handle, "SymGetLineNextW64");
            dbghelp.SymGetLinePrev = GetProcAddress(dll.handle, "SymGetLinePrev");
            dbghelp.SymGetLinePrev64 = GetProcAddress(dll.handle, "SymGetLinePrev64");
            dbghelp.SymGetLinePrevW64 = GetProcAddress(dll.handle, "SymGetLinePrevW64");
            dbghelp.SymGetModuleBase = GetProcAddress(dll.handle, "SymGetModuleBase");
            dbghelp.SymGetModuleBase64 = GetProcAddress(dll.handle, "SymGetModuleBase64");
            dbghelp.SymGetModuleInfo = GetProcAddress(dll.handle, "SymGetModuleInfo");
            dbghelp.SymGetModuleInfo64 = GetProcAddress(dll.handle, "SymGetModuleInfo64");
            dbghelp.SymGetModuleInfoW = GetProcAddress(dll.handle, "SymGetModuleInfoW");
            dbghelp.SymGetModuleInfoW64 = GetProcAddress(dll.handle, "SymGetModuleInfoW64");
            dbghelp.SymGetOmapBlockBase = GetProcAddress(dll.handle, "SymGetOmapBlockBase");
            dbghelp.SymGetOmaps = GetProcAddress(dll.handle, "SymGetOmaps");
            dbghelp.SymGetOptions = GetProcAddress(dll.handle, "SymGetOptions");
            dbghelp.SymGetScope = GetProcAddress(dll.handle, "SymGetScope");
            dbghelp.SymGetScopeW = GetProcAddress(dll.handle, "SymGetScopeW");
            dbghelp.SymGetSearchPath = GetProcAddress(dll.handle, "SymGetSearchPath");
            dbghelp.SymGetSearchPathW = GetProcAddress(dll.handle, "SymGetSearchPathW");
            dbghelp.SymGetSourceFile = GetProcAddress(dll.handle, "SymGetSourceFile");
            dbghelp.SymGetSourceFileFromToken = GetProcAddress(dll.handle, "SymGetSourceFileFromToken");
            dbghelp.SymGetSourceFileFromTokenW = GetProcAddress(dll.handle, "SymGetSourceFileFromTokenW");
            dbghelp.SymGetSourceFileToken = GetProcAddress(dll.handle, "SymGetSourceFileToken");
            dbghelp.SymGetSourceFileTokenW = GetProcAddress(dll.handle, "SymGetSourceFileTokenW");
            dbghelp.SymGetSourceFileW = GetProcAddress(dll.handle, "SymGetSourceFileW");
            dbghelp.SymGetSourceVarFromToken = GetProcAddress(dll.handle, "SymGetSourceVarFromToken");
            dbghelp.SymGetSourceVarFromTokenW = GetProcAddress(dll.handle, "SymGetSourceVarFromTokenW");
            dbghelp.SymGetSymFromAddr = GetProcAddress(dll.handle, "SymGetSymFromAddr");
            dbghelp.SymGetSymFromAddr64 = GetProcAddress(dll.handle, "SymGetSymFromAddr64");
            dbghelp.SymGetSymFromName = GetProcAddress(dll.handle, "SymGetSymFromName");
            dbghelp.SymGetSymFromName64 = GetProcAddress(dll.handle, "SymGetSymFromName64");
            dbghelp.SymGetSymNext = GetProcAddress(dll.handle, "SymGetSymNext");
            dbghelp.SymGetSymNext64 = GetProcAddress(dll.handle, "SymGetSymNext64");
            dbghelp.SymGetSymPrev = GetProcAddress(dll.handle, "SymGetSymPrev");
            dbghelp.SymGetSymPrev64 = GetProcAddress(dll.handle, "SymGetSymPrev64");
            dbghelp.SymGetSymbolFile = GetProcAddress(dll.handle, "SymGetSymbolFile");
            dbghelp.SymGetSymbolFileW = GetProcAddress(dll.handle, "SymGetSymbolFileW");
            dbghelp.SymGetTypeFromName = GetProcAddress(dll.handle, "SymGetTypeFromName");
            dbghelp.SymGetTypeFromNameW = GetProcAddress(dll.handle, "SymGetTypeFromNameW");
            dbghelp.SymGetTypeInfo = GetProcAddress(dll.handle, "SymGetTypeInfo");
            dbghelp.SymGetTypeInfoEx = GetProcAddress(dll.handle, "SymGetTypeInfoEx");
            dbghelp.SymGetUnwindInfo = GetProcAddress(dll.handle, "SymGetUnwindInfo");
            dbghelp.SymInitialize = GetProcAddress(dll.handle, "SymInitialize");
            dbghelp.SymInitializeW = GetProcAddress(dll.handle, "SymInitializeW");
            dbghelp.SymLoadModule = GetProcAddress(dll.handle, "SymLoadModule");
            dbghelp.SymLoadModule64 = GetProcAddress(dll.handle, "SymLoadModule64");
            dbghelp.SymLoadModuleEx = GetProcAddress(dll.handle, "SymLoadModuleEx");
            dbghelp.SymLoadModuleExW = GetProcAddress(dll.handle, "SymLoadModuleExW");
            dbghelp.SymMatchFileName = GetProcAddress(dll.handle, "SymMatchFileName");
            dbghelp.SymMatchFileNameW = GetProcAddress(dll.handle, "SymMatchFileNameW");
            dbghelp.SymMatchString = GetProcAddress(dll.handle, "SymMatchString");
            dbghelp.SymMatchStringA = GetProcAddress(dll.handle, "SymMatchStringA");
            dbghelp.SymMatchStringW = GetProcAddress(dll.handle, "SymMatchStringW");
            dbghelp.SymNext = GetProcAddress(dll.handle, "SymNext");
            dbghelp.SymNextW = GetProcAddress(dll.handle, "SymNextW");
            dbghelp.SymPrev = GetProcAddress(dll.handle, "SymPrev");
            dbghelp.SymPrevW = GetProcAddress(dll.handle, "SymPrevW");
            dbghelp.SymRefreshModuleList = GetProcAddress(dll.handle, "SymRefreshModuleList");
            dbghelp.SymRegisterCallback = GetProcAddress(dll.handle, "SymRegisterCallback");
            dbghelp.SymRegisterCallback64 = GetProcAddress(dll.handle, "SymRegisterCallback64");
            dbghelp.SymRegisterCallbackW64 = GetProcAddress(dll.handle, "SymRegisterCallbackW64");
            dbghelp.SymRegisterFunctionEntryCallback = GetProcAddress(dll.handle, "SymRegisterFunctionEntryCallback");
            dbghelp.SymRegisterFunctionEntryCallback64 = GetProcAddress(dll.handle, "SymRegisterFunctionEntryCallback64");
            dbghelp.SymSearch = GetProcAddress(dll.handle, "SymSearch");
            dbghelp.SymSearchW = GetProcAddress(dll.handle, "SymSearchW");
            dbghelp.SymSetContext = GetProcAddress(dll.handle, "SymSetContext");
            dbghelp.SymSetHomeDirectory = GetProcAddress(dll.handle, "SymSetHomeDirectory");
            dbghelp.SymSetHomeDirectoryW = GetProcAddress(dll.handle, "SymSetHomeDirectoryW");
            dbghelp.SymSetOptions = GetProcAddress(dll.handle, "SymSetOptions");
            dbghelp.SymSetParentWindow = GetProcAddress(dll.handle, "SymSetParentWindow");
            dbghelp.SymSetScopeFromAddr = GetProcAddress(dll.handle, "SymSetScopeFromAddr");
            dbghelp.SymSetScopeFromIndex = GetProcAddress(dll.handle, "SymSetScopeFromIndex");
            dbghelp.SymSetSearchPath = GetProcAddress(dll.handle, "SymSetSearchPath");
            dbghelp.SymSetSearchPathW = GetProcAddress(dll.handle, "SymSetSearchPathW");
            dbghelp.SymSrvDeltaName = GetProcAddress(dll.handle, "SymSrvDeltaName");
            dbghelp.SymSrvDeltaNameW = GetProcAddress(dll.handle, "SymSrvDeltaNameW");
            dbghelp.SymSrvGetFileIndexInfo = GetProcAddress(dll.handle, "SymSrvGetFileIndexInfo");
            dbghelp.SymSrvGetFileIndexInfoW = GetProcAddress(dll.handle, "SymSrvGetFileIndexInfoW");
            dbghelp.SymSrvGetFileIndexString = GetProcAddress(dll.handle, "SymSrvGetFileIndexString");
            dbghelp.SymSrvGetFileIndexStringW = GetProcAddress(dll.handle, "SymSrvGetFileIndexStringW");
            dbghelp.SymSrvGetFileIndexes = GetProcAddress(dll.handle, "SymSrvGetFileIndexes");
            dbghelp.SymSrvGetFileIndexesW = GetProcAddress(dll.handle, "SymSrvGetFileIndexesW");
            dbghelp.SymSrvGetSupplement = GetProcAddress(dll.handle, "SymSrvGetSupplement");
            dbghelp.SymSrvGetSupplementW = GetProcAddress(dll.handle, "SymSrvGetSupplementW");
            dbghelp.SymSrvIsStore = GetProcAddress(dll.handle, "SymSrvIsStore");
            dbghelp.SymSrvIsStoreW = GetProcAddress(dll.handle, "SymSrvIsStoreW");
            dbghelp.SymSrvStoreFile = GetProcAddress(dll.handle, "SymSrvStoreFile");
            dbghelp.SymSrvStoreFileW = GetProcAddress(dll.handle, "SymSrvStoreFileW");
            dbghelp.SymSrvStoreSupplement = GetProcAddress(dll.handle, "SymSrvStoreSupplement");
            dbghelp.SymSrvStoreSupplementW = GetProcAddress(dll.handle, "SymSrvStoreSupplementW");
            dbghelp.SymUnDName = GetProcAddress(dll.handle, "SymUnDName");
            dbghelp.SymUnDName64 = GetProcAddress(dll.handle, "SymUnDName64");
            dbghelp.SymUnloadModule = GetProcAddress(dll.handle, "SymUnloadModule");
            dbghelp.SymUnloadModule64 = GetProcAddress(dll.handle, "SymUnloadModule64");
            dbghelp.UnDecorateSymbolName = GetProcAddress(dll.handle, "UnDecorateSymbolName");
            dbghelp.UnDecorateSymbolNameW = GetProcAddress(dll.handle, "UnDecorateSymbolNameW");
            dbghelp.WinDbgExtensionDllInit = GetProcAddress(dll.handle, "WinDbgExtensionDllInit");
            dbghelp.block = GetProcAddress(dll.handle, "block");
            dbghelp.chksym = GetProcAddress(dll.handle, "chksym");
            dbghelp.dbghelp = GetProcAddress(dll.handle, "dbghelp");
            dbghelp.dh = GetProcAddress(dll.handle, "dh");
            dbghelp.fptr = GetProcAddress(dll.handle, "fptr");
            dbghelp.homedir = GetProcAddress(dll.handle, "homedir");
            dbghelp.itoldyouso = GetProcAddress(dll.handle, "itoldyouso");
            dbghelp.lmi = GetProcAddress(dll.handle, "lmi");
            dbghelp.lminfo = GetProcAddress(dll.handle, "lminfo");
            dbghelp.omap = GetProcAddress(dll.handle, "omap");
            dbghelp.srcfiles = GetProcAddress(dll.handle, "srcfiles");
            dbghelp.stack_force_ebp = GetProcAddress(dll.handle, "stack_force_ebp");
            dbghelp.stackdbg = GetProcAddress(dll.handle, "stackdbg");
            dbghelp.sym = GetProcAddress(dll.handle, "sym");
            dbghelp.symsrv = GetProcAddress(dll.handle, "symsrv");
            dbghelp.vc7fpo = GetProcAddress(dll.handle, "vc7fpo");
        }

        auto procName = plugin::ToLower(FM::GetProcessName());
        if (procName == L"gx")
            loader::Load();
        else {
            plugin::InternalMessage(L"The update was not applied because the process is not gx.exe (process: %s)",
                FM::GetProcessName().c_str());
        }
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH) {
        loader::Unload();
    }
    return TRUE;
}
