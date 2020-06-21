//Best Time to Buy and Sell Stock (easy)

//Runtime: 804 ms, faster than 17.63% of C online submissions for Best Time to Buy and Sell Stock.
//Memory Usage: 7.3 MB, less than 5.10% of C online submissions for Best Time to Buy and Sell Stock.


int f(int* price,int x){
    int max = 0;
    for (int i = 0 ; i < x-1 ; i++){
        if (max < price[x-1]-price[i]){
            max = price[x-1]-price[i];
        }
    }
    return  max;
}
int sub_routine(int* price, int n){
    if (n==0 || n==1){return 0;}
       
    
    if (n == 2 ){
        if (price[1]-price[0]>0){return price[1]-price[0];}
        else{return 0;}
    }
    else
    {
        return fmax(sub_routine(price,n-1),f(price,n));    
    }
}

int findmaxmin(int* prices, int pricesSize){
    int max =prices[0];
    int min =prices[0];
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0 ; i < pricesSize ; i++){
        if (max < prices[i]){
            max = prices[i];
            flag1 = i;
        }
        if (prices[i] < min){
            min = prices[i];
            flag2 = i;
        }
    }
    if (flag1>flag2){return max-min;}
    else {return 0;}
    
}

int maxProfit(int* prices, int pricesSize){
    if (pricesSize==0 || pricesSize==1){return 0;}
    int ans =  findmaxmin( prices,  pricesSize);
    if (ans!=0) {return ans;}
    else{
       return sub_routine( prices, pricesSize); 
    }
   
}