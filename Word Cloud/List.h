#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 46



typedef struct tNode
{
	char word[MAX];
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
Node* createNode(char*);	
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
Node* removeElement(List*, char*);
Node* searchList (List*, char*);
