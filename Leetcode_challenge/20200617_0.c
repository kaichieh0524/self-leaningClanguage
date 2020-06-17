//Valid Parentheses (easy)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 0 ms, faster than 100.00% of C online submissions for Valid Parentheses.
// Memory Usage: 5.5 MB, less than 11.74% of C online submissions for Valid Parentheses.
// main idea : using link list last in first out

typedef struct linklist {
    char val;
    struct linklist *previous;
}linklist;


bool isValid(char* s){
    linklist* temp = NULL;
    linklist* current = malloc(sizeof(linklist));
    int counter = -1;   
    current->previous = NULL;

    if (s[0] == 0){
        return true;
    }
    
    
    
    while (s[counter+1]!= '\0')
    {
        
        if (current == NULL) {
            linklist* current1 = malloc(sizeof(linklist));
            current = current1;
            current->previous = NULL;
        }
        counter = counter +1;
        current-> val = s[counter];
   

        while (s[counter + 1] - current->val == 1 || s[counter + 1] - current->val == 2)
        {
            temp = current;
            current = current->previous;
            counter = counter + 1;
            free(temp);
            if (current == NULL) {
                break;
            }
        }
        if (current != NULL) {
            if (s[counter + 1] - current->val != 1 && s[counter + 1] - current->val != 2) {
                
                linklist* intermediate = malloc(sizeof(linklist));
                temp = intermediate;
                temp->previous = current;
                current = temp;
            }
        }
        
        
        
    }

    if (current == NULL) {
        printf("This is valid.");
        return true;
        
    }
    else
    {   
        printf("This is invalid");
        return false;        
    }
    


}