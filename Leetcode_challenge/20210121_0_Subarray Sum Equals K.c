// Subarray Sum Equals K (medium)
// Runtime: 56 ms, faster than 60.47% of C online submissions for Subarray Sum Equals K.
// Memory Usage: 25.2 MB, less than 44.19% of C online submissions for Subarray Sum Equals K.

typedef struct {
    int key, val;
    UT_hash_handle hh;
}   element;


int subarraySum(int* nums, int numsSize, int k){
    element *hash = NULL, *temp, *ele;
    int count = 0;
    int ans = 0;
    ele = malloc(sizeof(element));
    ele -> key = 0;
    ele -> val = 1;
    HASH_ADD_INT(hash, key, ele);
    for (int i = 0; i < numsSize; i++){
        count+=nums[i];
        int target = count - k;
        HASH_FIND_INT(hash, &target, temp);
        if(temp){
            ans += temp -> val;
        }
        HASH_FIND_INT(hash, &count, temp);
        if(!temp){
            ele = malloc(sizeof(element));
            ele -> key = count;
            ele -> val = 1;
            HASH_ADD_INT(hash, key, ele);
        }
        else{
            (temp -> val) ++;
        }

    }
    // unsigned int num_users;
    // num_users = HASH_COUNT(hash);
    // printf("there are %u users\n", num_users);
    // for(element *s=hash; s != NULL; s=s->hh.next) {
    //     printf("key  %d: times %d\n", s->key, s->val);
    // }
    return ans;
}