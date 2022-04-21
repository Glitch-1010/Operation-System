#include <stdio.h>
#include <stdlib.h>

typedef struct node* Nodeptr;

typedef struct node{
	int data;
	Nodeptr next;
}QUEUE_NODE;



void enqueue(int x);



void main(){
	
	
	return;
}

void enqueue(int x){
	QUEUE_NODE queue = (QUEUE_NODE) malloc(sizeof(QUEUE_NODE));
	queue->data = x;
	queue->next = NULL;
}
