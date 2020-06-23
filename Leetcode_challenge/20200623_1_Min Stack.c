// Min Stack (easy)
// Runtime: 28 ms, faster than 84.33% of C online submissions for Min Stack.
// Memory Usage: 13.1 MB, less than 30.00% of C online submissions for Min Stack.
// key idea : creat two array, one of them store data, the other of them store the min
// and two pointers..... 

typedef struct {
    int stack[10000];
    int min[10000];
    int index1;
    int index2;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* new = malloc(sizeof(MinStack));
    new -> index1 = -1;
    new -> index2 = -1;
    memset(new->stack, 0, 20000);
    memset(new->min, 0, 20000);
    return new;
}

void minStackPush(MinStack* obj, int x) {
    obj -> index1++;
    (obj->stack)[obj->index1]=x;
    if(obj -> index2==-1 || x <= (obj->min)[obj->index2])
    {
        obj -> index2++;
        (obj -> min)[obj->index2]=x;
        
    }
}

void minStackPop(MinStack* obj) {
  if (obj -> index1==-1){return;}
  if ((obj -> stack)[obj -> index1] == (obj -> min)[obj -> index2])
  {
      obj -> index2--;
  }
  obj -> index1--;
}

int minStackTop(MinStack* obj) {
  return (obj->stack)[obj->index1];
}

int minStackGetMin(MinStack* obj) {
  return (obj->min)[obj->index2];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/