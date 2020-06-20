// maximum depth of binary tree (easy)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>


// Runtime: 4 ms, faster than 93.35% of C online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 7.7 MB, less than 6.51% of C online submissions for Maximum Depth of Binary Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



int maxDepth(struct TreeNode* root){
    if (root == NULL){return 0;}
    else
    {
        return 1+fmax(maxDepth(root -> left),maxDepth(root -> right));    
    }
}
