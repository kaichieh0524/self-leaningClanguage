// Remove Nth Node From End of List (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Remove Nth Node From End of List.
// Memory Usage: 5.6 MB, less than 5.68% of C online submissions for Remove Nth Node From End of List.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int len = 1;
    int target;
    struct ListNode* add = head;
    if (add -> next == NULL){return NULL;}
    while (add -> next != NULL){
        add = add -> next;
        len++;
    }
    printf("len :%d\n",len);
    add = head;
    target = len - n + 1;
    if (target ==1){head = head -> next; return head;}
    printf("target :%d",target);
    for (int i = 0; i < target - 2; i++){
        add = add -> next;
    }
    struct ListNode* temp = add -> next;
    add -> next = temp -> next;
    free(temp);
    return head;
}