#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int size, front, rear;
    int* array;
    int capacity;
 }queue_t;

queue_t* _make_queue(int capacity);

int _enqueue(queue_t* queue, int item);

int _dequeue(queue_t* queue, int* o_item);
