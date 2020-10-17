// Count Number of Teams (medium)
// Runtime: 4 ms, faster than 96.47% of C online submissions for Count Number of Teams.
// Memory Usage: 6 MB, less than 91.76% of C online submissions for Count Number of Teams.


int numTeams(int* rating, int ratingSize){
    int ans = 0;

    for (int j = 0; j < ratingSize;j++){
      int l = 0;
      int r = 0;
      for (int i = 0; i < j; i++)
        if (rating[i] >rating[j]) ++l;
      for (int k = j + 1; k < ratingSize; ++k)
        if (rating[j] > rating[k]) ++r;
      ans += (l * r) + (j - l) * (ratingSize - j - 1 - r);
    }  
    return ans;
}