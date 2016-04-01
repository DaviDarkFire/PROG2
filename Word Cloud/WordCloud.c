#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "Read.h"


#define CAPACITY 26

int main(void){
	/****************************Começa aqui a parte direcionada a leitura do arquivo do qual se quer extrair as palavras DontCare****************************/
	FILE* dontCare = fopen("palavrasDontCare.in","r"); //cria um ponteiro para o arquivo de palavras dontCare
	HashTable* hashDontCare = createHashTable(CAPACITY); //cria a hash de palavras dontCare
	char* dontCareWord = malloc(46*sizeof(char*));

	while (fscanf(dontCare, "%s", dontCareWord) != EOF) {	//loop que vai até o fim do arquivo

		lowerCase(dontCareWord); //transforma a palavra lida em caixa baixa

		Node* node = createNode(dontCareWord); //cria o nó a ser inserido na lista da hash

		put (hashDontCare, node); //coloca o nó na hash

	}

	/****************************Começa aqui a parte direcionada a leitura do arquivo do qual se quer extrair as palavras****************************/
	FILE* texto = fopen("texto.in","r"); //cria um ponteiro para o arquivo de texto
	HashTable* hashTexto = createHashTable(CAPACITY); //cria a hash de palavras dontCare

	read(texto, hashTexto, hashDontCare);
	
	

	destroyHash(hashTexto); //destroy a hash
	destroyHash(hashDontCare); //destroy a hash
	fclose(dontCare);
	fclose(texto);


	return 0;
}
