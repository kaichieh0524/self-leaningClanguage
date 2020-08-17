// Fraction to Recurring Decimal (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Fraction to Recurring Decimal.
// Memory Usage: 5.8 MB, less than 7.14% of C online submissions for Fraction to Recurring Decimal.


char * fractionToDecimal(int numerator, int denominator){
    int index = -1, index1 = 0, pointindex, flag = 0, sign = 0, cnt = 0;
    if ((numerator < 0 && denominator >0) || (numerator > 0 && denominator < 0) ){sign = 1;}
    long long int numerator1 = numerator; 
    long long int denominator1 = denominator; 
    numerator1 = llabs(numerator);
    denominator1 = llabs(denominator);   
    char* ans = malloc(4096*sizeof(char));
    char* temp = calloc(1000,sizeof(char));
    long long int *hash = malloc(sizeof(long long int)*1000);
    if (sign == 1){cnt += sprintf(ans + cnt, "%c", '-');}
    cnt += sprintf(ans + cnt, "%lld", numerator1/denominator1);
    long long int remainder = numerator1 % denominator1;
    if (remainder){
        cnt += sprintf(ans + cnt, "%c", '.');
        pointindex = cnt;
    }
       
    while(remainder){
        remainder *= 10;
        int d =  remainder / denominator1;
        
        for (int i = 0; i < index1; i++){
            if (hash[i] == remainder ){                
                index = i;
                break;
            }           
        }       
        
        if (index>=0){            
            strcat(temp,ans+index+pointindex);            
            ans[pointindex+index] = '(';      
            ans[pointindex+index+1] = '\0';
            strcat(ans,temp);
            strcat(ans,")");
            break;
        }
        
        hash[index1++] = remainder;
        cnt += sprintf(ans + cnt, "%lld", d);
        remainder %= denominator1;
        
    }
    return ans;

}