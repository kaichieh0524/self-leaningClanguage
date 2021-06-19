#include "raw_queue.h"

queue_t* _make_queue(int capacity){
    queue_t* queue = malloc(sizeof(queue_t));
    queue -> array = malloc(sizeof(int)*capacity);
    queue -> size = 0;
    queue -> front = 0;
    queue -> rear = -1;
    queue -> capacity = capacity;
    return queue;
}

bool _is_full(queue_t* queue){
    return (queue -> size == queue -> capacity);
}

bool _is_empty(queue_t* queue){
    return (queue -> size == 0);
}

int _enqueue(queue_t* queue, int item){
    if (queue == NULL || _is_full(queue)){
        printf("input invalid\n");
        return -1;
    }
    queue -> rear  = (queue -> rear + 1) % queue -> capacity;
    queue -> array[queue -> rear] = item;
    (queue -> size)++;
    printf("enqueue %d into queue successfully\n", item);
    return 0;
}

int _dequeue(queue_t* queue, int* o_item){
    if(queue == NULL || _is_empty(queue)){
        printf("the queue is empty");
        return -1;
    }
    int item = queue -> array[queue -> front];
    (queue -> size)--;
    queue -> front = (queue -> front + 1) % queue -> capacity;
    *o_item = item;
    return 0;
}