#include <stdio.h>
#include <stdlib.h>
#define size 10

int enqueue(int data);
int dequeue();
void display();
int isEmpty();
int isFull();
int clear();
int head();
int tail();
void run();

int queue[10];
int rear = -1;  
int front = -1;
