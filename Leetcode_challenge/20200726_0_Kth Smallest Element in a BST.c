// Kth Smallest Element in a BST (medium)
// Runtime: 8 ms, faster than 97.93% of C online submissions for Kth Smallest Element in a BST.
// Memory Usage: 10 MB, less than 50.00% of C online submissions for Kth Smallest Element in a BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Inorder(struct TreeNode* root, int* count, int k, int* ans) 
{ 
     if (root == NULL) 
          return;     
     Inorder(root->left,count,k,ans);      
     *count += 1;
     if (*count == k){*ans = root -> val;}
     Inorder(root->right,count,k,ans); 
} 

int kthSmallest(struct TreeNode* root, int k){
    int* count = calloc(1,sizeof(int));
    int* ans = calloc(1,sizeof(int));
    Inorder(root,count,k,ans);
    return *ans;
}