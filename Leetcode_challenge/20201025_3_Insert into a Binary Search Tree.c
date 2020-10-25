// Insert into a Binary Search Tree (medium)
// Runtime: 36 ms, faster than 98.20% of C online submissions for Insert into a Binary Search Tree.
// Memory Usage: 22.7 MB, less than 80.93% of C online submissions for Insert into a Binary Search Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* newnode(int val){
    struct TreeNode* root = calloc(1, sizeof(struct TreeNode));
    root -> val = val;
    return root;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
    if (!root){
        return newnode(val);
    }
    if (val < root -> val){
        root -> left = insertIntoBST(root -> left,  val);
    }
    else if (val > root -> val){
        root -> right = insertIntoBST(root -> right,  val);
    }
    
    return root;
}