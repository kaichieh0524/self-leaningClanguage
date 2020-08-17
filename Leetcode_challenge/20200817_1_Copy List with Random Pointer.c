// Copy List with Random Pointer (medium)
// Runtime: 8 ms, faster than 90.37% of C online submissions for Copy List with Random Pointer.
// Memory Usage: 8.3 MB, less than 5.19% of C online submissions for Copy List with Random Pointer.


/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct TreeNode *next;
 *     struct TreeNode *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if (!head) {return NULL;}
    int index1 = 0, index2 = 0, index3;
    int* address1 = malloc(sizeof(int)*1024);
    int* address2 = malloc(sizeof(int)*1024);
	struct Node* temp1 = head;
    struct Node* copy = malloc(sizeof(struct Node));
    struct Node* temp2 = copy;
    
    while(temp1){
        temp2 -> val = temp1 -> val;
        address1[index1++] = temp1;
        address2[index2++] = temp2;
        if (temp1 -> next){
            struct Node* temp3 = malloc(sizeof(struct Node));
            temp2 -> next = temp3;
            temp2 = temp2 -> next;            
         }
        temp1 = temp1 -> next;
    }
    address1[index1++] = NULL;
    address2[index2++] = NULL;
    temp2 -> next = NULL;
    
    temp1 = head;
    temp2 = copy;
    while(temp1){
        int temp4 = temp1 -> random;
        for (int i = 0; i < index1; i++){
            if (temp4 == address1[i]){
                index3 = i;
                break;
            }
        }
        temp2 -> random = (struct Node*) address2[index3];        
        temp1 = temp1 -> next;
        temp2 = temp2 -> next;
    }
      return copy;
}