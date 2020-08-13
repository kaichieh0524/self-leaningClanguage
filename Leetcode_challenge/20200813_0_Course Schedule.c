// Course Schedule (medium)
// Runtime: 28 ms, faster than 65.85% of C online submissions for Course Schedule.
// Memory Usage: 67.9 MB, less than 30.08% of C online submissions for Course Schedule.


bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    if (prerequisitesSize == 0){return 1;}
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
    
    indextemp--;    
    while(indextemp >= 0){        
        int t = temp[indextemp];        
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
    return totalnum == numCourses;
}

