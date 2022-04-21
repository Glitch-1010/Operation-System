#include "functions.h"

int enqueue(int data)
{
    if(front == -1 && rear == -1)
    {
    	front = rear = 0;
    	queue[rear] = data;
	}else if ((rear + 1)% 10 == front)
	{
		printf("Sorry queue is full!");
	}
	else 
	{
		rear = (rear + 1) % 10;
		queue[rear] = data;
	}
    
}

int dequeue() 
{
    int data = queue[front];
    
    if (front == -1 && rear == -1)
    {
    	printf("Queue is empty!");
	}else if (front == rear)
	{
		front = rear = 1;
	}else
	{
		front = (front + 1) % 10;
	}

    return data;
}   

void display()
{
    int i = front;
    
    if(front == -1 && rear == -1)
    {
    	printf("Queue is empty!");
	}else
	{
		printf("Elements: ");
		while(i != rear){
			printf("%d\t", queue[i]);
			i = (i +1) % 10;
		}
	}
	return;
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
   if(rear == size - 1)
      return 1;
   else
      return 0;
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
		printf("\n******MAIN MENU*****\n");
		printf("[1] Enqueue\n");
		printf("[2] Dequeue\n");
		printf("[3] Empty\n");
		printf("[4] Full\n");
		printf("[5] Clear\n");
		printf("[6] Head\n");
		printf("[7] Tail\n");
		printf("[8] Display\n");
		printf("Choice: ");
		
		scanf("%d", &choice);
		
		system("cls");
		
		switch(choice)
		{
			system("cls");
			case 1:
				do
				{
                    if(!isFull())
                    {
                        printf("Enqueue (element): ");
                        scanf("%d", &element);
					    enqueue(element);

                        printf("Add again? (1 = YES | 0 = NO): ");
					    scanf("%d", &multElement);
                    }
                    else
                    {
                        printf("Sorry, stack is already full");
                        multElement = 0;
                    }
				}
				while(multElement == 1);
						
				break;
            case 2:
				
				do
				{
                    if(isEmpty())
                        printf("Queue is empty.\n");
                    else
					{
                        dequeue();

                        printf("Element dequeued.\nDequeue again? (1 = YES | 0 = NO): ");
					    scanf("%d", &multElement);
                    }
				}
				while(multElement == 1);	
				
				break;
            case 3:
				printf("Is queue empty? %s", isEmpty() ? "Yes" : "No");
				break;
            case 4:
				printf("Is queue full? %s", isFull() ? "Yes" : "No");
				break;
            case 5:
				clear();
				printf("Queue is cleared.");
				break;
            case 6:
                printf("Head: %d", head());
				break;
            case 7:
                printf("Tail: %d", tail());
				break;
            case 8:
                system("cls");
                display();
				break;
			default:
				printf("Invalid choice.\n");
				break;
		}
		
		printf("\nBack to menu? (1 = YES | 0 = NO): ");
		scanf("%d", &repeat);
		
		system("cls");
	}
	while(repeat == 1);
	
}
