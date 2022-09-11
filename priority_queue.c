#include <malloc.h>
#include "priority_queue.h"
#include <stdio.h>

#define PARENT(i) (i-1)/2
#define LEFTCHILD(i) (2*i + 1)
#define RIGHTCHILD(i) (2*i + 2)


priority_queue* priority_queue_new(int capacity, double (*comparator)(T,T)){

    
    priority_queue* q = malloc(sizeof(priority_queue));

    q->capacity = capacity;
    q->size = 0;

    q->items = calloc(capacity,sizeof(T));

    q->comparator = comparator;

    return q;

}


void priority_queue_delete(priority_queue* q){

    free(q->items);

    free(q);
}

static inline int hasLeftChild(priority_queue* q , int i){

    return (int) (LEFTCHILD(i) < q->size);
}

static inline int hasRightChild(priority_queue* q, int i){
    return (int) (RIGHTCHILD(i) < q->size);
}

static inline int hasParent(int i){
    return (int) (PARENT(i) >= 0);
}

static inline T leftChild(priority_queue* q, int i ){
    return q->items[LEFTCHILD(i)];
}



static inline T rightChild(priority_queue* q, int i ){
    return q->items[RIGHTCHILD(i)];
}

static inline T parent(priority_queue* q, int i ){
    return q->items[PARENT(i)];
}


static inline void swap(priority_queue* q, int i, int j){
    T temp = q->items[j];
    q->items[j] = q->items[i];
    q->items[i] = temp;
}


static void ensureCapacity(priority_queue* q){
    if (q->size >= q->capacity){
        if((q->items = realloc(q->items, q->capacity*2 ))){
            q->capacity *= 2;
        }
    }
}

static void heapify_down(priority_queue* q){
    
    int index = 0;

    while(hasLeftChild(q, index)){
        int smallest = LEFTCHILD(index);
        if(q->comparator(leftChild(q, index), rightChild(q,index)) > 0){
            smallest = RIGHTCHILD(index);
        }  

        if( q->comparator(q->items[index], q->items[smallest]) < 0){ //then heap proprety is already satisfied
            break;
        }


        swap(q, index , smallest);
        index = smallest;
    }  

}

static void heapify_up(priority_queue* q){
    int index = q->size-1;
    while(hasParent(index) && q->comparator(q->items[index], parent(q,index)) < 0 ){
        swap(q, index, PARENT(index));
        index = PARENT(index);
    }
}


void priority_queue_add(priority_queue* q , T b ){

    ensureCapacity(q);
    q->items[q->size] = b;
    q->size++;
    heapify_up(q);


}

T priority_queue_peek(priority_queue* q){
    if(q->size <= 0){
        return (T) 0;
    }else{
        return q->items[0];
    }
}


T priority_queue_poll(priority_queue* q){
    if (q->size <= 0){
            return (T) 0;
    }else{
        T  el =  q->items[0];
        q->items[0] = q->items[q->size - 1];
        q->size--;
        heapify_down(q);
        return el;
    }    
}

int priority_queue_is_empty(priority_queue *q){
    return q->size == 0;
}
