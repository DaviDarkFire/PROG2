#include <stdio.h>
#include <stdlib.h>
#include "HashTable.h"

#define ALLOC_ERROR 0
#define UNDERFLOW_WARNING 1
#define NOT_FOUND_WARNING 2
#define EMPTY_WARNING 3
#define PROCCESS_KILL 4
#define MAX 46 //máximo de letras de uma palavra
#define CAPACITY 26 //quantos elementos tem a hash

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

//cria a hash
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

//adiciona um valor na hash
void put (HashTable* T, Node* node)
{
	int position = hashFunction (T,node->word);
	addSorted (T->data[position], node);
	(T->numberOfElements)++;
}
//procura um valor na hash
Node* search (HashTable* T, char word[MAX]) 
{
	int position = hashFunction (T,word);
	List* el = T->data[position];
	return searchList (el, word);
}
//printa a hash
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
//retorna a posição a qual o valor passado deve ser inserido
int hashFunction (HashTable* T, char word[MAX]){ //usando os códigos da tabela ascii, essa conta gera valores de 0 a 25	
	return word[0]-97;                          //guardando em cada posição uma letra diferente, 0 = a, 1 = b, 2 = c, ... 25 = z		
}
//destroy a hash
void destroyHash(HashTable* T){
	for(int i = 0; i < T->capacity; i++){		
		destroy(T->data[i]);		
	}
}



