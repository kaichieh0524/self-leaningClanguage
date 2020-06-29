//Convert Sorted Array to Binary Search Tree (easy)
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// Runtime: 8 ms, faster than 91.19% of C online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 17.5 MB, less than 68.16% of C online submissions for Convert Sorted Array to Binary Search Tree.


struct TreeNode* sub_routine(int* nums, int n, int m){
    
    if (n>m){
        return NULL;
    }
    
    else {
        int midpoint = (n+m)/2;
        struct TreeNode* current = malloc(sizeof(struct TreeNode)) ;
        current -> val = nums[midpoint];
        current -> left = sub_routine(nums, n, midpoint-1);
        current -> right = sub_routine(nums, midpoint+1,  m);
        return current;
    }
}



struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    
    return sub_routine(nums,0,numsSize-1);

}