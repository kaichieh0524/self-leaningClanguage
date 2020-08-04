// Lowest Common Ancestor of a Binary Tree (medium)
// Runtime: 32 ms, faster than 41.23% of C online submissions for Lowest Common Ancestor of a Binary Tree.
// Memory Usage: 18.3 MB, less than 60.00% of C online submissions for Lowest Common Ancestor of a Binary Tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isdescandants(struct TreeNode* root, int target){
    if (root == NULL){return 0;}
    bool res = (root -> val == target) || isdescandants(root->left,target) || isdescandants(root->right,target);
    return res;
}

void findLCA(struct TreeNode* root, struct TreeNode** ans, int p, int q){
    if (root == NULL ){return;}    
    
    findLCA( root->left,  ans,  p,  q);
    findLCA( root->right,  ans,  p,  q);
    if (*ans != NULL){return;}
    if (isdescandants(root,p) && isdescandants(root,q)){
        *ans = root;
    }   
    
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode** ans = malloc(sizeof(struct TreeNode*));
    *ans = NULL;
    findLCA(root,  ans, p->val, q->val);    
    return *ans;
}