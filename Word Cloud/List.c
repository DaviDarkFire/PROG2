#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "List.h"
#include <string.h>

#define ALLOC_ERROR 0
#define UNDERFLOW_WARNING 1
#define NOT_FOUND_WARNING 2
#define EMPTY_LIST_WARNING 3
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
			printf ("Remoção não realizada. Lista vazia.\n\n");
			break;
		case NOT_FOUND_WARNING:
			printf ("Remoção não realizada. Elemento não existente.\n\n");
			break;
		case EMPTY_LIST_WARNING:
			printf ("Lista Vazia.");
			break;
		case PROCCESS_KILL:
 			printf("Encerrando a execução do programa...\n\n");
			exit(1);	
		default:
			printf("Exceção desconhecida! Encerrando a execução do programa...");
			exit(1);
	}
}

// Criação de uma lista simplesmente encadeada vazia
List* create ()
{
	List* newList = (List*) malloc (sizeof(List));
	newList -> begin = NULL;
	newList -> end = NULL;
	newList -> numberOfElements = 0;
	if (!newList) exception (ALLOC_ERROR);
	
	return newList;
}

// Criação de um nó para armazenar um valor inteiro (value)
Node* createNode(char word[MAX])
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	//newNode -> value = value; ALTERAR
	newNode -> next = NULL;
	
	return newNode;
}


Node* searchList (List* list, char word[MAX])
{
	Node* aux = list->begin;

	/*while(aux != NULL && aux->value!= key)
	{
		aux = aux->next;
	}*/
	return aux;
}



// Operação padrão de inserção em lista. 
// Inserção de um novo nó no final da lista simplesmente encadeada
// Complexidade: O(1)
void add(List* list, Node* node)
{
	//caso de lista vazia
	if(isEmpty(list)) list->begin = list->end = node;
	//caso geral
	else{
		
		node->next = NULL;
		(list->end)->next = node;
		list->end = node;
	}

	(list->numberOfElements)++;
}


// Retorna TRUE se a lista é vazia e FALSE caso contrário
bool isEmpty(List* list)
{
	return (list->begin == NULL);
}

// Função para impressão da lista
// Complexidade: O(n)
void printList(List* list)
{
	if(isEmpty(list))
	{
		exception(EMPTY_LIST_WARNING);
		return;
	}	


	//printf ("\n\nQuantidade de elementos na lista: %d", list->numberOfElements);
	//printf ("\nElementos: ");
	Node* aux = list->begin;

	while(aux != NULL)
	{
		printNode(aux);
		
		aux = aux->next;
	}
	//printf("\n");
}

// Função de impressão dos campos de um nó
void printNode(Node* node)
{
	if (node) printf("->%s", node->word);
}


// Liberação de memória ocupada pela lista simplesmente encadeada
void destroy(List* list)
{
	Node* aux1;
	Node* aux = list->begin;

	while(aux1 != list->end)
	{
		aux1 = aux;
		aux = aux->next;
		destroyNode(aux1);
	}

}
// Liberação de memória ocupada por um nó da lista
// Caso existam campos "ponteiros" armazenados no nó, deve-se cuidar para que toda a memória previamente alocada seja liberada 
void destroyNode (Node* node)
{
	free (node);
}
