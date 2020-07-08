// //Remove Linked List Elements (easy)
// Runtime: 16 ms, faster than 29.52% of C online submissions for Remove Linked List Elements.
// Memory Usage: 7.7 MB, less than 52.21% of C online submissions for Remove Linked List Elements.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==NULL){return NULL;}
    while(head -> val == val){
        struct ListNode* temp1 = head;
        head = head -> next ? head-> next : NULL;
        free(temp1);
        if(head==NULL){return head;}
    }
    struct ListNode* temp2 = head;
    struct ListNode* temp3 = head -> next ? head-> next : NULL;
    if (temp3 == NULL && head -> val != val){return head;}
    while(temp3){
        while(temp3 -> val == val){
            struct ListNode* temp4 = temp3;
            temp2 -> next = temp4 -> next;
            temp3 = temp3 -> next ? temp3 -> next : NULL;
            free(temp4);
            if(temp3==NULL){break;}
        }
        if(temp3==NULL){break;}
        temp2 = temp2 -> next ? temp2 -> next : NULL;
        temp3 = temp3 -> next ? temp3 -> next : NULL;
    }
    return head;
}