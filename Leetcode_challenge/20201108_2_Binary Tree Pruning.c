// Binary Tree Pruning (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Tree Pruning.
// Memory Usage: 6.3 MB, less than 20.00% of C online submissions for Binary Tree Pruning.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int helper(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }
    if (root -> val == 1){
        return 1;
    }

    return root->val||helper(root -> right)||helper(root->left);
}



struct TreeNode* pruneTree(struct TreeNode* root){
    if (!helper(root)){
        return NULL;
    }

    if (!helper(root -> right)){
        root -> right = NULL;
    }
    if (!helper(root -> left)){
        root -> left = NULL;
    }
   pruneTree(root -> right);
   pruneTree(root -> left);

    return root;
}