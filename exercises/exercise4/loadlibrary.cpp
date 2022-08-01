#include <Windows.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc != 2) {
        printf("[!] 1 argument expected. Got %d\n", (argc - 1));
        return 1;
    }
    printf("[ ] calling LoadLibraryA(\"%s\") ...\n", argv[1]);

    HANDLE handle = LoadLibraryA(argv[1]);
    
    if (handle == NULL) {
        printf("[!] NULL returned! GetLastError: %d\n", GetLastError());
        return 1;
    }

    printf("[+] handle returned: %p\n", handle);
    printf("[ ] calling Sleep(INFINITE)...\n");

    Sleep(INFINITE);

    return 0;
}

