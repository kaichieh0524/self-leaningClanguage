// Populating Next Right Pointers in Each Node (medium)
// Runtime: 12 ms, faster than 98.41% of C online submissions for Populating Next Right Pointers in Each Node.
// Memory Usage: 8.5 MB, less than 82.54% of C online submissions for Populating Next Right Pointers in Each Node.

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */


void subroutine(struct Node* root){
    if (root == NULL){return;}    
    if(root->next && root->right){
        root->right->next = root->next->left;
    }
    if (root->right){
        root->left->next = root->right;
    }    
    subroutine(root->left);
    subroutine(root->right);
   
}
	

struct Node* connect(struct Node* root) {
	subroutine(root);
    return root;
}