// Path Sum III (medium)
// Runtime: 24 ms, faster than 37.50% of C online submissions for Path Sum III.
// Memory Usage: 8.1 MB, less than 87.50% of C online submissions for Path Sum III.



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int helper(struct TreeNode* root, int cursum, int sum){
    if (!root){
        return 0;
    }
    if (root->val+cursum == sum){
        return 1 + helper(root->right, root->val+cursum,sum)+helper(root->left,root->val+cursum,sum);
    }
    else{
        return helper(root->right, root->val+cursum,sum)+helper(root->left,root->val+cursum,sum);
    }
}

int pathSum(struct TreeNode* root, int sum){
    if(!root){
        return 0;
    }
    return helper(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
}
