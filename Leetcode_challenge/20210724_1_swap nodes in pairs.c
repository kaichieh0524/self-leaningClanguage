// Swap Nodes in Pairs (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Swap Nodes in Pairs.
// Memory Usage: 5.9 MB, less than 64.75% of C online submissions for Swap Nodes in Pairs.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* temp = calloc(1, sizeof(struct ListNode));
    temp -> next = head;
    if(!head){return head;}
    struct ListNode* first = head;
    if(!first->next){return head;}
    struct ListNode* second = first -> next;
    struct ListNode* newhead = second;
    while(1){
        struct ListNode* temp1 = second ->next;
        temp -> next = second;
        second -> next = first;
        first -> next = temp1;
        temp = first;
        first = first->next ? first->next : NULL;
        if(!first){ break;}
        second = first->next ? first->next : NULL;
        if(!second){ break;}
    }
    return newhead;
}
