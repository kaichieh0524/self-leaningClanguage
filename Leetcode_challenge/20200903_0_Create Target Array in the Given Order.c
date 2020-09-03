// Create Target Array in the Given Order (easy)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Create Target Array in the Given Order.
// Memory Usage: 5.7 MB, less than 38.74% of C online submissions for Create Target Array in the Given Order.


typedef struct linkedlist{
    int val;
    struct linkedlist* next;
}linkedlist;

linkedlist* createnode(int val){
    linkedlist* node = malloc(sizeof(linkedlist));
    node -> val = val;
    node -> next = NULL;
    return node;
}


linkedlist* insertion(linkedlist* head, int index, int val){
    if (index == 0){
        linkedlist* newhead = createnode(val);
        newhead->next = head;
        head = newhead;
        return head;
    }
    int count = 1;
    linkedlist* cur = head->next;
    linkedlist* pre = head;
    while(count != index){
        cur = cur -> next;
        pre = pre -> next;
        count++;
    }
    
    linkedlist* newnode = createnode(val);
    pre -> next = newnode;
    newnode -> next = cur;   
    return head;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize){
    if(numsSize == 0){return NULL;}
    int* ans = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    linkedlist* head = createnode(nums[0]);
    for (int i = 1; i < numsSize; i++){
        head = insertion(head, index[i], nums[i]);
    }
    int n = 0;
    while(head){
        printf(" %d ", head->val);
        ans[n++] = head->val;
        head = head->next;        
    }
    return ans;
}