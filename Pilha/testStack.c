// exercicio sobre funcoes

#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

int main ()
{
	Stack *Stack = create ();
	printStack(Stack);

//f1 -> f2 -> f4 -> f5 -> return(f4) -> return (f2)-> return (f1) -> f3 -> return -> return

	Node *node = createNode(10,"f1",1000);
	push(Stack, node);

	Node *node = createNode(10,"f2",1020);
	push(Stack, node);

	Node *node = createNode(10,"f4",2020);
	push(Stack, node);
	
	Node *node = createNode(10,"f5",3020);
	push(Stack, node);

	node = pop (Stack);
	printf("\nFuncao %s terminou. Retorna para %d", node->functionName, node->returnAddress);
	destroyNode (node);

	node = pop (Stack);
	printf("\nFuncao %s terminou. Retorna para %d", node->functionName, node->returnAddress);
	destroyNode (node);

	node = pop (Stack);
	printf("\nFuncao %s terminou. Retorna para %d", node->functionName, node->returnAddress);
	destroyNode (node)

	Node *node = createNode(10,"f4",2020);
	push(Stack, node);

	Node *node = createNode(10,"f3",1020);
	push(Stack, node);

	node = pop (Stack);
	printf("\nFuncao %s terminou. Retorna para %d", node->functionName, node->returnAddress);
	destroyNode (node)

	node = pop (Stack);
	printf("\nFuncao %s terminou. Retorna para %d", node->functionName, node->returnAddress);
	destroyNode (node)

	printStack(Stack);
	
	destroy(Stack);

	return 0;
}