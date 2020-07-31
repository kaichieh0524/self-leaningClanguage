// Construct Binary Tree from Preorder and Inorder Traversal
// Runtime: 24 ms, faster than 26.99% of C online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
// Memory Usage: 11.4 MB, less than 100.00% of C online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
    
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newroot(int value){
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root -> val = value;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

struct TreeNode* subroutine(int* preorder, int preorderSize, int* inorder, int inorderSize, int start , int end, int* index){
    if (start > end ){return NULL;}
    struct TreeNode* root = newroot(preorder[*index]);
    *index += 1;
    int i;
    for ( i = start; i < end; i++){
        if (inorder[i] == root -> val){
            break;
        }
    }
    root -> left = subroutine( preorder,  preorderSize,  inorder, inorderSize,  start , i-1, index);
    root -> right = subroutine( preorder,  preorderSize,  inorder, inorderSize,  i+1 , end, index);
    
   return root;
}


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int* index = calloc(1,sizeof(int));
    return subroutine(preorder, preorderSize, inorder, inorderSize, 0 , preorderSize-1, index);
}