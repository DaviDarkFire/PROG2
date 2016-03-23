#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 46



typedef struct tNode
{
	char word[MAX];
	int quantidade;
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
void addSorted(List*, Node*);
bool isEmpty(List*);
void printList(List*);
void printNode(Node*);
void destroy(List*);
void destroyNode(Node*);
void exception (int);
Node* searchList (List*, char*);
char* lowerCase(char*);
