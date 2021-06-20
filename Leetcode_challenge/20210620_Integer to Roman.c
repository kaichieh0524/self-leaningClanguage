// Integer to Roman (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Integer to Roman.
// Memory Usage: 6 MB, less than 64.16% of C online submissions for Integer to Roman.

char * intToRoman(int num){
    //note the nums is less than 3999
    int nums[4], index = 0;
    char* ans = malloc(sizeof(char)*20);
    ans[0] = '\0';
    for (int i = 0; i < 4; i++){
        nums[i] = num % 10;
        num /= 10;
    }
    if(nums[3] > 0){
        for(int i = 0; i < nums[3]; i++){
            strcat(ans, "M");
        }
    }
    if(nums[2] > 0){
        if(nums[2] == 9){
            strcat(ans, "CM");
        }
        else if (nums[2] == 4){
            strcat(ans, "CD");
        }
        else if(nums[2] >= 5 && nums[2] < 9){
            strcat(ans, "D");
            for(int i = 0; i < nums[2] - 5; i++){
                strcat(ans, "C");
            }
        }
        else{
            for(int i = 0; i < nums[2]; i++ ){
                strcat(ans, "C");
            }
        }
    }
    if(nums[1] > 0){
        if(nums[1] == 9){
            strcat(ans, "XC");
        }
        else if (nums[1] == 4){
            strcat(ans, "XL");
        }
        else if(nums[1] >= 5 && nums[1] < 9){
            strcat(ans, "L");
            for(int i = 0; i < nums[1] - 5; i++){
                strcat(ans, "X");
            }
        }
        else{
            for(int i = 0; i < nums[1]; i++ ){
                strcat(ans, "X");
            }
        }
    }
    if(nums[0] > 0){
        if(nums[0] == 9){
            strcat(ans, "IX");
        }
        else if (nums[0] == 4){
            strcat(ans, "IV");
        }
        else if(nums[0] >= 5 && nums[0] < 9){
            strcat(ans, "V");
            for(int i = 0; i < nums[0] - 5; i++){
                strcat(ans, "I");
            }
        }
        else{
            for(int i = 0; i < nums[0]; i++ ){
                strcat(ans, "I");
            }
        }
    }
    return ans;
}