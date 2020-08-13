// Course Schedule II (medium)
// Runtime: 20 ms, faster than 96.00% of C online submissions for Course Schedule II.
// Memory Usage: 68.6 MB, less than 27.20% of C online submissions for Course Schedule II.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){

    //initialize
    int totalnum = 0;
    int* indegree = calloc(numCourses, sizeof(int));
    int** neighbor = calloc(numCourses, sizeof(int*));
    for (int i = 0; i < numCourses; i++){
        neighbor[i] = malloc(numCourses*sizeof(int));
    }
    int* index = calloc(numCourses, sizeof(int));
    
    for (int i = 0; i < prerequisitesSize; i++){
        indegree[prerequisites[i][0]] += 1;
        neighbor[prerequisites[i][1]][index[prerequisites[i][1]]] = prerequisites[i][0];
        index[prerequisites[i][1]]++;
    }    
    //find zero indegree
    
    int* temp = calloc(numCourses, sizeof(int));
    int indextemp = 0;
    
    for (int i = 0; i < numCourses; i++){
        if (indegree[i] == 0){
            temp[indextemp] = i;
            indextemp++;
        }
    }
    int* ans = calloc(numCourses, sizeof(int));;
    int ansindex = 0;
    indextemp--;    
    while(indextemp >= 0){        
        int t = temp[indextemp];
        ans[ansindex] = t;
        ansindex++;
        indextemp--;        
        totalnum+=1;
        for (int i = 0; i < index[t]; i++){
            indegree[neighbor[t][i]]-=1; 
            if (indegree[neighbor[t][i]] == 0){
                indextemp+=1;
                temp[indextemp] = neighbor[t][i];
            }
        }
    }    
    if (totalnum == numCourses){*returnSize=totalnum; return ans;}
    *returnSize=0;
    return NULL;
}