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

} List;


// declaração das funcoes
List* create ();	
Node* createNode(int);	
void addBegin(List*, Node*);	
void add(List*, Node*);
bool isEmpty(List*);
void printList(List*);
void printNode(Node*);
void destroy(List*);
void destroyNode(Node*);
Node* removeBegin(List*);
Node* removeEnd(List*);
void exception (int);
Node* removeElement(List*, int);
