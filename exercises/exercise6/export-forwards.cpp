// https://github.com/magnusstubman/dll-exports/blob/main/win10.19042/System32/wpncore.dll.cpp
#pragma comment(linker, "/export:DllCanUnloadNow=\"C:\\Windows\\System32\\wpncore.DllCanUnloadNow\"")
#pragma comment(linker, "/export:DllGetClassObject=\"C:\\Windows\\System32\\wpncore.DllGetClassObject\"")

