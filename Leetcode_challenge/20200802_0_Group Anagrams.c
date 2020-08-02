// Group Anagrams (medium)
// Runtime: 392 ms, faster than 20.69% of C online submissions for Group Anagrams.
// Memory Usage: 78.9 MB, less than 50.00% of C online submissions for Group Anagrams.

void fillcount(char* str, int* count) {
    int index = 0;
    while (str[index] != '\0') {
        count[str[index]%97] += 1;
        index++;
    }
    count[26] = index; 
}

int compare(int* count1, int* count2) {
    if (count1[26] != count2[26]){return 0;} 
    else {
        for (int i = 0; i < 26; i++) {
            if (count1[i] != count2[i]) { return 0; }
        }
    }
    return 1;
}

void put(char* str1, char* str2) {
    int index = 0;
    while (str1[index] != '\0') {
        str2[index] = str1[index];
        index++;
    }
    str2[index] = '\0';
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int count = 0;
    printf("\n strsSize : %d \n",strsSize);
   char*** ans = calloc(10000,sizeof(char**));


    int* index = calloc(10000,sizeof(int));
    int returnsize = 0;
    int** table = malloc(sizeof(int*)*strsSize);
    for (int i = 0; i < strsSize; i++){
        table[i] = calloc(27, sizeof(int));
    }
    
    for (int i = 0; i < strsSize; i++) {
        if (strlen(strs[i])==0){count+=1; continue;}
        int* count1 = calloc(27, sizeof(int));        
        fillcount(strs[i], count1);
        for (int j = 0; j <= returnsize; j++) {            
                   
            int cmp = compare(count1, table[j]);
            if (cmp == 1) {
                ans[j][index[j]] = calloc(25,sizeof(char) );
                put(strs[i], ans[j][index[j]]);
                index[j] += 1;
                break; 
            }             
            if ( returnsize == j) {
                ans[returnsize] = calloc(300,sizeof(char*) );
                ans[j][index[j]] = calloc(25,sizeof(char) );
                put(strs[i], ans[j][index[j]]);
                memcpy(table[returnsize], count1, sizeof(int)*27);
                returnsize++;
                index[j] += 1;
                break; 
            }
        }
    }
    printf("\n count : %d \n" ,count);
    if (count){
        ans[returnsize] = calloc(count+1,sizeof(char*) );
        for (int i = 0; i < count; i++){            
             ans[returnsize][index[returnsize]] = calloc(2,sizeof(char) );
             put("", ans[returnsize][index[returnsize]]);
             index[returnsize] += 1;
            
        }
        returnsize+=1;
    }
//     printf("returnsize : %d", returnsize);
//         printf("\n--------------------------returncolsizes--------------------------------\n");
//      for (int i = 0; i < returnsize; i++) {       
//         printf(" %d " , index[i]);
//     }
    *returnSize = returnsize;
    *returnColumnSizes = calloc((*returnSize),sizeof(int));
    for (int i = 0; i < *returnSize; i++) {       
        returnColumnSizes[0][i] = index[i];
    }
    
//     for (int i = 0; i < returnsize; i++) {
//         printf("\n ------------------------%d-class----------------------------------------\n",i+1);
//         for (int j = 0; j < index[i]; j++) {
//             printf(" %s ", ans[i][j]);
//         }
        
//     }
//     printf("\n------------------------------------------------------------------------\n");  
    
    
    return ans;
}