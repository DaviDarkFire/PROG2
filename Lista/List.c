#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#include <stdbool.h>

#define ALLOC_ERROR 0

void exception (int error)
{

	if (error == ALLOC_ERROR)
	{
		printf ("Erro na alocação de memória. Programa finalizado.");
		exit (1);
	}
	
}


List* create ()
{
	List* newList = malloc (sizeof(List)); //cria espaço na memória para a lista

	if (!newList) exception (ALLOC_ERROR);

	newList->begin  = NULL; //o início recebe endereço nulo
	newList->end  = NULL; //o fim recebe endereço nulo
	newList->numberOfElements = 0; //número de elementos recebe 0
	
	return newList; //retorna a lista criada através de ponteiro
	
}

Node* createNode(int v){

	Node* newNode = malloc(sizeof(Node)); //cria o espaço na memória para o nó
	newNode->value = v; //coloca o valor passado no nó criado
	newNode->next = NULL; //faz ele apontar para o fim
	return newNode; //retorna o nó criado através de ponteiro
}

bool isEmpty(List* list){ //verifica se a lista está vazia ou não
	return (list->begin == NULL);
}

void addBegin(List* list, Node* node){ 
	 //caso de lista vazia
	if(isEmpty){
		list->begin = node;
		list->end = node;		
	}else{
	//caso a lista esteja preenchida	
		node->next = list->begin;
		list->begin = node;
	}

	(list->numberOfElements++);
}

void printList(List* list){
	Node* aux = list->begin;
	int i = 0;
	while(i < list->numberOfElements){
		printNode(aux);
		printf("\n");
		aux = aux->next;
		i++;

	}

}

void printNode(Node* node){

	printf("%d", node->value);
}

void add(List* list, Node* node){
	//caso de lista vazia
	if(isEmpty(list)){
		list->begin = node;
		list->end = node;		
	}else{
	//caso a lista esteja preenchida	
		node->next = NULL;
		(list->end)->next = node; //o que aconteceu com a minha vida ?
		list->end = node;
	}

	(list->numberOfElements)++;
}

void destroy(List*){
	Node* aux = list->begin;
	Node* aux1;

	while(aux != NULL){
		aux1 = aux;
		aux = aux->next;
		free(aux1);
	}
}
