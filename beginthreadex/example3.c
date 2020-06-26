#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>
#include<stdint.h>
#include<Windows.h>
#include<process.h>
#define Staff_Number 11

UINT _stdcall Staff(PVOID lp) {
    INT Count_Number = *(LPINT)lp;
    printf("員工編號為 %d，並報上數字%d\n", GetCurrentThreadId(),Count_Number);
    return 0;
}
int main(INT argc, PCHAR argv[])
{   
   
    HANDLE hd[Staff_Number];
    INT Count_Number[Staff_Number];
    INT Number = 0;
    for (INT i = 0; i < Staff_Number; i++) {
        Count_Number[i] = i + 1;
        hd[i] = (HANDLE)_beginthreadex(NULL, 0, Staff, &Count_Number[i], 0, NULL);
    }
    
    WaitForMultipleObjects(Staff_Number, hd, TRUE, INFINITE);
    for (INT i = 0; i < Staff_Number; i++) {
         CloseHandle(hd[i]);
    }
   
    system("pause");
    return 0;
}

