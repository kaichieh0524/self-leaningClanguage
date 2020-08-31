// Construct Binary Search Tree from Preorder Traversal (medium)
// Runtime: 4 ms, faster than 69.01% of C online submissions for Construct Binary Search Tree from Preorder Traversal.
// Memory Usage: 8.1 MB, less than 8.45% of C online submissions for Construct Binary Search Tree from Preorder Traversal.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createnode(int val){
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node -> val = val;
    node -> left = NULL;
    node -> right = NULL;
    return node;
}

struct TreeNode* subroutine(int* preorder, int start, int end){
    if (start > end){return NULL;}
    struct TreeNode* new = createnode(preorder[start]);
    int i;
    for ( i = start; i <= end;  i++){
        if (preorder[i] > new -> val){
            break;
        }
    }
    new -> left = subroutine(preorder,start + 1, i - 1);
    new -> right = subroutine(preorder, i, end);
    return new;
}



struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
        return subroutine(preorder,0,preorderSize-1);
}




