// Validate Binary Search Tree (medium)
// Runtime: 8 ms, faster than 78.07% of C online submissions for Validate Binary Search Tree.
// Memory Usage: 9.4 MB, less than 5.26% of C online submissions for Validate Binary Search Tree.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count = 0;
// void countInorder(struct TreeNode* root) 
// { 
//      if (root == NULL) 
//           return; 
//      countInorder(root->left); 
//      count += 1;   
//      countInorder(root->right); 
// } 
void Inorder(struct TreeNode* root, int* ordered) 
{ 
     if (root == NULL) 
          return; 
     Inorder(root->left,ordered); 
     ordered[count] = root ->val;
     count += 1;   
     Inorder(root->right,ordered); 
}  



bool isValidBST(struct TreeNode* root){
    // count = 0;
    // countInorder(root);
    int* ordered = malloc(sizeof(int)*10000);
    count = 0;
    Inorder(root,ordered);
    
    for (int i = 1; i < count; i++){
        if (ordered[i] <= ordered[i-1]){return 0;}
    }

    return 1;
}