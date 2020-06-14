// String to Integer (atoi)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

#define max 2147483647
#define min -2147483648
#define max_len 10


int myAtoi(char * str){
    
    int flag1 = 0;
    int sign;
    char *ptr1 = str;
    char *ptr2 = NULL;
    char *ptr3 = NULL;
    double number ;
    
    
    
    if (strlen(str) == 0) {
        return 0;
    }
    
    else {
        
        //the first element's pointer not ' '.
        
        printf("origin string : ");
        while( (*ptr1) != '\0'){
                        
            if (*ptr1 != ' '){
                flag1 = 1;
                break;
            }
            ptr1++;          
        }              
        
        if ( (*ptr1 !=43 && *ptr1 != 45 && (isdigit(*(ptr1))|| 0 )^1) ){
            return 0;
        }
        
        ptr3 = ptr1;
        
        if(*ptr3 == 43 || *ptr3 ==45){
                ptr1++;
        }
            
        
        while( (*ptr1) != '\0' && isdigit(*ptr1) && (*ptr1)==48){
                ptr1++;               
        }
        
        //printf("%d\n%d\n", ptr3,ptr1);
        
        //negative
        ptr2 = ptr1;
        if (*ptr3 == 45 )  {
            printf("%c",(*ptr1));
            sign = -1;            
            
            while (isdigit(*ptr1)){
                printf("%d",(*ptr1)%48);
                number = number*10 + (*ptr1)%48;
                ptr1++;
                if (ptr1-ptr2>12){                    
                    return min;
                    }
                
                }
            number = number*(-1);
            
            }
        else if (*ptr3 == 43 )  {
            printf("%c",(*ptr1));
            sign = 1;   
                        
            while (isdigit(*ptr1)){
                printf("%d",(*ptr1)%48);
                number = number*10 + (*ptr1)%48;
                ptr1++;
                if (ptr1-ptr2>12){                    
                    return max;
                    }
                
                }
            
            }
        else {
            
            while (isdigit(*ptr1)){  
                printf("%d",(*ptr1)%48);
                number = number*10 + (*ptr1)%48;
                ptr1++;
                if (ptr1-ptr2>12){                    
                    return max;
                    }
                
                }
            
        }
        
        if (number <=  max && number  >=  min) {        
        printf("\nresult : %d", (int) number);
        return (int)number;    
        }
        else if (number > max) {        
        printf("\nresult : %d",  max);
        return max;    
         }
        else {        
        printf("\nresult : %d", min);
        return min;   
        }

        
        
            
        
            
        }
        
    }