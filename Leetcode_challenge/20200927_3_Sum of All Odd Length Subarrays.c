// Sum of All Odd Length Subarrays (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Sum of All Odd Length Subarrays.
// Memory Usage: 6 MB, less than 5.66% of C online submissions for Sum of All Odd Length Subarrays.


int sumOddLengthSubarrays(int* arr, int arrSize){
    int sum = 0;
    for (int i = 0; i < arrSize; i++){
       sum += ((i+1)*(arrSize-i)+1)/2 * arr[i];
    }
    return sum;
}
