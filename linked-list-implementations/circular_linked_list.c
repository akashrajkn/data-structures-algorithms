/*
this program shows the simple implementation of
circular linked list.
the operatios performed are
adding an element into the list,
deleting an element from the list,
searching the list for an element
and printing  the list.

many functions are implemented using the recursion.
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node list;
//void createCList(list **q, list **head);
//use this if you dont want to declare head as global;
void createCList(list **q);
void printCList(list *q);
void insertCList(list **q,int a);
void deleteCList(list **q, int a);
void searchCList(list *q,int  a);
list *head;

int main()
{
	list *p;
	int m;
	head= malloc(sizeof(list));

	p=head;
	createCList(&p);
	printCList(p);
	printf("enter element to insert\n");
	scanf("%d",&m);
	insertCList(&(p->next),m);
	printCList(p);
	printf("enter element to delete\n");
	scanf("%d",&m);
	deleteCList(&p,m);
	printCList(p);
	printf("enter element to search\n");
	scanf("%d",&m);
	searchCList(p->next,m);
	return 0;
}
void createCList(list **p)
{
	int temp;
	scanf("%d",&temp);
	if(temp==-999)
	{
		free(*p);
		*p=head;
		return;
	}
	else
	{
		(*p)->data=temp;
		(*p)->next=malloc(sizeof(list));
		createCList(&((*p)->next));
	}
}
void printCList(list *q)
{
	printf("%d ",q->data);
	q=q->next;
	while(q!=head)
	{
		printf("%d ",q->data);
		q=q->next;
	}
	printf("\n");
	return;
}
void insertCList(list **q, int a)
{
	if(*q==head)
	{
		(*q)=malloc(sizeof(list));
		(*q)->data=a;
		(*q)->next=head;
		return;
	}
	else
		insertCList(&((*q)->next),a);
}
void deleteCList(list **q, int a)
{
	if((*q)->data==a)
	{
		(*q)=(*q)->next;
		return;
	}
	else
	{
		deleteCList(&((*q)->next),a);
	}
}
void searchCList(list *q,int a)
{
	if(head->data==a)
	{
		printf("element found\n");
		return;
	}
	while(q!=head)
	{
		if(q->data==a)
		{
			printf("elemetn found\n");
			return;
		}
		else
			q=q->next;
	}
	printf("element not found\n");
	return;
}
