// Evaluate Reverse Polish Notation (medium)
// Runtime: 8 ms, faster than 85.11% of C online submissions for Evaluate Reverse Polish Notation.
// Memory Usage: 7.3 MB, less than 24.47% of C online submissions for Evaluate Reverse Polish Notation.


int evalRPN(char ** tokens, int tokensSize){
    int* temp = calloc(tokensSize, sizeof(int));
    int index = -1;
    int ans = atoi(tokens[0]);
    char operator;

    for (int i = 0; i < tokensSize; i++) {
        if (isdigit(tokens[i][0])) {
            index++;
            temp[index] = atoi(tokens[i]);
        }
        else if (!isdigit(tokens[i][0]) && isdigit(tokens[i][1])) {
            index++;
            temp[index] = atoi(tokens[i]);
        }
        if (!isdigit(tokens[i][0]) && tokens[i][1] == '\0') {
            operator = tokens[i][0];
            if (operator == '+') {
                temp[index-1] = temp[index] + temp[index - 1];
                index--;
                ans = temp[index];
            }
            if (operator == '-') {
                temp[index-1] = temp[index - 1] - temp[index];
                index--;
                ans = temp[index];
            }
            if (operator == '*') {
                temp[index-1] = temp[index - 1] * temp[index];
                index--;
                ans = temp[index];
            }
            if (operator == '/') {
                temp[index-1] = temp[index - 1] / temp[index];
                index--;
                ans = temp[index];
            }
        }
    }
    printf("%d", ans);
    return ans;
}