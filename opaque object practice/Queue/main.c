#include "wrapped_queue.h"


int main(int argc, char *argv[]){

    int res = 0;
    int temp;
    pQueue queue = make_Queue(10);

    res = enqueue(queue , 1);
    if(res < 0){
        printf("enqueue error\n");
        return -1;
    }
    res = enqueue(queue , 2);
    if(res < 0){
        printf("enqueue error\n");
        return -1;
    }
    res = enqueue(queue , 3);
    if(res < 0){
        printf("enqueue error\n");
        return -1;
    }
    res = enqueue(queue , 4);
    if(res < 0){
        printf("enqueue error\n");
        return -1;
    }

    res = dequeue(queue, &temp);
    if(res < 0){
        printf("dequeue error\n");
        return -1;
    }   
    printf("dequeue element: %d\n", temp);
    return 0;
}