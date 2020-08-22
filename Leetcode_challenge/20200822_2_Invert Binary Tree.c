// Invert Binary Tree (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Invert Binary Tree.
// Memory Usage: 5.4 MB, less than 95.05% of C online submissions for Invert Binary Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void helper(struct TreeNode* root){
    if (root->left == NULL && root->right == NULL){return;}
    struct TreeNode* temp = root -> left;
    root->left = root -> right;
    root->right = temp;
    if (root->right != NULL){
       helper(root->right);
    }

    
    if (root->left != NULL){
        helper(root->left);
    }
}



struct TreeNode* invertTree(struct TreeNode* root){
    if(root==NULL){return NULL;}
    helper(root);
    return root;
}