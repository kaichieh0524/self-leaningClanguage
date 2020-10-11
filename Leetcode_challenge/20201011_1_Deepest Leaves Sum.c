// Deepest Leaves Sum (medium)
// Runtime: 16 ms, faster than 100.00% of C online submissions for Deepest Leaves Sum.
// Memory Usage: 16.1 MB, less than 7.14% of C online submissions for Deepest Leaves Sum.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int findlength(struct TreeNode* root){
    if(!root){return 0;}
    return 1 + fmax(findlength(root->left), findlength(root->right));
}

int sum_(struct TreeNode* root,int length, int step){
    if(!root){return 0;}
    if(length == step){
        return root -> val;
    }
    return sum_( root -> right, length, step + 1) +  sum_( root -> left, length, step + 1);

}

int deepestLeavesSum(struct TreeNode* root){
    int length = findlength(root);    
    return sum_(root, length, 1);
}