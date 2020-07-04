// Inorder Traversal (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Tree Inorder Traversal.
// Memory Usage: 5.5 MB, less than 89.24% of C online submissions for Binary Tree Inorder Traversal.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int count = 0;
void inordertraversal(struct TreeNode* root, int* ans);


int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* ans = malloc(sizeof(int) * 100);
    count = 0;
    printf("the inorder traversal of tree :");
    inordertraversal( root,  ans);
    printf("\n------------------------------------------------------------\n");
    printf("the return size is : %d", count);
    printf("\n------------------------------------------------------------\n");
    printf("the final ans is :");
    for (int i = 0; i < count; i++) {
        printf("%d ",ans[i] );
    }
    printf("\n------------------------------------------------------------\n");
    *returnSize = count;
    return ans;
    
}



void inordertraversal(struct TreeNode* root, int* ans) {
    if (root == NULL) {
        return;
    }   
    inordertraversal(root->left, ans);
    ans[count] = root->val;   
    printf("%d ", root->val);
    count++;
    if (root->right != NULL) {
        inordertraversal(root->right, ans);        
    }
}
    