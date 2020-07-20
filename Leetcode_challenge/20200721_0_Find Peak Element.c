// Find Peak Element (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Find Peak Element.
// Memory Usage: 5.5 MB, less than 40.54% of C online submissions for Find Peak Element.

int findPeakElement(int* nums, int numsSize){
    if (numsSize == 1){return 0;}
    
    
    
    int left = 0;
    int right = numsSize - 1;
    
    
    while (left < right){
        
        if (right-left== 1){            
             if (nums[left] > nums[right]){
                return left;
                 }
            else {
                return right;
                 }
            }
        
        
        int mid = (left + right) / 2;
        
        
        if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1] ){
            return mid;
        }
        else if (nums[mid] >= nums[mid-1] && nums[mid] <= nums[mid+1] ){
            left = mid;
        }
        else  {
            right = mid;
        }
        
        
        }
    return left;
}