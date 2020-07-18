// Sort List (medium)
// Runtime: 1244 ms, faster than 8.23% of C online submissions for Sort List.
// Memory Usage: 8.3 MB, less than 58.73% of C online submissions for Sort List.
// it can be modified by using extra memory space and then using sorting with complexity O(nlog n). Next step,
// rewrite the value into the linked list.
    
    
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* sortList(struct ListNode* head){
    if (head == NULL) {return NULL;}
    
    struct ListNode* current = head;
    struct ListNode* temp;
    int temp1;
    
    while (current){
        temp = current -> next;        
        while(temp){
            if (current -> val > temp -> val){
                temp1 = temp -> val;
                temp -> val = current -> val;
                current -> val = temp1;
            }
            temp = temp -> next;
        }
        current = current -> next;
    }
return head;
}