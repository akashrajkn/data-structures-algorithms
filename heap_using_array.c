/*
this program implements HEAP datastructure using arrays.
->maxHeapify() function performs heapify on two sub-heaps with a new element 
added as the root to the sub-heaps
->buildMaxHeap() function builds a max-heap with the elements in the array.
*/

#include<stdio.h>
#include<stdlib.h>

int *a;
void  maxHeapify(int p, int q);
void buildMaxHeap(int q);

int main()
{
	int n,i;
	printf("enter the size of array\n");
	scanf("%d",&n);
	a=malloc(n*sizeof(int));

	printf("enter the elements of the array\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("the list is\n");

	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	buildMaxHeap(n);

	printf("the heap is\n");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

	return 0;
}
void buildMaxHeap(int q)
{
	int i;
	for(i=q/2;i>=0;i--)
	{
		maxHeapify(i,q);
	}
}
void maxHeapify(int p, int q)
{
	int left=2*p+1;
	int right=2*p+2;
	int largest,temp;
	if(right<q || left<q)
	{
		largest=-1;
		if(a[p]>a[left])
			largest=p;
		else largest=left;

		if(a[right]>a[largest])
			largest=right;
		if(largest!=p && largest!=-1)
		{
			temp=a[p];
			a[p]=a[largest];
			a[largest]=temp;
			maxHeapify(largest,q);
		}
	}
}

