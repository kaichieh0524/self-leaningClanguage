// Balance a Binary Search Tree (medium)
// Runtime: 84 ms, faster than 25.68% of C online submissions for Balance a Binary Search Tree.
// Memory Usage: 44 MB, less than 9.46% of C online submissions for Balance a Binary Search Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void storevalue(struct TreeNode* root, int* temp, int* count){
    if (!root ){return;}
    storevalue(root->left, temp, count);
    temp[(*count)++] = root -> val;
    storevalue(root->right , temp, count);
}

struct TreeNode* newnode(int val){
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root -> right = NULL;
    root -> left = NULL;
    root -> val = val;
    return root;
}


struct TreeNode* construct(int* temp, int start, int end){
    if (end < start ){
        return NULL;
    }
    int mid = (end+start)/2;
    struct TreeNode* root = newnode(temp[mid]);
    root -> right = construct(temp,mid+1,end);
    root -> left = construct(temp,start,mid-1);
    return root;
}


struct TreeNode* balanceBST(struct TreeNode* root){
    struct TreeNode* ans = malloc(sizeof(struct TreeNode));
    int* temp = malloc(sizeof(int)*10000);
    int* count = calloc(1,sizeof(int));
    storevalue(root,temp,count);
    ans = construct(temp, 0 , *count-1);
    free(temp);
    return ans;
}