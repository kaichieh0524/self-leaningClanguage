//  All Elements in Two Binary Search Trees (medium)
// Runtime: 276 ms, faster than 29.12% of C online submissions for All Elements in Two Binary Search Trees.
// Memory Usage: 58.8 MB, less than 6.59% of C online submissions for All Elements in Two Binary Search Trees.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



void Postorder(struct TreeNode* node, int* size, int* list){ 
     if (node == NULL) 
        return;
     Postorder(node->left, size, list);
     Postorder(node->right, size, list);  
     list[(*size)++] = node -> val;
     
} 
  

int cmp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int* list1 = malloc(sizeof(int)*5000);
    int* list2 = malloc(sizeof(int)*5000);
    int* size1 = calloc(1,sizeof(int));
    int* size2 = calloc(1,sizeof(int));
    Postorder(root1,size1,list1);
    Postorder(root2,size2,list2);

    
    *returnSize = *size1+*size2;
    int* ans = malloc(sizeof(int)*(*returnSize));
    
    for (int i = 0; i < *size1; i++){
        ans[i] = list1[i];
    }
    for (int i = 0; i < *size2; i++){
        ans[i+(*size1)] = list2[i];
    }

    qsort(ans, *returnSize,sizeof(int), cmp);
    
    return ans;
}