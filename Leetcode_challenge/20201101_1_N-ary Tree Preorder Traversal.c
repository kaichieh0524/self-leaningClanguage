// N-ary Tree Preorder Traversal (easy)
// Runtime: 12 ms, faster than 85.71% of C online submissions for N-ary Tree Preorder Traversal.
// Memory Usage: 8.7 MB, less than 9.52% of C online submissions for N-ary Tree Preorder Traversal.

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */



void subroutine(struct Node* root, int* returnSize, int* ans){
    if (!root){return;}
    ans[(*returnSize)++] = root -> val;
    for (int i = 0; i < root -> numChildren; i++){
        subroutine(root->children[i], returnSize, ans);
    }    
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    int* ans = malloc(sizeof(int)*10000);
    subroutine(root, returnSize, ans);
    return ans;    
}