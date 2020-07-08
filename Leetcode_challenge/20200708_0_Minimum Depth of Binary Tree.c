// Minimum Depth of Binary Tree (easy)
// Runtime: 8 ms, faster than 96.10% of C online submissions for Minimum Depth of Binary Tree.
// Memory Usage: 8.4 MB, less than 5.88% of C online submissions for Minimum Depth of Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
       if (root == NULL){return 0;}
    else
    {
        if(root-> left == NULL){
            return 1+minDepth(root -> right);
        }
        else if (root-> right == NULL){
            return 1+minDepth(root -> left);
        }
        else {
            return 1+fmin(minDepth(root -> left),minDepth(root -> right)); 
        }
           
    }
}