# include<stdio.h>
# include<limits.h>
int main()
{
    int total = 0;
    int product1price = 100;
    float x = 0.5;

    total = total + product1price; // total += product1price, computation in ( ) will be run first.

    /*
    * '*' multiply
    * '%' mod
    */


    printf("Number : %d\n ", total);

    printf("%f\n", x);

    int maxInt = INT_MAX;
    float flmaxInt = maxInt;
    printf("max Integer : %d\n", maxInt); // max integer
    printf("max Integer in float : %f\n", flmaxInt);

    //example

    float number = 3.14159268;

    printf("%f\n", number); // 四捨五入小數點第六位

    float y1 = 0.3455550;
    float y2 = 0.6544448;
    printf("%.7f\n", y1 + y2); //print 出小數點後七位
    printf("%f\n", y1 + y2); //進位


    double t1 = 0.345555054354;
    double t2 = 0.65444484354;

    printf("%.16lf\n", t1 + t2); // double %lf, long double %Lf

    /*
    * float       32位元   6-7     有效位數
    * double      64位元   15-16   有效位數
    * long double 128位元  18-19   有效位數
    */

    int r1 = 137;
    float r2 = 0.87;
    printf("%f\n", r1 * r2); //誤差0.000002

    printf("%.2f\n", r1 * r2); //修正 


    //除法注意 float, double. ex int/int is int not float. 
    /*
    * int x = 10
    * int y = 4
    * printf("%d", x/y)=2
    */

    printf("%d\n", (int) 3.14 ); //transfer 3.14 to integer
    printf("%f\n", (float) 20);

    char word = 'c';

    printf("%d\n", (int)word);
    printf("%c\n", (char)98);

    //0b 二進位 0b11111111=255
    //0x 十六進位 0xff





    return 0;
}