// Stack.c


#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "Stack.h"

#define ALLOC_ERROR 0
#define UNDERFLOW_WARNING 1
#define NOT_FOUND_WARNING 2
#define EMPTY_Stack_WARNING 3
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
			printf ("Remoção não realizada. Stack vazia.\n\n");
			break;
		case NOT_FOUND_WARNING:
			printf ("Remoção não realizada. Elemento não existente.\n\n");
			break;
		case EMPTY_Stack_WARNING:
			printf ("Stack Vazia.\n\n");
			break;
		case PROCCESS_KILL:
 			printf("Encerrando a execução do programa...\n\n");
			exit(1);	
		default:
			printf("Exceção desconhecida! Encerrando a execução do programa...");
			exit(1);
	}
}

// Criação de uma Stack simplesmente encadeada vazia
Stack* create ()
{
	Stack* newStack = (Stack*) malloc (sizeof(Stack));
	newStack -> top = NULL;
	newStack -> numberOfElements = 0;
	if (!newStack) exception (ALLOC_ERROR);
	
	return newStack;
}

// Criação de um nó para armazenar um valor inteiro (value)
Node* createNode(int value, char functionName[], int returnAdress)
{
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode -> value = value;
	newNode -> returnAdress = returnAdress;
	newNode -> functionName = functionName;
	newNode -> next = NULL;
	
	return newNode;
}

// Inserção de um novo nó no topo da Stack
// Complexidade: O(1)
void push (Stack* Stack, Node* node)
{
	//caso de Stack vazia
	if(isEmpty(Stack)) Stack->top = node;
	//caso geral
	else{
		node->next = Stack->top;
		Stack->top = node;
	}

	(Stack->numberOfElements)++;
}


// Retorna TRUE se a Stack é vazia e FALSE caso contrário
bool isEmpty(Stack* Stack)
{
	return (Stack->top == NULL);
}

// Função para impressão da Stack
// Complexidade: O(n)
void printStack(Stack* Stack)
{
	if(isEmpty(Stack))
	{
		exception(EMPTY_Stack_WARNING);
		return;
	}	


	printf ("\n\nQuantidade de elementos na Stack: %d", Stack->numberOfElements);
	printf ("\nElementos: ");
	Node* aux = Stack->top;

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


// Liberação de memória ocupada pela Stack simplesmente encadeada
void destroy(Stack* Stack)
{
	Node* aux1;
	Node* aux = Stack->top;

	while(aux != NULL)
	{
		aux1 = aux;
		aux = aux->next;
		destroyNode(aux1);
	}

}
// Liberação de memória ocupada por um nó da Stack
// Caso existam campos "ponteiros" armazenados no nó, deve-se cuidar para que toda a memória previamente alocada seja liberada 
void destroyNode (Node* node)
{
	free (node);
}

// Remove o nó da Stack apontado por top 
// Não libera memória ocupada pelo nó (é responsabilidade da função chamadora)
// Complexidade: O(1)
Node* pop(Stack* Stack)
{
	// caso de Stack vazia
	if(isEmpty(Stack)) 
	{
		exception(UNDERFLOW_WARNING);
		return NULL;
	}

	// caso exista pelo menos um elemento, o elemento apontado por top deve ser removido da Stack
	Node* aux = Stack->top;
	Stack->top = (Stack->top)->next;
	// atualiza a quantidade de elementos da Stack e retorna o ponteiro para o nó removido
	(Stack->numberOfElements)--;

	return aux; 
}

