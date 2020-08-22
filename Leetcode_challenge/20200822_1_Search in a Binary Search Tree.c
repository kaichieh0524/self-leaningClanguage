// Search in a Binary Search Tree (easy)
// Runtime: 24 ms, faster than 83.85% of C online submissions for Search in a Binary Search Tree.
// Memory Usage: 14.9 MB, less than 27.33% of C online submissions for Search in a Binary Search Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void subroutine(struct TreeNode* root, struct TreeNode** ans, int val){
    if(root == NULL){return;}
    if(root -> val == val){*ans = root; return;}
    subroutine(root->left,  ans, val);
    subroutine(root->right,  ans, val);
    return;
}



struct TreeNode* searchBST(struct TreeNode* root, int val){
    struct TreeNode** ans = calloc(1, sizeof(struct TreeNode*));
    subroutine(root,  ans, val);
    return *ans;
}