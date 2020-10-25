//  Maximum Number of Coins You Can Get (medium)
// Runtime: 120 ms, faster than 98.51% of C online submissions for Maximum Number of Coins You Can Get.
// Memory Usage: 14.1 MB, less than 71.64% of C online submissions for Maximum Number of Coins You Can Get.


int cmp (const void * a, const void * b) {
   return -( *(int*)a - *(int*)b );
}


int maxCoins(int* piles, int pilesSize){
    qsort(piles, pilesSize, sizeof(int), cmp);
    int n = pilesSize / 3;
    int ans = 0;    
    for (int i = 0; i < n; i++){
        ans += piles[2*i+1];
    }
    return ans;
}