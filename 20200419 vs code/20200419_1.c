#include <stdio.h>

int main()
{
    
    char x = 'H';
    char y = 'e';
    printf("%c%cllo world!!\n",x,y); // \n 換行

    printf("%s World!!\n", "Hello");

    char z[] = "Hello"; // 方框號後可以接字串,注意 "和'差別

    printf("%s World!!\n", z);
    //printf("Hello world!!");

    int index = 1; // or (int index=1, total=10;)
    int total = 10;

    // or int index,total
    //    int index=total=1564

    printf("%d\n", index); //print %d 印integer

    int index1;
    index1 = 2;
    // index = index1 同樣int可以asign, index = index1 = total 都是total
    printf("%d\n", index1);




//--------------------------------------------------------------------------------------------
    int value = 0;
    int result = 0;

    result = sizeof(value); //記憶體空間
    printf("%d\n", result);

    /*
    * double->8
    * float->4
    */

    /* complier
    * source code->
    * preporcessor->
    * complier->
    * assembler->
    * object code->
    * linker->
    * executables exe檔

    */
    return 0;
}