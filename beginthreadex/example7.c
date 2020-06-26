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
HANDLE Process1_Done, Process2_Ready, Process2_GetDoc;

UINT _stdcall Process1(PVOID lp) {
    
    while (Document_Number < MAX_DOCUMENT)
    {
        printf("Process document %2d by staff 1\n", Document_Number);
        printf("Finish1 document %2d by staff 1\n", Document_Number);
        Document_Counter[Document_Number]++;
        SetEvent(Process1_Done);
        WaitForSingleObject(Process2_Ready, INFINITE);
        WaitForSingleObject(Process2_GetDoc, INFINITE);
        Document_Number++;
    }   
    return 0;
}
UINT _stdcall Process2(PVOID lp) {
    SetEvent(Process2_Ready);
    while (Document_Number < MAX_DOCUMENT)
    {
        WaitForSingleObject(Process1_Done, INFINITE);
        INT i = Document_Number;
        printf("Process document %2d by staff 2\n",i);
        SetEvent(Process2_GetDoc);
        printf("Finish2 document %2d by staff 2\n", i);
        Document_Counter[i]++;
        SetEvent(Process2_Ready);
    }
    return 0;
}
int main(INT argc, PCHAR argv[])
{   
   
    HANDLE Staff_Handles[TOTAL_STAFF];    
    ZeroMemory(Document_Counter, sizeof(Document_Counter));
    Process1_Done = CreateEvent(NULL, FALSE, FALSE, NULL);
    Process2_Ready = CreateEvent(NULL, FALSE, FALSE, NULL);
    Process2_GetDoc = CreateEvent(NULL, FALSE, FALSE, NULL);
    Staff_Handles[0] = (HANDLE)_beginthreadex(NULL, 0, Process1, NULL , 0, NULL);
    Staff_Handles[1] = (HANDLE)_beginthreadex(NULL, 0, Process2, NULL, 0, NULL);    
    WaitForMultipleObjects(TOTAL_STAFF, Staff_Handles, TRUE, INFINITE);
    CloseHandle(Process1_Done);
    CloseHandle(Process2_Ready);
    CloseHandle(Process2_GetDoc);    
    for (int i = 0; i < MAX_DOCUMENT; i++) {
        printf("Document %2d processed by %d staffs\n", i, Document_Counter[i]);
    }
    
    system("pause");
    return 0;
}

