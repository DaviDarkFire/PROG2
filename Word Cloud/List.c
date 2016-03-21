#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "List.h"

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
Node* createNode(int value)
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> value = value;
	newNode -> next = NULL;
	
	return newNode;
}


Node* searchList (List* list, int key)
{
	Node* aux = list->begin;

	while(aux != NULL && aux->value!= key)
	{
		aux = aux->next;
	}
	return aux;
}

// Inserção de um novo nó no início da lista
// Complexidade: O(1)
void addBegin(List* list, Node* node)
{
	//caso de lista vazia
	if(isEmpty(list)) list->begin = list->end = node;
	//caso geral
	else{
		node->next = list->begin;
		list->begin = node;
	}

	(list->numberOfElements)++;
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
	if (node) printf("->%d", node->value);
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

// Remove o primeiro nó da lista simplesmente encadeada
// Não libera memória ocupada pelo nó (é responsabilidade da função chamadora)
// Complexidade: O(1)
Node* removeBegin(List* list)
{
	// caso de lista vazia
	if(isEmpty(list)) 
	{
		exception(UNDERFLOW_WARNING);
		return NULL;
	}

	// caso exista pelo menos um elemento, o elemento apontado por begin deve ser removido da lista
	Node* aux = list->begin;
	list->begin = (list->begin)->next;

	// caso só exista um elemento na lista e ele esteja sendo removido, deve-se atualizar ponteiro end
	if(list->begin == NULL) list->end = NULL;
	
	// atualiza a quantidade de elementos da lista e retorna o ponteiro para o nó removido
	(list->numberOfElements)--;

	return aux; 
}


// Remove o último nó da lista simplesmente encadeada
// Não libera memória ocupada pelo nó (é responsabilidade da função chamadora)
// Complexidade: O(n), pois é necessário percorrer a lista para garantir a atualização do ponteiro "next" do penúltimo nó da lista
Node* removeEnd(List* list)
{

	// Caso de lista vazia
	if(isEmpty(list)) 
	{
		exception(UNDERFLOW_WARNING);
		return NULL;
	}

	// percorre a lista utilizando dois ponteiros auxiliares
	Node* aux = NULL;
	Node* aux1 = list->begin;
	while(aux1->next != NULL)
	{
		aux = aux1;
		aux1 = aux1->next;
	}

	// caso em que a lista tem apenas um elemento
	// deve-se atualizar tanto ponteiro begin quanto ponteiro end 	
	if(aux==NULL)
	{
		list->begin = list->end = NULL;
	}
	// caso geral (mais de um nó na lista). 
	// atualiza-se ponteiro next do penúltimo nó e ponteiro end da lista antes de retornar o nó removido
	else
	{
		aux->next = NULL;
		list->end = aux;
	}

	// atualiza a quantidade de elementos e retorna o ponteiro para o nó removido da lista
	(list->numberOfElements)--;
	return aux1;
}

// Remove um elemento da lista especificado por "el"
// O método deve realizar a busca do elemento. Em caso de sucesso na busca, o elemento deve ser removido.
// Se houver duplicatas, a primeira ocorrência de "el" na lista será removida. 
// Não libera memória ocupada pelo nó (é responsabilidade da função chamadora)
// Complexidade: O(n)
Node* removeElement(List* list, int el)
{

	// caso de lista vazia
	if(isEmpty(list)) 
	{
		exception(UNDERFLOW_WARNING);
		return NULL;
	}


	// busca o elemento na lista
	Node* aux = NULL;
	Node* aux1 = list->begin;

	while(aux1!= NULL && aux1->value != el)
	{
		aux = aux1;
		aux1 = aux1->next;
	}

	// se o elemento não se encontra na lista, o ponteiro aux1 terminará a busca com valor NULL
	if(aux1==NULL)
	{
		exception(NOT_FOUND_WARNING);
		return NULL;
	}

	// se o elemento encontrado é o primeiro da lista, o ponteiro aux terminará a busca com valor NULL
	if(aux==NULL)
	{
		list->begin = (list->begin)->next;
	}

	// caso contrário, o elemento a ser removido está apontado por aux1 e aux aponta para o nó anterior a ele
	else
	{
		aux->next = aux1->next;
	}

	// caso o nó removido seja o último, deve-se autalizar o ponteiro end da lista
	if(aux1->next == NULL) list->end = aux;

	// atualiza a quantidade de elementos e retorna o ponteiro para o nó removido
	(list->numberOfElements)--;
	return aux1;

	
}
