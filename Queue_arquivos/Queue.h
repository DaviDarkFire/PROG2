#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



typedef struct tNode
{
	int value;
	// outros campos necessários
	struct tNode* next;
}Node;



typedef struct
{
	Node *begin;
	Node *end;
	int numberOfElements;

} Queue;


// declaração das funcoes
Queue* create ();	
Node* createNode(int);	
void enqueue(Queue*, Node*);	
Node* dequeue(Queue*);

bool isEmpty(Queue*);
void printQueue(Queue*);
void printNode(Node*);
void destroy(Queue*);
void destroyNode(Node*);


void exception (int);

