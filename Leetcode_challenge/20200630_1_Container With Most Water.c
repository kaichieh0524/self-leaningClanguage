// Container With Most Water (medium)
// Runtime: 12 ms, faster than 94.00% of C online submissions for Container With Most Water.
// Memory Usage: 6.5 MB, less than 12.61% of C online submissions for Container With Most Water.

int maxArea(int* height, int heightSize){
    int max = 0;
    int i = 0;
    int j = heightSize -1;
    while(i < j){
        max = fmax(max , (j - i)*fmin(height[i],height[j])) ;
        if (height[i]<height[j]){ i++;}
        else {j--;}
    }
    return max;
}