// Insert Delete GetRandom O(1) (medium)
// Runtime: 48 ms, faster than 75.38% of C online submissions for Insert Delete GetRandom O(1).
// Memory Usage: 16.6 MB, less than 100.00% of C online submissions for Insert Delete GetRandom O(1).
// using uthash macro
// reference : https://www.twblogs.net/a/5c9e0315bd9eee73ef4b537f

typedef struct hashtable {
    int key;
    int value;
    UT_hash_handle hh; 
} hashtable;



typedef struct {
    int* nums;
    int index;
    hashtable* table;    
} RandomizedSet;

/** Initialize your data structure here. */

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* randomizedset = malloc(sizeof(RandomizedSet));
    randomizedset->nums = malloc(sizeof(int)*5000);
    randomizedset->index = 0;
    randomizedset->table = NULL;
    return randomizedset;
    
}

/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
bool randomizedSetInsert(RandomizedSet* obj, int val) {
    hashtable* h; 
    HASH_FIND_INT(obj->table, &val, h);
    
    if (!h) {
        h = malloc(sizeof(hashtable));
        h->key = val;        
        obj->nums[obj->index] = val;
        h->value = obj->index;
        obj->index++;
        HASH_ADD_INT(obj->table, key, h);
        
        return true;
    }
    
    return false;
}

/** Removes a value from the set. Returns true if the set contained the specified element. */
bool randomizedSetRemove(RandomizedSet* obj, int val) {
    hashtable *h1, *h2; 
    HASH_FIND_INT(obj->table, &val, h1);
    
   
    if (h1) {
        obj->nums[h1->value] = obj->nums[obj->index-1]; 
        HASH_FIND_INT(obj->table, &obj->nums[obj->index-1], h2);
        h2->value = h1->value;
        obj->index--;
        HASH_DEL(obj->table, h1);
        
        return true;
    }
    
    return false;
}

/** Get a random element from the set. */
int randomizedSetGetRandom(RandomizedSet* obj) {
    return obj->nums[rand()%obj->index];
}

void randomizedSetFree(RandomizedSet* obj) {    
    free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 
 * bool param_2 = randomizedSetRemove(obj, val);
 
 * int param_3 = randomizedSetGetRandom(obj);
 
 * randomizedSetFree(obj);
*/