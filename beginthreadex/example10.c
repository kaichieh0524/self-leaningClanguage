#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

#define MAX_SUSHI 100
#define BAR_SIZE 6
#define TOTAL_CHEF 3
#define TOTAL_CUSTOMER 5

volatile LONGLONG Sushi_Number = 0;
volatile LONGLONG Sushi_on_Bar = 0;
CRITICAL_SECTION Sushi_Bar;
INT head = 0, tail = 0;
INT Sushi_Counter[MAX_SUSHI];

UINT _stdcall Customer(PVOID lp) {
    INT Customer_Number = *(PINT)lp;
    while (tail < MAX_SUSHI) {
        EnterCriticalSection(&Sushi_Bar);
        INT i = -1;
        if (head > tail) {
            i = tail++;
            Sushi_on_Bar--;
            printf("Customer %d Eat Sushi %d (%d)\n", Customer_Number, i, Sushi_on_Bar);
            }
        LeaveCriticalSection(&Sushi_Bar);
        if (i >= 0) {
            Sleep(rand() % 4);
            Sushi_Counter[i]++;
        }
    }
    return 0;
}

UINT _stdcall Chef(PVOID lp) {
    INT Chef_Number = *((PINT)lp);
    while (head < MAX_SUSHI) {
        EnterCriticalSection(&Sushi_Bar);
        INT i = -1;
        if (head - tail < BAR_SIZE) {
            i = head++;
            Sushi_on_Bar++;
            printf("Chef %d makes sushi %d (%d) \n", Chef_Number, i,Sushi_on_Bar);
        }
        LeaveCriticalSection(&Sushi_Bar);
        if (i >= 0) {
            Sleep(rand() % 4);
        }
    }
    return 0;
}

int main(INT argc, PCHAR argv[]){     
    HANDLE Chef_Handles[TOTAL_CHEF];
    INT Chef_Numbers[TOTAL_CHEF];
    HANDLE Customer_Handles[TOTAL_CUSTOMER];
    INT Customer_Numbers[TOTAL_CUSTOMER];
    srand(GetTickCount());
    InitializeCriticalSection(&Sushi_Bar);
    ZeroMemory(Sushi_Counter, sizeof(Sushi_Counter));
    for (int i = 0; i < TOTAL_CHEF; i++) {
        Chef_Numbers[i] = i;
        Chef_Handles[i] = (HANDLE)_beginthreadex(NULL, 0, Chef, &Chef_Numbers[i], 0, NULL);
    }
    for (int i = 0; i < TOTAL_CUSTOMER; i++) {
        Customer_Numbers[i] = i;
        Customer_Handles[i] = (HANDLE)_beginthreadex(NULL, 0, Customer, &Customer_Numbers[i], CREATE_SUSPENDED, NULL);
    }
    printf("Customers are ready\n");
    for (int i = 0; i < TOTAL_CUSTOMER; i++) {
        ResumeThread(Customer_Handles[i]);
    }
    WaitForMultipleObjects(TOTAL_CUSTOMER, Customer_Handles, TRUE, INFINITE);
    WaitForMultipleObjects(TOTAL_CHEF, Chef_Handles, TRUE, INFINITE);
    for (int i = 0; i < MAX_SUSHI; i++) {
        printf("SUSHI %2d ate by %d customer\n", i, Sushi_Counter[i]);
    }
    DeleteCriticalSection(&Sushi_Bar);
    system("pause");
    return 0;
}

