#pragma once

#ifndef T //type of the proprity queue items

/*
    T must be defined outside of compiled program
    example : gcc -DT=int -c priority_queue.c

*/

    // # define T int
    // # error "T must be defined. Try using gcc's -D flag to define it before compilation. for example: gcc -DT=int -c priority_queue.c "
    

#endif


typedef struct {

    T* items;
    int capacity;
    int size;
    double (*comparator)(T, T);

} priority_queue;


priority_queue* priority_queue_new(int capacity, double (*comparator)(T,T));

void priority_queue_delete(priority_queue* q);

void priority_queue_add(priority_queue* q , T b );

T priority_queue_peek(priority_queue* q);

T priority_queue_poll(priority_queue* q);

int priority_queue_is_empty(priority_queue *q);