#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<tchar.h>

INT _tmain(INT argc, LPCTSTR argv[]){     
    TCHAR szCommandLine[] = _T("calc.exe");
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;

    BOOL bProcess = CreateProcess(
        NULL,
        szCommandLine,
        NULL,
        NULL,
        FALSE,
        CREATE_NEW_CONSOLE,
        NULL,
        NULL,
        &si,
        &pi);

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    system("pause");
    return 0;
}