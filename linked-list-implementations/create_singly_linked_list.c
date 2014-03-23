/*
this program is a basic application of singly linked list
the program takes input as long as it is -999
this program creates list using recursion.
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node list;

// **q is pointer to the pointer pointing to list
void create(list **q);

int main()
{
	list *head,*p;
	head=malloc(sizeof(list));

	p=head;
	create(&p);
	//&p sends the address of the pointer p
	p=head;
	printf("the values in the list are:\n");
	while(p!=NULL)
	{
		printf("%d\n",p->data );
		p=p->next;
	}
	return 0;
}
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
