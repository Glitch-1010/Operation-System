#include "PQueue.h"

int enqueue(int data)
{
    int x, temp[front], ctr = 0;

    if(front == -1)
        front = 0;
    
    rear++;
    queue[rear] = data;

    // sorts the data
    for(x = front; x <= rear; x++)
    {
        if(queue[x] > queue[rear])
        {
            temp[x] = queue[x];
            queue[x] = queue[rear];
            queue[rear] = temp[x];
        }
    }
   // rear = (rear + 1) % size;    // for circular queue
}

int dequeue() 
{
    int data = queue[front];


    if(front != rear)
        front = (front + 1) % size;    
    else
    {
        front -= 1;
        rear -= 1;
    }

    return data;
}   

void display()
{
    int x;

    printf("Elements in Queue: ");
	if(rear != -2)
    {
        for(x = front; x <= rear; x++)
		printf("%d ", queue[x]);
    }

    /*
        For printing after clearing
        0 - an element not added would still be printed after clearing
        The following line of codes is a fix to this issue
    */
    else
    {
        for(x = front; x < rear; x++)
		printf("%d ", queue[x]);
                    
        rear = -1;  //resetting the rear to the original value
    }
}

int isEmpty() 
{
   if(front == -1)
      return 1;
   else
      return 0;
}

int isFull() 
{
	return (rear == size - 1)? 1: 0;
}

int clear()
{
	return front = -1, rear = -1;   
}

int head() 
{
	
    return queue[front];
}

int tail() 
{

    return queue[rear];
}

void run(){
	int repeat, choice, element, multElement;
	
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
						enqueue(element);
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
				if(front == -1)
				printf("Empty");
				else
				printf("Head: %d", head(queue));
                
				break;
			case 4:
				if(rear == -1)
				printf("Empty");
				else
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
