// Maximum Binary Tree (medium)
// Runtime: 48 ms, faster than 57.58% of C online submissions for Maximum Binary Tree.
// Memory Usage: 27.4 MB, less than 7.58% of C online submissions for Maximum Binary Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode node;

node* createnode(int val){
    node* root = malloc(sizeof(node));
    root -> val = val;
    root -> right = NULL;
    root -> left = NULL;
    return root;
}

int findmax(int* nums, int l, int r){
    int max = nums[l];
    int index = l;
    for (int i = l + 1; i <= r; i++){
        if (max < nums[i]){
            index = i;
            max = nums[i];
        }
    }
    return index;
}

struct TreeNode* helper(int* nums, int numsSize, int l, int r){
    if (l > r) { return NULL; }
    int i = findmax(nums,l, r);
    node* root = createnode(nums[i]);
    root->right = helper(nums, r - i, i + 1, r);
    root->left = helper(nums, r - l, l, i - 1);
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
   node* root = helper(nums, numsSize, 0, numsSize - 1);
    return root;
}