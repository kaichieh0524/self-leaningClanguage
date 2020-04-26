# include <stdio.h>
# include <stdlib.h>
int main(){
    int integer1;
    int integer2;
    int sum;


    printf("Please enter the first integer: ");
    scanf("%d", &integer1);
    printf("Please enter the second integer: ");
    scanf("%d", &integer2);


    sum = integer1 + integer2;
    printf("Sum is %d.\n", sum);
    system ("pause");

    /*  

        use less memory

        int integer, sum;

        printf("Please enter the first integer: ");
        scanf("%d", &integer);
        sum = integer
        printf("Please enter the second integer: ");
        scanf("%d", &integer);
        sum = sum + integer;
        printf("Please enter the third integer: ");
        scanf("%d", &integer);
        sum = sum + integer;
        printf("Sum is %d.\n", sum);
        return 0;

    */
    return 0;

}