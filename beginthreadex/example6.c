#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>
#include<stdint.h>
#include<Windows.h>
#include<process.h>
#define MAX_DOCUMENT 100
#define TOTAL_STAFF 2
CRITICAL_SECTION CriticalSection;

volatile LONGLONG Document_Number = 0;
INT Document_Counter[MAX_DOCUMENT];

UINT _stdcall Staff(PVOID lp) {
    INT Staff_Number = *(INT*)lp;
    while (Document_Number < MAX_DOCUMENT)
    {
        EnterCriticalSection(&CriticalSection);
        INT i = Document_Number;
        Sleep(rand() % 2);
        Document_Number = i + 1;
        LeaveCriticalSection(&CriticalSection);
        printf("Process document %2d by staff %d\n", i, Staff_Number);
        Document_Counter[i]++;
    }   
    return 0;
}
int main(INT argc, PCHAR argv[])
{   
   
    HANDLE Staff_Handles[TOTAL_STAFF];
    INT Staff_Numbers[TOTAL_STAFF];   
    ZeroMemory(Document_Counter, sizeof(Document_Counter));
    InitializeCriticalSection(&CriticalSection);
    for (INT i = 0; i < TOTAL_STAFF; i++) {
        Staff_Numbers[i] = i ;
        Staff_Handles[i] = (HANDLE)_beginthreadex(NULL, 0, Staff, &Staff_Numbers[i], CREATE_SUSPENDED, NULL);
    }
    printf("Stuffs are ready\n");
    for (int i = 0; i < TOTAL_STAFF; i++) {
        ResumeThread(Staff_Handles[i]);
    }
    WaitForMultipleObjects(TOTAL_STAFF, Staff_Handles, TRUE, INFINITE);
    for (INT i = 0; i < TOTAL_STAFF; i++) {
         CloseHandle(Staff_Handles[i]);
    }
    for (int i = 0; i < MAX_DOCUMENT; i++) {
        printf("Document %2d processed by %d staffs\n", i, Document_Counter[i]);
    }
    DeleteCriticalSection(&CriticalSection);
    system("pause");
    return 0;
}