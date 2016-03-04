#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int hashFunction1(HashTable* T,int n){
	return n%(T->capacity);
}

HashTable* createHashTable(int c){
	HashTable* T = malloc(sizeof(HashTable));
	T->numberOfElements = 0;
	T->capacity = c;
	T->data = (List**) malloc(c * sizeof(List*)); //como data é um vetor, estou criando capacity posições, cada uma delas com uma lista
	for(int i = 0; i < c; i++)
		T->data[i] = NULL;
	return T;
}

void put(HashTable* T, Node* node){
	int posicao = hashFunction1(T, node->value);
	add(T->data[posicao], node);
	(T->numberOfElements)++;


}
Node* get (HashTable* T, int n){
	int position = hashFunction1(T, n);
	Node* node = removeElement(T->data[position], n);
	(T->numberOfElements)--;
	return node;




}
int main(void){
	printf("Teste\n");






	return 0;
}
