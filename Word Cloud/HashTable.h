// Implementação de tabela Hash com tratamento de colisões por encadeamento externo 

#include <stdbool.h>
#include "List.h"

typedef struct
{
  int capacity;					// capacidade da tabela (do vetor) - obs: as listas encadeadas não têm limite 
  int numberOfElements;				// quantidade de elementos armazenados 
  List **data;					// elementos 

}HashTable;

// funcionalidades de um HashTable

HashTable *createHashTable (int); 				// alocação de memória para um HashTable; recebe como parâmetro a quantidade maxima de elementos do vetor;
void put (HashTable*, Node* ); 			// inserção do elemento passado como parâmetro no final do vetor
Node* search (HashTable*, char*); 		// busca sequencial de um elemento passado como parâmetro
int hashFunction (HashTable*, char*);
void printHashTable(HashTable*); 				// impressão os elementos do vetor
void exceptionHT (int);
