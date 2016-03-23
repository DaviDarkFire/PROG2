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
#define MAX 46


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
	int i = 0;
	while(word[i] != '\0'){		
		printf("testeforever\n");
		newNode->word[i] = word[i];
	}
	newNode->quantidade = 1;
	newNode -> next = NULL;

	return newNode;
}


Node* searchList (List* list, char word[MAX])
{
	Node* aux = list->begin;

	while(aux != NULL && strcmp(word, aux->word) != 0)
	{
		aux = aux->next;
	}
	return aux;
}



// Operação padrão de inserção ordenada em lista. 
// Inserção de um novo nó na sua posição correta da lista
void addSorted(List* list, Node* node)
{
	int aux = 1;
	//caso de lista vazia
	if(isEmpty(list)) list->begin = list->end = node;	
	
	//caso geral
	else{
		Node* nodeAux = list->begin;
		Node* nodeAux2 = (list->begin)->next;		
		for (int i = 0; i < list->numberOfElements; i++){
			printf("teste\n");
			if(strcmp(node->word, nodeAux->word) == 0){ //comparação pra saber se são iguais

				(nodeAux->quantidade)++;
				aux = 0;

			}

			if(strcmp(node->word, nodeAux->word) < 0 ){ //comparação pra saber se a palavra passada vem antes que o primeiro item da lista

				node->next = nodeAux;
				list->begin = node;				

			}			
			if(strcmp(node->word, nodeAux2->word) < 0 ){ //comparação pra saber se aṕalavra passada vem antes de qualquer outro nó da lista que não seja o inicio

				node->next = nodeAux2;
				nodeAux->next = node;				

			}			
			
			if(nodeAux == list->end && strcmp(node->word, nodeAux->word) > 0){ //comaparação pra saber se a palavra passada vem depois de qualquer nó da lista
				node->next = NULL;
				nodeAux->next = node;
				list->end = node;
			}else{
				nodeAux = nodeAux2;
				nodeAux2 = nodeAux2->next;
			}		
		
		}
	}

	if(aux){ //se a palavra a ser inserida não existe ainda
		(list->numberOfElements)++;
	}	
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

	Node* aux = list->begin;

	while(aux != NULL)
	{
		printNode(aux);
		
		aux = aux->next;
	}
}

// Função de impressão dos campos de um nó
void printNode(Node* node)
{
	printf("Palavra %s\n", node->word);
	printf("Quantidade %d\n", node->quantidade);
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

char* lowerCase(char*  word){

	int i = 0;
	while(word[i] != '\0'){
	
		if(word[i] < 90){		
			word[i] = word[i]+32;
		}
		i++;
	}
	return word;

}
