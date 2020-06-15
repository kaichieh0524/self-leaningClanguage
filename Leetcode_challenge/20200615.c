// add two numbers

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum = 0;
    int carry = 0;
    struct ListNode* answer = malloc(sizeof(struct ListNode));
    struct ListNode* temp = answer;  
    
    while (l1 != NULL || l2 != NULL) {
        int x,y;
        if (l1 != NULL){
             x = l1->val;
            if (l1 -> next != NULL){
                l1 = l1 -> next;
            } else {
                l1 = NULL;
            }
        }
        else {
             x = 0;
        }
        
        if (l2 != NULL){
             y = l2->val;
            if (l2 -> next != NULL){
                l2 = l2 -> next;
            } else {
                    l2 = NULL;
            }
        }
        else {
             y = 0;
        }
        printf("int1 : %d int2 : %d\n", x,y);
        sum = carry+x+y;
        carry = sum/10;
        sum = sum%10;
        printf("sum : %d \n", sum);
        temp -> val = sum;
        printf("address : %d \n", temp);
        
        if (l1 != NULL || l2 != NULL){
            struct ListNode* immediate = malloc(sizeof(struct ListNode));
            temp -> next = immediate;
            temp = temp -> next;
        } else if (carry) {
            struct ListNode* immediate = malloc(sizeof(struct ListNode));
            temp -> next = immediate;
            temp = temp -> next;
            temp -> val = 1;
        }

        //printf("value : %d \n address : %d \n", temp-> val, temp -> next);
        
    }
    
    temp -> next = NULL;
        
    return answer;
}