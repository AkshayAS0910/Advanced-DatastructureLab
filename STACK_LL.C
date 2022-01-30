#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
struct node
{
int data;
struct node *next;
};
struct node *top;

void main ()
{
    int choice=0;clrscr();
    while(1)
    {
	printf("\n\nChose one from the below options...\n");
	printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
	printf("\n Enter your choice \n");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
	    {
		push();
		break;
	    }
	    case 2:
	    {
		pop();
		break;
	    }
	    case 3:
	    {
		display();
		break;
	    }
	    case 4:
	    {
		exit(0);
		break;
	    }
	    default:
	    {
		printf("Please Enter valid choice ");
	    }
    };
}
}
void push ()
{
    int item;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
	printf("not able to push the element");
    }
    else
    {
	printf("Enter the value");
	scanf("%d",&item);
	if(top==NULL)
	{
	    newnode->data = item;
	    newnode-> next = NULL;
	    top=newnode;
	}
	else
	{
	    newnode->data = item;
	    newnode->next = top;
	    top=newnode;

	}
	printf("Item pushed");

    }
}

void pop()
{
    int item;
    struct node *ptr;
    if (top == NULL)
    {
	printf("Underflow");
    }
    else
    {
	item = top->data;
	ptr = top;
	top = top->next;
	free(ptr);
	printf("Item popped");

    }
}
void display()
{
    int i;
    struct node *ptr;
    ptr=top;
    if(ptr == NULL)
    {
	printf("Stack is empty\n");
    }
    else
    {
	printf("Printing Stack elements \n");
	while(ptr!=NULL)
	{
	    printf("%d\n",ptr->data);
	    ptr = ptr->next;
	}
    }
}