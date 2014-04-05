/*
this program implements a simple circular queue using linked list.
the operations supported are enqueue and dequeue
assumption:
whenever dequeue is called, the list is nonempty
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node list;
list *head,*tail;
void printList(list *q);
void enqueue(int n);
void dequeue();

int main()
{
	int t,n;
	printf("enter 1 to enqueue\n2 to dequeue\n3 to exit\n");
	while(1)
	{
		printf("select:\n");
		scanf("%d",&t);
		if(t==1)
		{
			printf("enter the number\n");
			scanf("%d",&n);
			enqueue(n);
		}
		if(t==2)
		{
			dequeue();
		}
		if(t==3)
			break;
	}		
	printList(head);
	return 0;
}
void printList(list *p)
{
	int count=0;
	while(p!=head || count!=1)
	{
		if(p==head)
			count++;
		printf("%d  ",p->data );
		p=p->next;
	}
	printf("\n");
}
void enqueue(int n)
{
	list *q;
	if(head==NULL)
	{
		head=malloc(sizeof(list));
		head->data=n;
		tail=head;
		tail->next=head;
	}
	else
	{
		tail->next=malloc(sizeof(list));
		tail->next->data=n;
		tail=tail->next;
		tail->next=head;
	}
}
void dequeue()
{
	list *q;
	q=head->next;
	printf("dequeued number=%d\n",head->data);
	head=head->next;
	tail->next=head;
	return;
}
