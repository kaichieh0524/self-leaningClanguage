// Intersection of Two Arrays II (easy)
// me: 4 ms, faster than 94.41% of C online submissions for Intersection of Two Arrays II.
// Memory Usage: 5.9 MB, less than 82.56% of C online submissions for Intersection of Two Arrays II.
// remark : be careful the compare function in qsort may be overflow

int compare (const void * a, const void * b)
{
   float fa = *(const float*) a;
   float fb = *(const float*) b;
  return (fa > fb) - (fa < fb);
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int* ans = malloc(sizeof(int)*fmin(nums1Size,nums2Size));
    int i = 0 ;
    int j = 0 ;
    int count = 0 ;
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare); 

    while( i < nums1Size && j < nums2Size)
    {
        if (nums1[i]==nums2[j])
        {
            
            ans[count] = nums1[i];            
            i++;
            j++;            
            count++;
        }
        else if (nums1[i] > nums2[j])
        {
            j++;    
        }
        else 
        {
            i++;
        }
    }
    
    *returnSize = count;
    return ans;
}