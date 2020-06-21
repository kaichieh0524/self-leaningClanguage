//  Best Time to Buy and Sell Stock II (easy)

// Runtime: 4 ms, faster than 90.91% of C online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 6.4 MB, less than 58.76% of C online submissions for Best Time to Buy and Sell Stock II.

int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    for (int i = 1 ; i < pricesSize ; i++){
        int intermediate_val = fmax(0,prices[i]-prices[i-1]);
        profit += intermediate_val;
    }
    return profit;
}