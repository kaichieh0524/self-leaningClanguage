// Remove Element (easy)
// Runtime: 8 ms, faster than 100.00% of C online submissions for Remove Element.
// Memory Usage: 5.6 MB, less than 69.11% of C online submissions for Remove Element.
    
int count = 0;

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

int removeElement(int* nums, int numsSize, int val){
    count = 0;
	for (int i = 0; i < numsSize-count; i++) {
		while (nums[i] == val) {
			count++;
            if (i >= numsSize - count) { break; }
			for (int j = i; j < numsSize-1; j++) {
				swap(&nums[j], &nums[j + 1]);
			}
		}
	}
    printf("The array is : ");
	for (int i = 0; i < numsSize; i++) {
		printf("%d", nums[i]);
	}
	printf("\ncount %d\n", count);
    return numsSize-count;
}