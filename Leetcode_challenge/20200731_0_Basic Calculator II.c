// Basic Calculator II (medium)
// untime: 28 ms, faster than 26.67% of C online submissions for Basic Calculator II.
// Memory Usage: 13.1 MB, less than 25.00% of C online submissions for Basic Calculator II.

int calculate(char * s){
    int* nums = calloc(100000,sizeof(int));
    char operator = '+';
    int current = 0;
    int index = 0;
    int index1 = 0;
    int len = strlen(s);
    int ans = 0;
    while( index < len ){
        if (s[index]==' '){
            index+=1;
            continue;
        }
        
        while (isdigit(s[index]) && index < len ){
            current = current * 10 + (s[index++] - '0');
        }
        if (operator == '+'){
            nums[index1++] = current;            
        }
        else if ( operator == '-'){
            nums[index1++] = -current;
        }
        else if (operator == '*'){
            index1 -= 1;
            nums[index1] *= current;
            index1++;
        }
        else if (operator == '/'){
            index1 -= 1;
            nums[index1] /= current;
            index1++;
        }
        current = 0;
        operator = s[index++];
    }
    for (int i = 0; i < 100000; i++){
        ans += nums[i];
    }
    
    return ans;
  
}  
    