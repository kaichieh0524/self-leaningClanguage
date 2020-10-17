// Binary Search Tree to Greater Sum Tree (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Search Tree to Greater Sum Tree.
// Memory Usage: 6 MB, less than 100.00% of C online submissions for Binary Search Tree to Greater Sum Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void subroutine(struct TreeNode* root, int* sum){
    if(!root){return;}
    subroutine(root-> right,sum);
    *sum += root->val;
    root -> val = *sum;    
    subroutine(root-> left,sum);
}

struct TreeNode* bstToGst(struct TreeNode* root){
    int* sum = calloc(1,sizeof(int));
    subroutine(root,sum);
    return root;
}
