#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "HashTable.h"
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
	printHashTable(hashDontCare);

	/****************************Começa aqui a parte direcionada a leitura do arquivo do qual se quer extrair as palavras****************************/
	FILE* texto = fopen("texto.in","r"); //cria um ponteiro para o arquivo de texto
	HashTable* hashTexto = createHashTable(CAPACITY); //cria a hash de palavras dontCare
	char* word = malloc(46*sizeof(char*));
	int letter = fgetc(texto);
	int cont = 0;
	while(letter != EOF){
		if((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122) || letter == 45){
			word[cont] = letter;
			cont++;
		}
		if(letter == 32 || letter == '\n'){
			word[cont] = '\0';
			cont = 0;			
		}			
		letter = fgetc(texto);
	}


	destroyHash(hashDontCare); //destroy a hash
	printHashTable(hashDontCare);

					
	return 0;
}
