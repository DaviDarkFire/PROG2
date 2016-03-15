#include <stdlib.h>
#include <stdio.h>
#include "List.h"

int main ()
{
	List *list = create ();
	List *list2 = create ();
	List *list3 = create ();	
		
	Node *node1 = createNode(0);
	add(list, node1);
	printList(list);
	
	Node *node2 = createNode(2);
	add(list, node2);
	printList(list);

	Node *node3 = createNode(4);
	add(list, node3);	
	printList(list);
	
	Node *node4 = createNode(6);
	add(list, node4);
	printList(list);
	
	Node *node5 = createNode(8);	
	add(list, node5);
	printList(list);



	Node *node6 = createNode(1);
	add(list2, node6);
	printList(list2);
	
	Node *node7 = createNode(3);
	add(list2, node7);
	printList(list2);

	Node *node8 = createNode(5);
	add(list2, node8);	
	printList(list2);
	
	Node *node9 = createNode(7);
	add(list2, node9);
	printList(list2);
	
	Node *node10 = createNode(9);	
	add(list2, node10);
	printList(list2);


	mergeList(list, list2, list3);

	printList(list3);
	
	

	

	return 0;
}
