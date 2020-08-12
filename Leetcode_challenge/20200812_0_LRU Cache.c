// LRU Cache (medium)
// Runtime: 196 ms, faster than 13.33% of C online submissions for LRU Cache.
// Memory Usage: 24 MB, less than 94.82% of C online submissions for LRU Cache.
    
typedef struct unit {
    int key;
    int value;
    int priroity;
} unit;



typedef struct {
    unit* list;
    int size;
    int now;
} LRUCache;


LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = malloc(sizeof(LRUCache));
    cache -> list = calloc(capacity,sizeof(unit));
    cache -> size = capacity;
    cache -> now = 0;
    for (int i = 0; i < cache -> size; i++){
        cache -> list[i].key = -1;
    }
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
  for (int i = 0; i < obj -> size; i++){
      if (obj -> list[i].key == key){
          obj -> now ++;
          obj -> list[i].priroity = obj -> now;
          return obj -> list[i].value;
      }
  }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    
    for (int i = 0; i < obj -> size; i++){
      if (obj -> list[i].key == key){
          obj -> list[i].value = value;
          obj -> now ++;
          obj -> list[i].priroity = obj -> now;
          return ;
       }
     }
    for (int i = 0; i < obj -> size; i++){
      if (obj -> list[i].key == -1){
          obj -> list[i].key = key;
          obj -> list[i].value = value;
          obj -> now ++;
          obj -> list[i].priroity = obj -> now;
          return ;
      }
  }
    int min = 0;
    for (int i = 0; i < obj -> size; i++){
      if (obj -> list[i].priroity < obj -> list[min].priroity){
          min = i;
      }     
    }
      obj -> list[min].key = key;
      obj -> list[min].value = value;
      obj -> now ++;
      obj -> list[min].priroity = obj -> now;
      return ;

     
}

void lRUCacheFree(LRUCache* obj) {
    free(obj->list);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/