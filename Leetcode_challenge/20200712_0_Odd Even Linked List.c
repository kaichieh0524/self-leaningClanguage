// Odd Even Linked List (medium)
// Runtime: 4 ms, faster than 94.39% of C online submissions for Odd Even Linked List.
// Memory Usage: 6.5 MB, less than 97.69% of C online submissions for Odd Even Linked List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (!head){return NULL;}
    struct ListNode* odd = head;
    struct ListNode* evenhead = head -> next;
    if(evenhead==NULL){return head;}
    struct ListNode* even = head -> next;
    struct ListNode* temp = head -> next -> next;
    int flag = 1;
    
    while(temp){
        if (flag%2==1){
            odd -> next = temp;
            odd = odd -> next;
            temp = temp -> next;
            flag = (flag + 1)%2;
        }
        else{
            even -> next = temp;
            even = even -> next;
            temp = temp -> next;
            flag = (flag + 1)%2;
        }
    }
    odd -> next = evenhead;
    even -> next = NULL;
    
    
    return head;
}