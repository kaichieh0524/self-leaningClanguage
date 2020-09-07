// Best Time to Buy and Sell Stock with Cooldown (medium)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Best Time to Buy and Sell Stock with Cooldown.
// Memory Usage: 5.7 MB, less than 33.33% of C online submissions for Best Time to Buy and Sell Stock with Cooldown.


int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0){return 0;}
    int temp1[pricesSize];
    int temp2[pricesSize];
    
    temp1[0] = 0;
    temp2[0] = -prices[0];
    for (int i = 1; i < pricesSize; i++){
        temp1[i] = fmax(temp1[i-1], temp2[i-1]+prices[i]);
        temp2[i] = fmax(temp2[i-1], (i>1? temp1[i-2] : 0) - prices[i]);
    }
    return temp1[pricesSize-1];
}



