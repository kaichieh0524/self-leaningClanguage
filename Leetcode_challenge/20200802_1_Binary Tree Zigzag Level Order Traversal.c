// Binary Tree Zigzag Level Order Traversal (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Binary Tree Zigzag Level Order Traversal.
// Memory Usage: 7 MB, less than 100.00% of C online submissions for Binary Tree Zigzag Level Order Traversal.



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

typedef struct TreeNode TreeNode;
void swap (int* a ,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void reverse(int* nums,int n){
    int mid = (n+1)/2;
    for (int i = 0; i < mid; i++){
        swap(&nums[i],&nums[n-1-i]);
    }
}

struct TreeNode* newroot(int value) {
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int maxDepth(struct TreeNode* root){
    if (root == NULL){return 0;}
    else
    {
        return 1+fmax(maxDepth(root -> left),maxDepth(root -> right));    
    }
}


void levelorder(TreeNode* node,int level,int** ans, int* index)
{
    if (!node) { return; }

    if (node-> left == NULL && node->right == NULL)
        return;
    else if (node->left && node->right == NULL) {
        
        ans[level-1][index[level-1]] = node->left->val;
        index[level-1] +=1;
        //printf("\n level : %d, val : %d \n",level, node->left->val);
    }
    else if (node->left == NULL && node->right) {
        
        ans[level-1][index[level-1]] = node->right->val;
        index[level-1] +=1;
       // printf("\n level : %d, val : %d \n", level, node->right->val);
    }
    else if (node->left && node->right) {
       
        ans[level-1][index[level-1]] = node->left->val;
        index[level-1] +=1;
        ans[level-1][index[level-1]] = node->right->val;
        index[level-1] +=1;
        // printf("\n level : %d, val : %d \n", level, node->left->val);
        // printf("\n level : %d, val : %d \n", level, node->right->val);
    }
    levelorder(node->left,level+1,ans,index);
    levelorder(node->right,level+1,ans,index);
}


int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    
    TreeNode* pre_root = newroot(0);    
    pre_root -> right = NULL;
    pre_root->left = root; 
    
    *returnSize = maxDepth(root);
    int** ans = malloc(sizeof(int*)*(*returnSize));
    int* index = calloc(*returnSize, sizeof(int));
    *returnColumnSizes = calloc((*returnSize),sizeof(int));
    
    for (int i = 0; i < *returnSize; i++) {
        ans[i] = malloc(sizeof(int) * pow(2, i)); 
    }

    levelorder(pre_root,1,ans,index);
    
    for (int i = 0; i < *returnSize; i++) {       
        returnColumnSizes[0][i] = index[i];
    }
    for (int i = 1; i < *returnSize;i+=2){
        reverse(ans[i],index[i]);
    }
       
    
    return ans;
}