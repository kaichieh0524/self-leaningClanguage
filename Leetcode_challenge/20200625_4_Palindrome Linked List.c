// Palindrome Linked List (easy)
// Runtime: 12 ms, faster than 69.93% of C online submissions for Palindrome Linked List.
// Memory Usage: 11 MB, less than 7.91% of C online submissions for Palindrome Linked List.
// key idea : use reverse linked list, and compare each val.

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

bool isPalindrome(struct ListNode* head){
    if (head==NULL) {return 1;}
    struct ListNode* reverse = reverseList(head);
    while (reverse || head)
    {
        if (reverse -> val != head -> val ){return 0;}
        else
        {
            reverse = reverse -> next ? reverse -> next : NULL;
            head = head -> next ? head -> next : NULL;
        }
        
    }
    return 1;
}