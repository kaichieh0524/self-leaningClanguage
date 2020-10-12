// Sum of Nodes with Even-Valued Grandparent (medium)
// Runtime: 20 ms, faster than 100.00% of C online submissions for Sum of Nodes with Even-Valued Grandparent.
// Memory Usage: 16.1 MB, less than 48.33% of C online submissions for Sum of Nodes with Even-Valued Grandparent.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int sumEvenGrandparent(struct TreeNode* root){
    if(!root){return 0;}
    if (root -> val % 2 == 0){
        if (!root -> right && !root -> left){
            return 0;
        }
        else if (root -> right && !root -> left) {
            if (root -> right -> left && root -> right -> right){
                return root -> right -> left -> val + root -> right -> right -> val +sumEvenGrandparent(root -> right);
            }
            else if (root -> right -> left && !root -> right -> right){
                return root -> right -> left -> val+sumEvenGrandparent(root -> right);
            }
            else if (!root -> right -> left && root -> right -> right){
                return root -> right -> right -> val+sumEvenGrandparent(root -> right);
            }
            else{
                return 0+sumEvenGrandparent(root -> right);
            }
        }
        else if (!root -> right && root -> left) {
            if (root -> left -> left && root -> left -> right){
                return root -> left -> left -> val + root -> left -> right -> val+sumEvenGrandparent(root -> left);
            }
            else if (root -> left -> left && !root -> left -> right){
                return root -> left -> left -> val+sumEvenGrandparent(root -> left);
            }
            else if (!root -> left -> left && root -> left -> right){
                return root -> left -> right -> val+sumEvenGrandparent(root -> left);
            }
            else{
                return 0+sumEvenGrandparent(root -> left);
            }
        }
        else {
            if (root -> right -> left && root -> right -> right && root -> left -> left && root -> left -> right){
                return root -> left -> left -> val + root -> left -> right -> val + root -> right -> left -> val + root -> right -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (root -> right -> left && root -> right -> right && !root -> left -> left && root -> left -> right){
                return  root -> left -> right -> val + root -> right -> left -> val + root -> right -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (root -> right -> left && root -> right -> right && root -> left -> left && !root -> left -> right){
                return root -> left -> left -> val  + root -> right -> left -> val + root -> right -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (!root -> right -> left && root -> right -> right && root -> left -> left && root -> left -> right){
                return root -> left -> left -> val + root -> left -> right -> val  + root -> right -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (root -> right -> left && !root -> right -> right && root -> left -> left && root -> left -> right){
                return root -> left -> left -> val + root -> left -> right -> val + root -> right -> left -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (!root -> right -> left && !root -> right -> right && root -> left -> left && root -> left -> right){
                return root -> left -> left -> val + root -> left -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (!root -> right -> left && root -> right -> right && !root -> left -> left && root -> left -> right){
                return  root -> left -> right -> val +  root -> right -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (!root -> right -> left && root -> right -> right && root -> left -> left && !root -> left -> right){
                return root -> left -> left -> val +  root -> right -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (root -> right -> left && !root -> right -> right && !root -> left -> left && root -> left -> right){
                return  root -> left -> right -> val + root -> right -> left -> val +sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (root -> right -> left && !root -> right -> right && root -> left -> left && !root -> left -> right){
                return root -> left -> left -> val  + root -> right -> left -> val +sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (root -> right -> left && root -> right -> right && !root -> left -> left && !root -> left -> right){
                return  root -> right -> left -> val + root -> right -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (!root -> right -> left && !root -> right -> right && !root -> left -> left && root -> left -> right){
                return  root -> left -> right -> val +sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (!root -> right -> left && !root -> right -> right && root -> left -> left && !root -> left -> right){
                return root -> left -> left -> val +sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (!root -> right -> left && root -> right -> right && !root -> left -> left && !root -> left -> right){
                return  root -> right -> right -> val+sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else if (root -> right -> left && !root -> right -> right && !root -> left -> left && !root -> left -> right){
                return  root -> right -> left -> val +sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
            }
            else {
                return 0;
            }
        }
    }
   
    return sumEvenGrandparent(root -> right) +   sumEvenGrandparent(root -> left);
    
}