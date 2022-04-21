#include <stdio.h>
#include <stdlib.h>

int enqueue(int data);
int dequeue();
void display();
int isEmpty();
int isFull();
int clear();
int head();
int tail();
void run();

int size = 10;
int queue[10];
int rear = -1;  
int front = -1;
