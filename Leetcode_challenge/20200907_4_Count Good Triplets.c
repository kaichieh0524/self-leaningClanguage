// Count Good Triplets (easy)
// Runtime: 20 ms, faster than 68.49% of C online submissions for Count Good Triplets.
// Memory Usage: 5.7 MB, less than 9.13% of C online submissions for Count Good Triplets.


int countGoodTriplets(int* arr, int arrSize, int a, int b, int c){
    int ans = 0;
    for (int i = 0; i < arrSize; i++){
        for (int j = i+1; j < arrSize; j++){
            for (int k = j+1; k< arrSize; k++){
                if (abs(arr[i]-arr[j]) <= a && abs(arr[j]-arr[k]) <= b && abs(arr[i]-arr[k]) <= c){
                    ans++;
                }
            }
        }
    }
    return ans;
}