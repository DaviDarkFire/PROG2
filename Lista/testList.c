#include <stdlib.h>
#include <stdio.h>
#include "List.h"

int main ()
{
	List *list = create ();
	Node* node = createNode(10);
	add(list, node);

	Node* node1 = createNode(13);
	add(list, node1);

	Node* node2 = createNode(9);
	add(list, node2);

	printList(list);
	printf("\n");
	return 0;
}
