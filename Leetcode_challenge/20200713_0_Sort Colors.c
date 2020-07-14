// Sort Colors (medium)
// Runtime: 4 ms, faster than 66.47% of C online submissions for Sort Colors.
// Memory Usage: 5.6 MB, less than 80.88% of C online submissions for Sort Colors.

void sortColors(int* nums, int numsSize){
    int num0 = 0, num1 = 0, num2 = 0;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] == 0 ){
            num0 +=1;
        }
        else if (nums[i] == 1){
            num1 += 1;
        }
        else {
            num2 += 1;
        }
    }
    printf("num0 : %d\n", num0);
    printf("num1 : %d\n", num1);
    printf("num2 : %d\n", num2);
    for (int i = 0; i < numsSize; i++){
        if (i < num0){
            nums[i] = 0;
        }
        else if (num0 <= i && i < num0+num1){
            nums[i] = 1;
        }
        else {
            nums[i] = 2;
        }
    }
}