#include <stdio.h>
#include <stdlib.h>
#include "Read.h"

void read(FILE* texto, HashTable* hashTexto, HashTable* hashDontCare){
	char* word = malloc(46*sizeof(char*));
	int letter = fgetc(texto);
	int cont = 0;
	int aux;
	while(letter != EOF){

		if((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122) || letter == 45){
			word[cont] = letter;
			aux = 0;
			cont++;
		}
		if((letter == 32 || letter == '\n') && aux == 0){
			word[cont] = '\0';
			lowerCase(word); //transforma a palavra lida em caixa baixa
			if(search(hashDontCare,word) == NULL){
				printf("%s\n", word);
				Node* node1 = createNode(word); //cria o nó a ser inserido na lista da hash
				put (hashTexto, node1); //coloca o nó na hash
			}
			cont = 0;
			aux = 1;
		}
		letter = fgetc(texto);
	}

}








































/*void readHTML(FILE* texto, HashTable* hashTexto, HashTable* hashDontCare){
	char* word = malloc(46*sizeof(char*));
	printf("te\n");
	int letter = fgetc(texto);
	printf("tes\n");

	int cont = 0;
	int aux;
	int aux2;
	printf("test\n");
	while(letter != EOF){		
		printf("teste\n");
		if(letter == '>'){
			printf("teste1\n");
			aux2 = 1;
		}	
		printf("teste2\n");
		while(letter != '<' && aux2 == 1){
			if((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122) || letter == 45){
				word[cont] = letter;
				aux = 0;
				cont++;
			}
			if((letter == 32 || letter == '\n') && aux == 0){
				word[cont] = '\0';
				lowerCase(word); //transforma a palavra lida em caixa baixa
				if(search(hashDontCare,word) == NULL){
					printf("%s\n", word);
					Node* node1 = createNode(word); //cria o nó a ser inserido na lista da hash
					put (hashTexto, node1); //coloca o nó na hash
				}
				cont = 0;
				aux = 1;
			}
		}				
		letter = fgetc(texto);
	}

}
*/