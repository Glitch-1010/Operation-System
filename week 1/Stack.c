
/*
	13/04/22 17:54
	Name: John Clyde A. Apas
	
	Description: this programs is a simple implementation of stack using c.
				i also implemented functions like push, pop, isEmpty, clear, and top.
				Linked list us used to implement the stack for memory efficiency (assuming size is unknown).
				
				I select the first node as the top of the stack. (for efficient time complexity)
				push operation > will insert at the beginning of the linked list. O(1)
				pop operation > the first node (top) of the linked list will be deleted. O(1)
				
				
				stackStruct.h > contains the implementation of the list. It is placed in a header file for readability
*/

# include <stdio.h>
# include <stdlib.h>
# include <conio.h>
# include <dos.h>


void push(int input);
void pop();
struct node* Top(struct node* top);
void clear();
int isEmpty();
int peek();

void run();
void printElem();

struct node{
	int data;
	struct node * next;
}*top = NULL;

void main(){	
	run();
	
	return;
}

void push(int input){
	struct node *ptr = (struct node*) malloc(sizeof(struct node));
	// we make sure that the allocation is a success before we proceed
	// malloc returns NULL if requested memory can't be allocated
	if(ptr == NULL){
		printf("Stack Overflow!");
		exit(1);
	}
	
	ptr -> data = input;
	ptr -> next = NULL;
	
	ptr -> next = top;
	top = ptr;
	
	return;
}

void pop(){
	struct node* temp;
	if(isEmpty()){
		printf("STACK UNDERFLOW!");
	}

		temp = top;
		top = top->next;
		free(temp);
		temp = NULL;

	return;
}

int isEmpty(){
	
	return ((top == NULL) ? 1 : 0);
	
}

int peek(){
	if(isEmpty()){
		printf("STACK UNDERFLOW!");
		
	}
	return top->data;
}

struct node* Top(struct node* top){
	if (top == NULL){
		printf("Stack Underflow!");
		exit(1);
	}
	return top;
}


void printElem(){
	// creating temp for traversal we won't use ead to traverse to keep track of the top elem
	struct node* temp = top;
	if(isEmpty()){
		printf("Stack Overflow ro Stack is empty!");
		exit(1);
	}
	
	printf("Stack Element: ");
	
	while(temp){
		printf("%d \t", temp->data);
		temp= temp->next;
	}
	printf("\n");
	
}


void clear(){
	// creating temp for traversal we won't use ead to traverse to keep track of the top elem
	struct node* temp;
	if(isEmpty()){
		printf("Stack Overflow!");
		exit(1);
	}
	
	
	while(top){
		temp= top->next;
		free(top);
		top = NULL;
		top = temp;
		
//		temp = top;
//		top = top->next;
//		free(temp);
//		temp = NULL;
		
	}
	printf("Stack Cleared!");
	
}

void run(){
	int action;
	int data;
//	
//	struct node *stack = (struct node*) malloc(sizeof(struct node));
//	if(stack == NULL){
//		printf("Stack Overflow!");
//		exit(1);
//	}
	
	do {
	system("cls");
	
	printf("CHOOSE ACTION:\n");
	printf("1.  Push\n");
	printf("2.  pop\n");
	printf("3.  isEmpty\n");
	printf("4.  clear\n");
	printf("5.  top\n");
	printf("6.  print elements\n");
	printf("7.  exit\n");
	
	printf("ACTION: ");
	scanf("%d", &action);
	
	switch(action) {
		case 1:
			printf("Enter the element to be pushed: ");
			scanf("%d", &data);
			push(data);
			break;
		case 2:
			pop();
			printf("POPED ELEMENT");
			sleep(2);
			break;
		case 3:
			printf("the stack %s", isEmpty()? "is empty": "is not Empty");
			sleep(2);
			break;
		case 4:
			clear();
			sleep(2);
			break;
		case 5:
			printf("The topmost element is %d", peek());
			sleep(2);
			break;
		case 6:
			printElem();
			sleep(2);
			break;
		case 7:
			printf("\nTHANK YOU HAVE A GREAT DAY!!");
			break;
		
	default:
		printf("INVALID INPUT!!\n");
		printf("TRY AGAIN");
		sleep(2);
		system("cls");
	}
		
	} while(action != 7);
	
	return;
}
