// House Robber III (medium)
// Runtime: 808 ms, faster than 34.29% of C online submissions for House Robber III.
// Memory Usage: 8.3 MB, less than 40.00% of C online submissions for House Robber III.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int rob(struct TreeNode* root){
    if (root == NULL){return 0;}
    if (root->left && !root->right){
        return fmax(root->val+rob(root->left->right)+rob(root->left->left),rob(root->right)+rob(root->left));
    }
    else if (!root->left && root->right){
        return fmax(root->val+rob(root->right->right)+rob(root->right->left),rob(root->right)+rob(root->left));
    }
    else if  (!root->left && !root->right){
         return root->val;
    }
    
    return fmax(root->val+rob(root->left->right)+rob(root->left->left)+rob(root->right->right)+rob(root->right->left),rob(root->right)+rob(root->left));
    
}