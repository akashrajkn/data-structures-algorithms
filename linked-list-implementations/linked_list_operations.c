/*
this file contains basic singly linked list operations.
create = creates a linked list with user inputs. stops when -999 is given as input
insertAfter = inserts a number after a particular node in the list
insertBefore = inserts a number before a particular node in the list
delete = deletes a node
printList = prints the list
middleNode = returns the middle node in a list containing odd number of nodes
*/

//many of the functions here use recursion

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node list;
void create(list **q);
void insertAfter(list **q,int a, int b);
void insertBefore(list **q, int a, int b);
void delete(list **q,int a);
void printList(list *q);
int middleNode(list *q);

int main()
{
	int a,b;
	list *head,*p;
	head=malloc(sizeof(list));
		
	p=head;
	create(&p);
	printList(head);

	printf("enter after which no, to add and what to add:\n");
	scanf("%d %d",&a,&b);
	insertAfter(&head,a,b);

	printList(head);

	printf("enter before which no, to add and what to add:\n");
	scanf("%d %d",&a,&b);
	insertBefore(&head,a,b);

	printList(head);

	printf("enter no to delete");
	scanf("%d",&a);
	delete(&head,a);	

	printList(head);

	b=middleNode(head);
	printf("middle node is: %d\n",b);
	return 0;
}

//creates a list.  takes the pointer to the list pointer

void create(list **p)
{
	int temp;
	scanf("%d",&temp);
	if(temp==-999)
	{
		(*p)->data=7;
		(*p)=NULL;
	}
	else
	{
		(*p)->data=temp;
		(*p)->next=malloc(sizeof(list));
		create(&((*p)->next));
	}
	return;
}

//inserts after a particulare node. 
//the parameters are pointer to the list pointer, new number and the node after which it 
//to insert the new data

void insertAfter(list **p, int a, int b)
{
	list *temp;
	if((*p)==NULL)
	{
		printf("number not found\n");
		return;
	}
	if((*p)->data==a)
	{
		temp=(*p)->next;
		(*p)->next=malloc(sizeof(list));
		(*p)->next->data=b;
		(*p)->next->next=temp;
		return;
	}
	else
	{
		insertAfter(&((*p)->next),a,b);
	}
	return;
}

//inserts before a particulare node. 
//the parameters are pointer to the list pointer, new number and the node before which it 
//to insert the new data

void insertBefore(list **p,int a,int b)
{
	list *temp;
	if((*p)==NULL)
	{
		printf("number not found\n");
		return;
	}
	if((*p)->data==a)
	{
		temp=(*p);
		(*p)=malloc(sizeof(list));
		(*p)->data=b;
		(*p)->next=temp;
		return;
	}
	else
	{
		insertBefore(&((*p)->next),a,b);
	}
	return;
}

//deletes a particular node. 

void delete(list **p, int a)
{
	list *temp;
	if((*p)->data==a)
	{
		printf("hello\n");
		temp=(*p)->next;
		free(*p);
		(*p)=temp;
		return;
	}
	else
	{
		delete(&((*p)->next),a);
	}
	return;
}

//prints the list from the pointer passed.


void printList(list *p)
{
	while(p!=NULL)
	{
		printf("%d  ",p->data );
		p=p->next;
	}
	printf("\n");
}

//finds the middle node of the list 'p'

int middleNode(list *p)
{
	list *r,*q;
	r=p;q=p;
	while(1)
	{	
		if(r->next==NULL ||r->next->next==NULL)
			break;
		r=r->next;
		r=r->next;
		q=q->next;
	}
	return q->data;
}
