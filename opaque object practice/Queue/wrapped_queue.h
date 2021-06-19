#include "raw_queue.h"

typedef queue_t Queue;
typedef Queue* pQueue;


pQueue make_Queue(int capacity);

int enqueue(pQueue queue, int item);

int dequeue(pQueue queue, int* o_item);