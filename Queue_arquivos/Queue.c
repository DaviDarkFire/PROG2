#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "Queue.h"

#define ALLOC_ERROR 0
#define UNDERFLOW_WARNING 1
#define NOT_FOUND_WARNING 2
#define EMPTY_Queue_WARNING 3
#define PROCCESS_KILL 4


// funcao para tratamento de avisos e erros do programa (exceções)
void exception (int error)
{
	switch (error)
	{
		case ALLOC_ERROR:
			printf ("Erro na alocação de memória.\n\n");
			exit (1);
		case UNDERFLOW_WARNING:
			printf ("Remoção não realizada. Queue vazia.\n\n");
			break;
		case NOT_FOUND_WARNING:
			printf ("Remoção não realizada. Elemento não existente.\n\n");
			break;
		case EMPTY_Queue_WARNING:
			printf ("Queue Vazia.\n\n");
			break;
		case PROCCESS_KILL:
 			printf("Encerrando a execução do programa...\n\n");
			exit(1);	
		default:
			printf("Exceção desconhecida! Encerrando a execução do programa...");
			exit(1);
	}
}

// Criação de uma Queue simplesmente encadeada vazia
Queue* create ()
{
	Queue* newQueue = (Queue*) malloc (sizeof(Queue));
	newQueue -> begin = NULL;
	newQueue -> end = NULL;
	newQueue -> numberOfElements = 0;
	if (!newQueue) exception (ALLOC_ERROR);
	
	return newQueue;
}

// Criação de um nó para armazenar um valor inteiro (value)
Node* createNode(int value)
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> value = value;
	newNode -> next = NULL;
	
	return newNode;
}

// Operação padrão de inserção em Queue (inserção no final da lista). 
// Inserção de um novo nó no final da Queue simplesmente encadeada
// Complexidade: O(1)
void enqueue(Queue* Queue, Node* node)
{
	//caso de Queue vazia
	if(isEmpty(Queue)) Queue->begin = Queue->end = node;
	//caso geral
	else{
		
		node->next = NULL;
		(Queue->end)->next = node;
		Queue->end = node;
	}

	(Queue->numberOfElements)++;
}


// Retorna TRUE se a Queue é vazia e FALSE caso contrário
bool isEmpty(Queue* Queue)
{
	return (Queue->begin == NULL);
}

// Função para impressão da Queue
// Complexidade: O(n)
void printQueue(Queue* Queue)
{
	if(isEmpty(Queue))
	{
		exception(EMPTY_Queue_WARNING);
		return;
	}	


	printf ("\n\nQuantidade de elementos na Queue: %d", Queue->numberOfElements);
	printf ("\nElementos: ");
	Node* aux = Queue->begin;

	while(aux != NULL)
	{
		printNode(aux);
		aux = aux->next;
	}
	printf("\n");
}

// Função de impressão dos campos de um nó
void printNode(Node* node)
{
	if (node) printf("%d  ", node->value);
}


// Liberação de memória ocupada pela Queue simplesmente encadeada
void destroy(Queue* Queue)
{
	Node* aux1;
	Node* aux = Queue->begin;

	while(aux1 != Queue->end)
	{
		aux1 = aux;
		aux = aux->next;
		destroyNode(aux1);
	}

}
// Liberação de memória ocupada por um nó da Queue
// Caso existam campos "ponteiros" armazenados no nó, deve-se cuidar para que toda a memória previamente alocada seja liberada 
void destroyNode (Node* node)
{
	free (node);
}

// Remove o nó do início da Queue simplesmente encadeada
// Não libera memória ocupada pelo nó (é responsabilidade da função chamadora)
// Complexidade: O(1)
Node* dequeue(Queue* Queue)
{
	// caso de Queue vazia
	if(isEmpty(Queue)) 
	{
		exception(UNDERFLOW_WARNING);
		return NULL;
	}

	// caso exista pelo menos um elemento, o elemento apontado por begin deve ser removido da Queue
	Node* aux = Queue->begin;
	Queue->begin = (Queue->begin)->next;

	// caso só exista um elemento na Queue e ele esteja sendo removido, deve-se atualizar ponteiro end
	if(Queue->begin == NULL) Queue->end = NULL;
	
	// atualiza a quantidade de elementos da Queue e retorna o ponteiro para o nó removido
	(Queue->numberOfElements)--;

	return aux; 
}


