// sqrt(x) (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>
#define max 2147483647
#define min 0

// Runtime: 0 ms, faster than 100.00% of C online submissions for Sqrt(x).
// Memory Usage: 5.3 MB, less than 25.79% of C online submissions for Sqrt(x).
// key idea : using binary search the complexity is O(log_2 n)

int mySqrt(int x){
    
    double flag1= max;
	double flag2 = min;
	double flag_inter = (flag1 + flag2) / 2;
	double temp;

	while (flag1 != flag2 && flag_inter!=0) {
		temp = flag_inter * flag_inter;
		if (temp < x)
		{
			flag2 = flag_inter;
			flag_inter= (flag1 + flag2) / 2;
		}
		else if (temp > x)
		{
			flag1 = flag_inter;
			flag_inter = (flag1 + flag2) / 2;
		}
		else
		{
			printf("the ans is :%d\n", (int) flag_inter);
            return (int) flag_inter;
		}
		if ((int) flag1 - (int) flag2 == 0) {
			printf("the ans is :%d\n", (int) flag1);           
			break;
		}
	}
    
    
     return (int) flag1;
}