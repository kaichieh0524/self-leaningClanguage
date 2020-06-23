// Rotate Array (easy)
// Runtime: 12 ms, faster than 89.31% of C online submissions for Rotate Array.
// Memory Usage: 7.6 MB, less than 7.33% of C online submissions for Rotate Array.

void rotate(int* nums, int numsSize, int k){
    int* temp= malloc(sizeof(int)*numsSize);
    int check = (k + 0) % numsSize;
    for (int i = 0; i < numsSize; i++) {
        temp[(k + i) % numsSize] = nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
    // printf("the ans is : ");
    // for (int i = 0; i < numsSize; i++) {
    //     printf("%d", nums[i]);
    // }
   
}