// Count Complete Tree Nodes (medium)
// Runtime: 28 ms, faster than 52.94% of C online submissions for Count Complete Tree Nodes.
// Memory Usage: 16.5 MB, less than 43.53% of C online submissions for Count Complete Tree Nodes.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



int countNodes(struct TreeNode* root){
    if (root==NULL){return 0;}    
    return countNodes(root->right)+countNodes(root->left)+1;
}