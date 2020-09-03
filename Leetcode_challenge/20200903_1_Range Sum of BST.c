/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int rangeSumBST(struct TreeNode* root, int L, int R){
    if (!root){return 0;}
    if (root->val <= R && root->val >= L){
        return root->val + rangeSumBST(root->right,L,R) + rangeSumBST(root->left,L,R);
    }    
    return rangeSumBST(root->right,L,R) + rangeSumBST(root->left,L,R);
}