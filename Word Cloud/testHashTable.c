#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "HashTable.h"

int main(void)
{

	HashTable *T = createHashTable (10);
	Node* newNode1 = createNode (1);
	Node* newNode2 = createNode (2);
	Node* newNode3 = createNode (3);
	Node* newNode4 = createNode (22);
	Node* newNode5 = createNode (23);
	Node* newNode6 = createNode (21);
	Node* newNode7 = createNode (32);
	Node* newNode8 = createNode (999);



	put (T,newNode1);
	put (T,newNode2);
	put (T,newNode3);
	put (T,newNode4);
	put (T,newNode5);
	put (T,newNode6);
	put (T,newNode7);
	put (T,newNode8);


	//get (T, 999);
	get (T, 11);
	printHashTable (T);

	int el = 11;
	search (T, el);
	if (search (T, el)) printf("\nElemento %d encontrado na HT", el);
	else printf("\nElemento %d não ncontrado na HT", el);
	
	el = 3;
	if (search (T, el)) printf("\nElemento %d encontrado na HT", el);
	else printf("\nElemento %d não ncontrado na HT", el);



	destroyNode (newNode1);
	destroyNode (newNode2);
	destroyNode (newNode3);
	destroyNode (newNode4);
	destroyNode (newNode5);
	destroyNode (newNode6);
	destroyNode (newNode7);
	destroyNode (newNode8);

	return 0;
}
