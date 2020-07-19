// 4sum II (medium)
// Runtime: 204 ms, faster than 42.31% of C online submissions for 4Sum II.
// Memory Usage: 19.2 MB, less than 50.00% of C online submissions for 4Sum II.


int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize){
    int ans = 0;
    int* A_add_B = calloc(ASize * BSize, sizeof(int));
    int* C_add_D = calloc(CSize * DSize, sizeof(int));
    int index = 0;


    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            A_add_B[index] = A[i] + B[j];
            index++;
        }
    }
    index = 0;
    for (int i = 0; i < CSize; i++) {
        for (int j = 0; j < DSize; j++) {
            C_add_D[index] = C[i] + D[j];
            index++;
        }
    }

    qsort(A_add_B, ASize * BSize, sizeof(int), cmpfunc);
    qsort(C_add_D, CSize * DSize, sizeof(int), cmpfunc);


    int left = 0;
    int right = CSize * DSize - 1;

    while (left < CSize * DSize && right >= 0) {

        if (A_add_B[left] + C_add_D[right] < 0) {
            left++;
        }
        else if (A_add_B[left] + C_add_D[right] > 0) {
            right--;
        }
        else {
            int temp1 = 1;
            int temp2 = 1;

            while (right >= 1 && C_add_D[right - 1] == C_add_D[right]) {
                right--;
                temp1++;
            }
            while (left < CSize * DSize - 1 && A_add_B[left] == A_add_B[left + 1]) {
                left++;
                temp2++;
            }
            ans += temp1 * temp2;
            right--;
            left++;
        }
    }


    printf("ans : %d", ans);
    
    return ans;
}