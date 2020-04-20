# include<stdio.h>
# include<stdbool.h> //use boolean value, ctrl 可查看


int main()
{
   if(true){               //true 不是 1 也可以
       printf("Hello\n");
   }else{
       printf("HiHi!\n");
   }

//relation operators

   int result1 = 10 > 2;
   bool result2 = 10 > 2;  // !result2  true->false, false->true
     
   if(result1){                     // if (x>y)
       printf("That's okay\n"); 
   }
   if(result2){
       printf("That's okay\n");
   }

   /*
   if(){

   }else if(){

   }else if (){

   }else{

   }
    */

   char ssss = 's';
   char aaaa = 'a';
   char ssaa[] = "sa";

   printf("address : %p, sizeof : %ld\n", &ssss, sizeof(ssss));
   printf("address : %p, sizeof : %ld\n", &aaaa, sizeof(aaaa));
   printf("address : %p, sizeof : %ld\n", ssaa, sizeof(ssaa));

   // ssaa[0], ssaa[1]


   return 0;
}