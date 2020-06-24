//  Reverse Linked List (easy)
// Runtime: 4 ms, faster than 76.14% of C online submissions for Reverse Linked List.
// Memory Usage: 6.2 MB, less than 10.39% of C online submissions for Reverse Linked List.
// key idea just reverse and need scan one time linked list, but it comsume much memory space.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL){return NULL;}
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    temp -> next = NULL;
    
    while (head != NULL)
    {
        temp -> val = head -> val;
        if ( head -> next != NULL){
            struct ListNode* inter = malloc(sizeof(struct ListNode));
            inter -> next = temp;
            temp = inter;
        }
        
        head = head -> next ? head -> next : NULL;
    }
    return temp;
}