#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"


#define ALLOC_ERROR 0
#define UNDERFLOW_WARNING 1
#define NOT_FOUND_WARNING 2
#define EMPTY_WARNING 3
#define PROCCESS_KILL 4

// funcao para tratamento de avisos e erros do programa (exceções)
void exceptionHT (int error)
{
	switch (error)
	{
		case ALLOC_ERROR:
			printf ("Erro na alocação de memória.\n\n");
			exit (1);
		case UNDERFLOW_WARNING:
			printf ("Remoção não realizada. Lista vazia.\n\n");
			break;
		case NOT_FOUND_WARNING:
			printf ("Remoção não realizada. Elemento não existente.\n\n");
			break;
		case EMPTY_WARNING:
			printf ("Lista Vazia.\n\n");
			break;
		case PROCCESS_KILL:
 			printf("Encerrando a execução do programa...\n\n");
			exit(1);	
		default:
			printf("Exceção desconhecida! Encerrando a execução do programa...");
			exit(1);
	}
}


HashTable *createHashTable (int capacity)
{

	int i;
	HashTable *newTable = malloc (sizeof(HashTable));
	

	if (!newTable) exception(ALLOC_ERROR);
	
  	// alocação de memória para armazenamento dos elementos 
	newTable->data = (List**) malloc (capacity * sizeof(List*));   

	if (! (newTable->data)) exception(ALLOC_ERROR);

	for (i=0; i<capacity; i++)
	{
		newTable->data[i] = create (); // criacao da lista (vazia) 
	}

	newTable->capacity = capacity;
	newTable->numberOfElements = 0;
	return newTable;

}


void put (HashTable* T, Node* node)
{
	int position = hashFunction1 (T,node->value);
	add (T->data[position], node);
	(T->numberOfElements)++;
}

Node* get (HashTable* T, int key)
{
	int position = hashFunction1 (T,key);
	Node* node = removeElement (T->data[position], key);
	if (node) (T->numberOfElements)--;
	return node;
}
Node* search (HashTable* T, int key) 
{
	int position = hashFunction1 (T,key);
	List* el = T->data[position];
	return searchList (el, key);
}
void printHashTable(HashTable* T)
{

	int i;
	
	for (i=0; i<T->capacity; i++)
	{
		printf("\nPosicao %d, endereço da lista = %p.\nElementos:", i, (void*) T->data[i]);
		List* list = T->data[i];
		printList (list);
	}



	
}

int hashFunction1 (HashTable* T, int key)
{
	return (key%(T->capacity));
}


