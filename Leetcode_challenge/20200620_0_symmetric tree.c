// symmetric tree (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 4 ms, faster than 69.23% of C online submissions for Symmetric Tree.
// Memory Usage: 6.5 MB, less than 47.96% of C online submissions for Symmetric Tree.

// the key idea is recurrsively to check that 

// (1) The left subtree of the left subtree and the right subtree of the right subtree are symmetrical.
// (2) The right subtree of the left subtree and the left subtree of the right subtree are symmetrical.   

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool sub_symmetric(struct TreeNode* root1,struct TreeNode* root2){
    if (root1==NULL && root2==NULL){return true;}
    if (root1==NULL || root2==NULL){return false;}
    else{
        return (root1->val == root2->val) && sub_symmetric( root1 -> left, root2 ->right) && sub_symmetric( root1 -> right, root2 -> left);
    }
}


bool isSymmetric(struct TreeNode* root){
    if (root == NULL){return true;}
    struct TreeNode* root1 = root -> left;
    struct TreeNode* root2 = root -> right;
    return sub_symmetric(root1, root2); 
    
}