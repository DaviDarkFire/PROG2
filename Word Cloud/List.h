#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#define MAX 46 //máximo de letras de uma palavra



typedef struct tNode
{
	char word[MAX]; //palavra em um dos campos do node
	int quantidade; //quantidade de vezes que essa palavra aparece
	// outros campos necessários
	struct tNode* next; //ponteiro para o próximo node
}Node;



typedef struct
{
	Node *begin; //início da lista
	Node *end; //fim da lista
	int numberOfElements; //número de elementos da lista

} List;


// declaração das funcoes
List* create (); //cria uma lista
Node* createNode(char*); //cria um nó
void addSorted(List*, Node*); //adiciona ordenadamente um nó na lista
int isEmpty(List*); //ve se a lista está vazia
void printList(List*); //imprime a lista
void printNode(Node*); //imprime o nó
void destroy(List*); //libera memória alocada pra lista
void destroyNode(Node*); //libera memória alocada pra nó
void exception (int); //avisos e warnings
Node* searchList (List*, char*); //procura um valor passado na lista
void lowerCase(char*); //transforma a palavra passada em caxa baixa
