#include "wrapped_queue.h"

typedef int (*Enqueue)(queue_t *, int);
typedef int (*Dequeue)(queue_t *, int*);

typedef struct {
    Enqueue enqueue;
    Dequeue dequeue;
}Queue_Service;

Queue_Service* queue_service = NULL;

int init_queue_service(Queue_Service** queue_service){
    if(NULL == (*queue_service = malloc(sizeof(Queue_Service)))){
        printf("queue service init fail\n");
        return -1;
    }
    (*queue_service) -> enqueue = _enqueue;
    (*queue_service) -> dequeue = _dequeue;
    return 0;
}

pQueue make_Queue(int capacity){
    int res = 0; 
    res = init_queue_service(&queue_service);
    if(res < 0){
        return NULL;
    }
    return _make_queue(capacity);
 };

int enqueue(pQueue queue, int item){
     return (queue_service -> enqueue)(queue, item);
 }

int dequeue(pQueue queue, int* o_item){
     return (queue_service -> dequeue)(queue, o_item);
 }

