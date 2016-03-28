#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include <string.h>

#define ALLOC_ERROR 0
#define UNDERFLOW_WARNING 1
#define NOT_FOUND_WARNING 2
#define EMPTY_LIST_WARNING 3
#define PROCCESS_KILL 4
#define MAX 46
#define CAPACITY 26


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
		
		newNode->word[i] = word[i];
		i++;
	}
	newNode->word[i] = '\0';
	newNode->quantidade = 1;
	newNode -> next = NULL;

	return newNode;
}

//procura na lista o valor passado
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
void addSorted(List* list, Node* node){					
	
	Node* inicio = list->begin; //começa o ponteiro no começo da lista


	Node* anterior = NULL; //começa o ponteiro uma posição antes do começo da lista, neste caso no NULL
			
	while(inicio != NULL && strcmp(node->word, inicio->word) >= 0){ //o loop vai até o fim da lista (NULL) ou até que a palavra de entrada seja maior ou igual que a palavra da posição atual da lista
		
		if(strcmp(node->word, inicio->word) == 0){ //se as palavras forem iguais, não insere nada, apenas se incrementa o contador e sai da função
			(inicio->quantidade)++;
			return;
		
		}	
		anterior = inicio; //se não forem iguais, se a palavra de entrada for apenas maior move os 2 ponteiros um nó a frente pra andar na lista
		inicio = inicio->next;			
	}
			
	//verificação pra saber se a inserção tem que ser no começo da lista	
	if(anterior == NULL){ 
	
		node->next = inicio; //inserção no começo da lista
		list->begin = node; 
				
	//inserção nos demais lugares da lista	
	}else{
	
		anterior->next = node;
		node->next = inicio;
	
	}	
	//incremento do número de elementos
	(list->numberOfElements)++;		
}

// Retorna 1 se a lista é vazia e 0 caso contrário
int isEmpty(List* list)
{
	if(list->begin == NULL)
		return 1;
	else
		return 0;	
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
	printf("\n%s %d\n", node->word, node->quantidade);
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

//função que converte as strings passadas para caixa baixa
void lowerCase(char word[MAX]){

	int i = 0;
	while(word[i] != '\0'){
	
		if(word[i] < 90){		
			word[i] = word[i]+32;
		}
		i++;
	}	
}
