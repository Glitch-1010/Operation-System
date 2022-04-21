#include <stdio.h>
#include <stdlib.h>

typedef struct node* Nodeptr;

typedef struct
{
	Nodeptr front;
	int count;
	Nodeptr rear;
}HEAD;

typedef HEAD* Queue;

typedef struct node
{
	int data;
	Nodeptr next;
}NODE;

Queue create();
void enqueue(Queue queue, int item);
int dequeue(Queue queue);
int head(Queue queue);
int tail(Queue queue);
int isEmpty(Queue queue);
int isFull(Queue queue);
int clear(Queue queue);
void display(Queue queue);
