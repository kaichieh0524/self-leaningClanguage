//  Intersection of Two Linked Lists (easy)

// Approach 1 (my first idea)
// Runtime: 820 ms, faster than 6.29% of C online submissions for Intersection of Two Linked Lists.
// Memory Usage: 13.5 MB, less than 72.32% of C online submissions for Intersection of Two Linked Lists.
// It should be modified.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {return NULL;}
    struct ListNode* p1 = headA;
    struct ListNode* p2 = headB;
    
    if (p1==p2){return p1;}
    
    while (p1!=p2 && p1  != NULL)
    {   struct ListNode* temp = p2;
        while (p1!=temp && temp != NULL)
        {            
            temp = temp -> next ? temp -> next :NULL;
            if (temp == p1) {return temp;}
        }
        p1 = p1 -> next ? p1 -> next : NULL;
        if (p2 == p1) {return p1;}
    }
    return NULL;
}

// Approach 2
// Runtime: 32 ms, faster than 95.09% of C online submissions for Intersection of Two Linked Lists.
// Memory Usage: 13.7 MB, less than 18.80% of C online submissions for Intersection of Two Linked Lists.

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {return NULL;}
   
    struct ListNode* p1 = headA;
    struct ListNode* p2 = headB;
    
    while (p1!=p2)
    {
        p1 = (p1 != NULL) ? p1 -> next : headB;
        p2 = (p2 != NULL) ? p2 -> next : headA;
    }
    return p1;
}