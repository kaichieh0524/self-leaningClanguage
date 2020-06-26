#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>
#include<stdint.h>
#include<Windows.h>
#include<process.h>
#define Staff_Number 5

UINT _stdcall Staff(PVOID lp) {
    printf("The Number is %d\n", GetCurrentThreadId());
    return 0;
}
int main(INT argc, PCHAR argv[])
{   
   
    HANDLE hd[Staff_Number];
    for (INT i = 0; i < Staff_Number; i++) {
        hd[i] = (HANDLE)_beginthreadex(NULL, 0, Staff, NULL, 0, NULL);
    }
    
    WaitForMultipleObjects(Staff_Number, hd, TRUE, INFINITE);
    for (INT i = 0; i < Staff_Number; i++) {
         CloseHandle(hd[i]);
    }
   
    system("pause");
    return 0;
}
