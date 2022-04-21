#include "functions.h"

Queue create()
{
	// for creating the queue
	Queue q = (Queue)malloc(sizeof(HEAD));
	q->front = q->rear = NULL;
	q->count = 0;
	
	return q;
}

Nodeptr createNode(int item)
{
	// for creating the list
	Nodeptr ptr = (Nodeptr)malloc(sizeof(NODE));
	ptr->data = item;
	ptr->next = NULL;
	
	return ptr;
}

void enqueue(Queue q, int item)
{
	Nodeptr ptr = createNode(item);
	
	if(q->count == 0)
		q->front = ptr;
	else
		q->rear->next = ptr;
	
	q->rear = ptr;
	q->count++;
}

void display(Queue q)
{
	Nodeptr ptr = q->front;
	
	printf("Elements: ");
	while(ptr != NULL)
	{
		printf("%d\t", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int head(Queue q)
{
	return q->front->data;
}

int tail(Queue q)
{
	return q->rear->data;
}

int dequeue(Queue q)
{
	Nodeptr ptr = q->front;
	int item = ptr->data;
	
	if(q->count == 1)
		q->rear = NULL;
	
	q->front = ptr->next;
	ptr = NULL;
	free(ptr);
	q->count--;
	
	return item;
}

int isEmpty(Queue q)
{
	return q->count == 0;
}

int isFull(Queue q)
{
	return q->count == 10;
}

int clear(Queue q)
{
	return q->rear = q->front = NULL, q->count = 0;
}

void run()
{
	int repeat, choice, element;
	Queue queue = create();
	
	do
	{
		system("cls");
		printf("******MAIN MENU*****\n");
		printf("[1] Enqueue\n");
		printf("[2] Dequeue\n");
		printf("[3] Head\n");
		printf("[4] Tail\n");
		printf("[5] isEmpty\n");
		printf("[6] isFull\n");
		printf("[7] Clear\n");
		printf("[8] Display\n");
		printf("[9] Exit\n");
		printf("Choice: ");
		
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				system("cls");

                    if(!isFull(queue))
                    {
                        printf("Enqueue (element): ");
	                	scanf("%d", &element);
						enqueue(queue, element);
                    }
                    else
                   	{
                   		printf("Sorry, stack is already full");
				   	}

				break;
			case 2:
                if(isEmpty(queue))
                	printf("Queue is empty.\n");
                else
				{
                    dequeue(queue);
                    printf("\nDEQUEUED!!");
                }

				break;
			case 3:
				printf("Head: %d", head(queue));
                
				break;
			case 4:
				printf("Tail: %d", tail(queue));
                
				break;
			case 5:
				printf("Queue is%sempty..", isEmpty(queue) ? " " : " not ");
				break;
			case 6:
				printf("Queue is%sfull", isFull(queue) ? " " : " not ");
                
				break;
			case 7:
                clear(queue);
				printf("QUEUE CLEARED!!");
				break;
			case 8:
                system("cls");
                display(queue);
				break;  
			case 9:
				exit(1);      
			default:
				printf("Invalid choice.\n");
				break;
		}
		
		printf("\nBack to menu? (1 = YES | 0 = NO): ");
		scanf("%d", &repeat);
		
		system("cls");
	}
	while(repeat == 1);
	
	return;
}
