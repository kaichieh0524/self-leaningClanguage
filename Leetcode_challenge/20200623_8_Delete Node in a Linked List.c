// Delete Node in a Linked List (easy)
// Runtime: 4 ms, faster than 92.24% of C online submissions for Delete Node in a Linked List.
// Memory Usage: 6 MB, less than 75.38% of C online submissions for Delete Node in a Linked List.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if (node->next == NULL) {node= NULL;}
    struct ListNode* temp = node -> next;
    node -> val = (node -> next) -> val;
    node -> next = node -> next -> next ? node -> next -> next : NULL;
    free(temp);    
}