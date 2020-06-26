#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>
#include<stdint.h>
#include<Windows.h>
#include<process.h>
#define TIMES 100
#define TOTAL_STAFF 5




HANDLE hMutex;

UINT _stdcall Staff(PVOID lp) {
    INT Staff_Number = *(int*)lp;
    for (int i = 0; i < TIMES; i++)
    {
        WaitForSingleObject(hMutex, INFINITE);
        printf("Staff %d enter toilet\n", Staff_Number);
        Sleep(rand() % 2);
        printf("Staff %d leave toilet\n", Staff_Number);
        ReleaseMutex(hMutex);
    }
    return 0;
}

int main(INT argc, TCHAR* argv[])
{   
   
    HANDLE Staff_Handles[TOTAL_STAFF];
    INT Staff_Numbers[TOTAL_STAFF];
    srand(GetTickCount);
    hMutex = CreateMutex(NULL, FALSE, NULL);
    for (int i = 0; i < TOTAL_STAFF; i++) {
        Staff_Numbers[i] = i;
        Staff_Handles[i] = (HANDLE)_beginthreadex(NULL, 0, Staff, &Staff_Numbers[i], CREATE_SUSPENDED, NULL);
    }
    printf("Stuffs are ready\n");
    for (int i = 0; i < TOTAL_STAFF; i++) {
        ResumeThread(Staff_Handles[i]);
    }
    WaitForMultipleObjects(TOTAL_STAFF, Staff_Handles, TRUE, INFINITE);     
    for (int i = 0; i < TOTAL_STAFF; i++) {
        CloseHandle(Staff_Handles[i]);
    }
    CloseHandle(hMutex);
    system("pause");
    return 0;
}

