# Generic Priority Queue in C

This is a simople "generic" priority queue implementation to be used in C programs. The "generic" aspect is implemented by using a undefined T macro for the type of the priority queue's items. The user must then define the T type outside the program and compile everything.

## Usage 

Include priority_queue.h in your program and compile it along side priority_queue.c while defining T :

``` bash

    gcc -c priority_queue.c -DT=my_type
    gcc -o my_cool_program code.c priority_queue.o -DT=my_type

```

It is also necessary to provide a comparator function that will define the order of the elements the priority queue takes in. This comparator function will have to return a double and accept two variables of the queue's type as arguments.


This function must return: 
 - a positive double if the first argument is bigger than the second
 - a negative double otherwise


***Note*** : This priority queue is a implemented with a min heap => this means the highest priority memeber is the one that is **smaller** than all the others!

## About

I developped this priority queue to use in my A* 8puzzle solver, but I decided to save the queue itself in its separate repository to better reuse it in the future.

A simple example of the usage of the functions is provided in example.c.

## Procedures

This library's procedures are the following:

```C 
priority_queue* priority_queue_new(int capacity, double (*comparator)(T,T)); 
```

> Creates and returns a pointer to a priority queue. The initial capacity of the queue and the comparator function must be provided.

```C 
void priority_queue_delete(priority_queue* q); 
```
> Deletes the priority queue along with its data. **Attention** : if the elements of the queue are pointers, this procedure does not call free() on them.  

```C 
void priority_queue_add(priority_queue* q , T b ); 
```

> Adds an element to the priority queue

```C 
T priority_queue_peek(priority_queue* q); 
```
> Returns the highest priority member without removing it.

```C 
T priority_queue_poll(priority_queue* q); 
```

> Returns and removes the highest priority member from the queue.

```C 
int priority_queue_is_empty(priority_queue *q); 
```
> Returns 1 if the queue is empty and 0 otherwise.


