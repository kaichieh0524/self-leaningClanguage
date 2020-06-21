// Linked List Cycle (easy)
// Runtime: 8 ms, faster than 77.33% of C online submissions for Linked List Cycle.
// Memory Usage: 7 MB, less than 30.28% of C online submissions for Linked List Cycle.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (head == NULL ){return 0;}
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    while( p2 -> next != NULL && p2 -> next -> next != NULL)
    {        
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1==p2){return 1;}
        
    }
    return 0;
}



