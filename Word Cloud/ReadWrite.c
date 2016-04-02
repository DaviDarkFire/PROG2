#include <stdio.h>
#include <stdlib.h>
#include "ReadWrite.h"

#define CAPACITY 26

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
				Node* node1 = createNode(word); //cria o nó a ser inserido na lista da hash
				put (hashTexto, node1); //coloca o nó na hash
			}
			cont = 0;
			aux = 1;
		}
		letter = fgetc(texto);
	}

}

int importantWordsCount(HashTable* hashTexto){
	int count = 0;
	for(int i = 0; i < CAPACITY; i++){
		if(isEmpty(hashTexto->data[i]) == 0){
			Node* node = hashTexto->data[i]->begin;
			while(node != NULL){
				if(node->quantidade > 1){
					count++;
				}
				node = node->next;
			}
		}
	}
	return count;

}



float wordSize(int total, int n){
	float n1 = n;
	float total1 = total;
	return (n1/total1)*100;
}
void write(FILE* saida, HashTable* hashTexto){
	float fontSize;
	int total;
	for(int i = 0; i < CAPACITY; i++){
		if(isEmpty(hashTexto->data[i]) == 0){

			Node* node = hashTexto->data[i]->begin;

			while(node != NULL){

				if(node->quantidade > 1){
					total = importantWordsCount(hashTexto);
					fontSize = wordSize(total, node->quantidade);


					if(fontSize >= 99){
						fprintf(saida, "{\\Huge {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
					}
					if(fontSize >= 88){
						fprintf(saida, "{\\huge {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);

					}
					if(fontSize >= 77){
						fprintf(saida, "{\\LARGE {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);

					}
					if(fontSize >= 66){
						fprintf(saida, "{\\Large {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);

					}
					if(fontSize >= 55){
						fprintf(saida, "{\\large {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);

					}
					if(fontSize >= 44){
						fprintf(saida, "{\\normalsize {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);

					}
					if(fontSize >= 33){
						fprintf(saida, "{\\small {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);

					}
					if(fontSize >= 22){
						fprintf(saida, "{\\footnotesize {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);

					}
					if(fontSize >= 11){
						fprintf(saida, "{\\scriptsize {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
					}
					if(fontSize >= 1){
						fprintf(saida, "{\\tiny {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
					}
				}
				node = node->next;
			}

		}
	}
	fprintf(saida, "\n%s\n", "\\hline");
	fprintf(saida, "%s\n", "\\end{tabular}");
	fprintf(saida, "%s\n", "\\end{center}");
	fprintf(saida, "%s\n", "\\end{document}");
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
