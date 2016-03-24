#include <stdbool.h>

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
void exception (int);
List* create ();
Node* createNode (int);
void addBegin (List*, Node*);
bool isEmpty(List*);
void printList(List*);
void printNode(Node*);
void add(List*, Node*);
