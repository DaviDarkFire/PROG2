#include <stdio.h>
#include <stdbool.h>
#include "Vector.h"

int main(void)
{

	int i, el=100, pos;

	tVector *V = create(10);

	for (i=0; i<20; i++)
	{
		add (V, el++);
	}

	print(V);


	printf("\n\n");

	el = 3;
	if( (pos = recursiveSearch(V, el, 0)) != -1)
		printf("\nWe found element %d at positiion %d.", el, pos);
	else
		printf("\nWe did not find the element %d.",el);

	el = 113;
	if( (pos = sequentialSearch(V, el)) != -1)
		printf("\nWe found element %d at positiion %d.", el, pos);
	else
		printf("\nWe did not find the element %d.",el);

	el = 119;
	if((pos = binarySearch(V, el)) != -1) 
		printf("\nWe found the element %d at position %d.", el, pos);
	else
		printf("\nWe did not find the element %d.",el);

	el = 102;
	pos = binarySearch(V, el);
	if(pos!= -1)
		printf("\nWe found the element %d at position %d.", el, pos);
	else
		printf("\nWe did not find the element %d.",el);
	
	el = 119;
	pos = binarySearchIt(V, el);
	if(V->data[pos] == el) 
		printf("\nWe found the element %d at position %d.", el, pos);
	else
		printf("\nWe did not find the element %d.",el);
	
	el = 101;
	pos = binarySearchIt(V, el);
	if(V->data[pos] == el) 
		printf("\nWe found the element %d at position %d.", el, pos);
	else
		printf("\nWe did not find the element %d.",el);


	el = 105;
	pos = binarySearchIt_other(V, el);
	if(pos != -1) 
		printf("\nWe found the element %d at position %d.", el, pos);
	else
		printf("\nWe did not find the element %d.",el);
	

	el = 115;
	pos = binarySearchIt_other(V, el);
	if(pos != -1) 
		printf("\nWe found the element %d at position %d.", el, pos);
	else
		printf("\nWe did not find the element %d.",el);

	
	int removed = removeLast(V);
	removed = removeFirst(V);
	removeElement(V,113);
	removeElement(V,118);

	printf("\nMax: %d",max (V));
	printf("\nMin: %d",min (V));
	
	print(V);
	destroy(V);
	return 0;
}
