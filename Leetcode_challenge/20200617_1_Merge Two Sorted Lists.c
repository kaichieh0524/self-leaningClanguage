//Merge Two Sorted Lists (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 0 ms, faster than 100.00% of C online submissions for Merge Two Sorted Lists.
// Memory Usage: 6 MB, less than 12.24% of C online submissions for Merge Two Sorted Lists.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

double infinity = INFINITY;

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    
    if ( l1==0 && l2==0){
        return NULL;
    }
    
    
    struct ListNode* ans = malloc(sizeof(struct ListNode));
    struct ListNode* temp = ans;
    

    
    
    while (l1 || l2)
    {
        if ((l1 ? l1->val : infinity ) <= (l2 ? l2->val : infinity ) ){
            temp -> val = l1->val;
            l1 = l1? l1 -> next : NULL; 
        }
        else
        {
            temp -> val = l2->val;
            l2 = l2? l2 -> next : NULL; 
        }
        if (l1 || l2)
        {
            temp -> next =  malloc(sizeof(struct ListNode));
            temp = temp -> next;
        }
        
    }
    
    temp -> next = NULL;
    
    return ans;

}