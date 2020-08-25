// Sum Root to Leaf Numbers (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Sum Root to Leaf Numbers.
// Memory Usage: 5.9 MB, less than 71.43% of C online submissions for Sum Root to Leaf Numbers.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void subroutine(struct TreeNode* root , int cur, int* ans){    
    cur = 10*cur + root->val;      
    if (root->left==NULL && root->right==NULL){
    *ans += cur;         
    return ;
    }
    if (root->left==NULL && root->right){
        subroutine(root->right,cur,ans);
    }   
    if (root->right==NULL && root->left){
        subroutine(root->left,cur,ans);
    }
    if (root->right && root->left){
        subroutine(root->left,cur,ans);
        subroutine(root->right,cur,ans);
    }    
}



int sumNumbers(struct TreeNode* root){
    if (!root){return 0;}
    int* ans = calloc(1,sizeof(int));
    subroutine(root,0,ans);
    return *ans;
}