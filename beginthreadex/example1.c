#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdint.h>
#include<Windows.h>
#include<process.h>

UINT _stdcall Staff(PVOID lp) {
    printf("The Number is %d\n", GetCurrentThreadId());
    return 0;
}
int main(INT argc, PCHAR argv[])
{   
    HANDLE hd = (HANDLE)_beginthreadex(NULL, 0, Staff, NULL, 0, NULL);
    WaitForSingleObject(hd, INFINITE);
    CloseHandle(hd);
    system("pause");
    return 0;
}
