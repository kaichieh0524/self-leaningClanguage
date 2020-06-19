// Merge Sorted Array (easy)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include <stdbool.h>

// Runtime: 4 ms, faster than 78.83% of C online submissions for Merge Sorted Array.
// Memory Usage: 5.9 MB, less than 36.54% of C online submissions for Merge Sorted Array.

double min = -INFINITY;


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int len = n+m-1;
    m-=1;
    n-=1;
        while (m != -1 || n != -1) {

        //printf("nums1 [m] :%d\n nums2[n] : %d", nums1[m], nums2[n]);
        
        
        if (((m != -1) ? nums1[m] : min) >= ((n != -1) ? nums2[n] : min)) {
            nums1[len] = nums1[m];
            len -= 1;
            m = (m != -1) ? m - 1 : -1;
        }
        else
        {
            nums1[len] = nums2[n];
            n = (n != -1) ? n - 1 : -1;
            len -= 1;
        }

    }
}