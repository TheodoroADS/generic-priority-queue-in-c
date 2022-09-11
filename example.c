#include <stdio.h>

#include "priority_queue.h"
// I will be using a priority queue of int


#define PQ_CAPACITY 10


double int_comp(int a, int b){ //comparator to be used in priority queue

    return (double) a - b;

}


int main(){

    priority_queue* queue = priority_queue_new(PQ_CAPACITY, int_comp);

    priority_queue_add(queue , 10);
    priority_queue_add(queue , 2);
    priority_queue_add(queue , 1);
    priority_queue_add(queue , 15);
    priority_queue_add(queue , 9);
    priority_queue_add(queue , 13);
    priority_queue_add(queue , 22);
    priority_queue_add(queue , 5);
    priority_queue_add(queue , 0);
    priority_queue_add(queue , 1);
    priority_queue_add(queue , 4);

    while (!priority_queue_is_empty(queue)){

        printf("%d \n", priority_queue_poll(queue));
    }

    priority_queue_delete(queue);

    return 0;
}
