// N-ary Tree Postorder Traversal (easy)
// Runtime: 12 ms, faster than 77.14% of C online submissions for N-ary Tree Postorder Traversal.
// Memory Usage: 8.4 MB, less than 11.43% of C online submissions for N-ary Tree Postorder Traversal.


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
    for (int i = 0; i < root -> numChildren; i++){
        subroutine(root->children[i], returnSize, ans);
    }
    
    ans[(*returnSize)++] = root -> val;
    
}






/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize) {
    *returnSize = 0;
    int* ans = malloc(sizeof(int)*10000);
    subroutine(root, returnSize, ans);
    return ans;
}