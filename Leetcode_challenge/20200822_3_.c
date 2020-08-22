// Two City Scheduling (easy)
// Runtime: 4 ms, faster than 93.55% of C online submissions for Two City Scheduling.
// Memory Usage: 5.9 MB, less than 16.13% of C online submissions for Two City Scheduling.


int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    int total = 0;
    for (int i = 0; i < costsSize; i++){
        total += costs[i][0];
    }
    int* difference = calloc(costsSize,sizeof(int)) ;
    for (int i = 0; i < costsSize; i++){
        difference[i] += costs[i][1] - costs[i][0];

    }

    qsort(difference,costsSize,sizeof(int),compare);
    
    for (int i = 0; i < costsSize/2; i++)
    {
        total += difference[i];
    }
    
    return total;
}


