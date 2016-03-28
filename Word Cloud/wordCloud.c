#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "HashTable.h"
#define CAPACITY 26

int main(void){

	FILE* dontCare = fopen("palavrasDontCare.in","r"); //cria um ponteiro para o arquivo de palavras dontCare
	HashTable* hashDontCare = createHashTable(CAPACITY); //cria a hash de palavras dontCare
	char* dontCareWord = malloc(46*sizeof(char*)); 

	while (fscanf(dontCare, "%s", dontCareWord) != EOF) {	//loop que vai até o fim do arquivo

		lowerCase(dontCareWord); //transforma a palavra lida em caixa baixa	
		
		Node* node = createNode(dontCareWord); //cria o nó a ser inserido na lista da hash
		
		put (hashDontCare, node); //coloca o nó na hash

	}			
	printHashTable(hashDontCare);


	destroyHash(hashDontCare); //destroy a hash

					
	return 0;
}
