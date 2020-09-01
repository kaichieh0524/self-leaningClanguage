// Convert Binary Number in a Linked List to Integer (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Convert Binary Number in a Linked List to Integer.
// Memory Usage: 5.3 MB, less than 54.66% of C online submissions for Convert Binary Number in a Linked List to Integer.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    int number = 0;
    while(head!=NULL){
        number = number*2 + head->val;
        head = head -> next;
    }
    return number;
}