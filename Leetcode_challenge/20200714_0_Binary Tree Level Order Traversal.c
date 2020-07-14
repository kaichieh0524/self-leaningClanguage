// Binary Tree Level Order Traversal (medium)
// Runtime: 12 ms, faster than 59.02% of C online submissions for Binary Tree Level Order Traversal.
// Memory Usage: 6.7 MB, less than 96.67% of C online submissions for Binary Tree Level Order Traversal.
    
int count = 0;
void levelorder(struct TreeNode* root, int level, int step) {

    if (root != NULL) {

        if (level == step) {
            count += 1;
        }
        levelorder(root -> left,level,step+1);
        levelorder(root -> right, level, step + 1);

    }
}

void levelorder1(struct TreeNode* root, int level, int step, int** ans) {

    if (root != NULL) {

        if (level == step) {
            ans[level-1][count] = root->val;
            count += 1;
        }
        levelorder1(root->left, level, step + 1,ans);
        levelorder1(root->right, level, step + 1,ans);

    }
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) { return 0; }
    else
    {
        return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
    }
}



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    int depth = maxDepth(root);
    *returnSize = depth;
    // printf("the depth : %d\n", depth);


    int** ans = malloc(sizeof(int*) * depth);
    returnColumnSizes[0] = calloc(depth,sizeof(int));
    

    for (int i = 1; i < depth+1; i++) {
        count = 0;
        levelorder(root, i, 1);
        returnColumnSizes[0][i - 1] = count;
    }


//     printf("the number each level : ", depth);

//     for (int i = 0; i < depth ; i++) {
//         printf(" %d ", returnColumnSizes[0][i]);
//     }
    // printf("\n");
    for (int i = 0; i < depth; i++) {
        ans[i] = malloc(sizeof(int)*returnColumnSizes[0][i]);
    }

    for (int i = 1; i < depth + 1; i++) {
        count = 0;
        levelorder1(root, i, 1,ans);        
    }

    // for (int i = 0; i < depth; i++) {
    //     for (int j = 0; j < returnColumnSizes[0][i]; j++) {
    //         printf(" %d ", ans[i][j]);
    //     }
    //     printf("\n");
    // }
    return ans;
}