// Letter Combinations of a Phone Number (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 5.4 MB, less than 90.57% of C online submissions for Letter Combinations of a Phone Number.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** letterCombinations(char * digits, int* returnSize){
    if(*digits==0){*returnSize=0;return NULL;}
    char** s = malloc(sizeof(char*) * 8);
    s[0] = "abc";
    s[1] = "def";
    s[2] = "ghi";
    s[3] = "jkl";
    s[4] = "mno";
    s[5] = "pqrs";
    s[6] = "tuv";
    s[7] = "wxyz";
    int total = 1;
    
    int len = strlen(digits);


    for (int i = 0; i < 8; i++) {
        printf("the number %d : %s\n", i + 2, s[i]);
    }
    printf("---------------------------------------");

    for (int i = 0; i < len; i++) {
        if (digits[i] % 50 == 5 || digits[i] % 50 == 7) {
            total *= 4;
        }
        else { total *= 3; }
    }
    printf("\ntotal : %d", total);

    char** ans = malloc(sizeof(char*) * total);
    for (int i = 0; i < total; i++) {
        ans[i] = malloc(sizeof(char) * (len + 1));
    }
    int temp = total;
    *returnSize = total;
    for (int i = 0; i < len + 1; i++) {
        int cnt = 0;
        int flag = 0;
        
        if (i == len - 1 && digits[i] % 50 != 5 && digits[i] % 50 != 7 ) {
            for (int j = 0; j < total; j++) {
                ans[j][i] = s[digits[i] % 50][flag];
                flag = (flag + 1) % 3;
            }
        }
        else if (i == len - 1 && (digits[i] % 50 == 5 || digits[i] % 50 == 7)) {
            for (int j = 0; j < total; j++) {
                ans[j][i] = s[digits[i] % 50][flag];
                flag = (flag + 1) % 4;
            }
        }
        else if (digits[i] % 50 == 5 || digits[i] % 50 == 7 && i < len) {
                temp = temp / 4;
                for (int j = 0; j < total; j++) {
                    ans[j][i] = s[digits[i] % 50][flag];
                    cnt++;                    
                    if (cnt % (temp) == 0) { flag = (flag + 1) % 4; }
            

                }
        }
        else if (digits[i] % 50 != 5 && digits[i] % 50 != 7 && i < len){
            temp = temp / 3;
            for (int j = 0; j < total; j++) {
                    ans[j][i] = s[digits[i] % 50][flag];
                    cnt++;                    
                    if (cnt % (temp) == 0) {flag = (flag + 1)% 3;}


            }
        }
        else if (i == len) {
            for (int j = 0; j < total; j++) {
                ans[j][i] = '\0';
            }
        }

    }
    printf("\n---------------------------------------\n");
    printf("the ans is :");
    for (int i = 0; i < total; i++) {
        printf("\n%s", ans[i]);
    }
    printf("\n---------------------------------------\n");
    
    return ans;
}