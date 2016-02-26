#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct tNode
{
	int value;
	char functionName[10];
	int returnAdress;
	// outros campos necessários
	struct tNode* next;
}Node;



typedef struct
{
	Node *top;
	int numberOfElements;
} Stack;


// declaração das funcoes
Stack* create ();	
Node* createNode(int);	
void push (Stack*, Node*);
Node* pop(Stack*);
bool isEmpty(Stack*);
void printStack(Stack*);
void printNode(Node*);
void destroy(Stack*);
void destroyNode(Node*);
void exception (int);
