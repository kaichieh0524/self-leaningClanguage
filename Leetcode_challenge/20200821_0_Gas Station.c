// Gas Station (medium)
// Runtime: 128 ms, faster than 19.39% of C online submissions for Gas Station.
// Memory Usage: 6 MB, less than 18.37% of C online submissions for Gas Station.



int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int index = 0;
    for (int i = 0; i < gasSize; i++){
        
        int cur_gas = gas[i] - cost[i];
        if (cur_gas >= 0){
        for (int j = 0 ; j < gasSize - 1; j++){            
            index = (j+i+1)%gasSize;
            cur_gas = cur_gas + gas[index] - cost[index];
            if (cur_gas < 0){break;}            
        }            
        if (cur_gas >= 0 && index == (i-1+gasSize)%gasSize){
            return i;
            }  
        }
    }
    return -1;
}
