// Flatten Binary Tree to Linked List (medium)
// Runtime: 4 ms, faster than 80.46% of C online submissions for Flatten Binary Tree to Linked List.
// Memory Usage: 6.5 MB, less than 17.24% of C online submissions for Flatten Binary Tree to Linked List.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void flatten(struct TreeNode* root){
    if (!root){return ;}
    flatten(root->left);
    flatten(root->right); 
   
    struct TreeNode* temp = root->right;
    root->right = root->left;
    root->left = NULL;
    while(root->right){
        root = root -> right;
    }
    root->right = temp;
}