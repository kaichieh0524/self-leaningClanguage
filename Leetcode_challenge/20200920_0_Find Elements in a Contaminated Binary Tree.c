// Find Elements in a Contaminated Binary Tree (medium)
// Runtime: 56 ms, faster than 25.00% of C online submissions for Find Elements in a Contaminated Binary Tree.
// Memory Usage: 47.6 MB, less than 12.50% of C online submissions for Find Elements in a Contaminated Binary Tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    bool* ele ;
} FindElements;

void travel(struct TreeNode* root, int val, bool* ele){
    if (!root){return;}
    ele[val] = 1;
    if(root->left != NULL){
        //ele[2*val + 1] = 1;
        travel(root->left,2*val+1,ele);
    }
    if(root->right != NULL){
        //ele[2*val + 2] = 1;
        travel(root->right,2*val+2,ele);
    }
}

FindElements* findElementsCreate(struct TreeNode* root) {
    FindElements* elements = malloc(sizeof(FindElements));
    elements -> ele = calloc(10000000,sizeof(bool));
    travel(root,0,elements->ele);
    return elements;
}

bool findElementsFind(FindElements* obj, int target) {
  return obj->ele[target];
}

void findElementsFree(FindElements* obj) {
    free(obj->ele);
    free(obj);
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/