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
			if(word[0] != '-' && search(hashDontCare,word) == NULL){
				Node* node1 = createNode(word); //cria o nó a ser inserido na lista da hash
				put (hashTexto, node1); //coloca o nó na hash
			}
			cont = 0;
			aux = 1;
		}
		letter = fgetc(texto);
	}

}

void copyDocument(FILE* doc, FILE* saida){
	int letter;
	 while (1) {
      letter = fgetc(doc);
 
      if (letter == EOF)
         break;
      else
         putc(letter, saida);
   }

}


void write(FILE* saida, FILE* saidaHTML, HashTable* hashTexto){
	float fontSize;
	int aux;
	int contador = 0;
	FILE* header = fopen("header.tex", "r");
	FILE* headerHTML = fopen("header.html", "r");
	copyDocument(header, saida);
	copyDocument(headerHTML, saidaHTML);



	for(int i = 0; i < CAPACITY; i++){
		if(isEmpty(hashTexto->data[i]) == 0){
			Node* node = hashTexto->data[i]->begin;
			while(node != NULL){
				if(node->quantidade > 1){
					aux = 1;
					contador++;
					fontSize = (node->quantidade)*11;
					if(fontSize >= 99 && aux == 1){
						fprintf(saida, "{\\Huge \\textcolor{AzulEscuro} {\\bf %s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						fprintf(saidaHTML, "<span class=\"cor6 Huge\"><strong>%s</strong></span><span class=\"cor6 footnotesize\">(%d)</span> ",node->word, node->quantidade);
						aux = 0;
					}
					if(fontSize >= 88 && aux == 1){
						fprintf(saida, "{\\huge \\textcolor{Amarelo} {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						fprintf(saidaHTML, "<span class=\"cor2 huge\">%s</span><span class=\"cor6 footnotesize\">(%d)</span> ",node->word, node->quantidade);
						aux = 0;
					}
					if(fontSize >= 77 && aux == 1){
						fprintf(saida, "{\\LARGE \\textcolor{Rosa} {\\bf %s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						fprintf(saidaHTML, "<span class=\"cor3 Large\"><strong>%s</strong></span><span class=\"cor6 footnotesize\">(%d)</span> ",node->word, node->quantidade);
						aux = 0;
					}
					if(fontSize >= 66 && aux == 1){
						fprintf(saida, "{\\Large \\textcolor{VermEscuro} {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						fprintf(saidaHTML, "<span class=\"cor4 large\">%s</span><span class=\"cor6 footnotesize\">(%d)</span> ",node->word, node->quantidade);
						aux = 0;
					}
					if(fontSize >= 55 && aux == 1){
						fprintf(saida, "{\\large \\textcolor{Roxo} {\\bf %s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						fprintf(saidaHTML, "<span class=\"cor5 normalsize\"><strong>%s</strong></span><span class=\"cor6 footnotesize\">(%d)</span> ",node->word, node->quantidade);
						aux = 0;
					}
					if(fontSize >= 44 && aux == 1){
						fprintf(saida, "{\\normalsize \\textcolor{VerdeLocao} {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						fprintf(saidaHTML, "<span class=\"cor6 small\">%s</span><span class=\"cor6 footnotesize\">(%d)</span> ",node->word, node->quantidade);
						aux = 0;
					}
					if(fontSize >= 33 && aux == 1){
						fprintf(saida, "{\\small \\textcolor{Laranja} {\\bf %s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						fprintf(saidaHTML, "<span class=\"cor1 footnotesize\"><strong>%s</strong></span><span class=\"cor6 footnotesize\">(%d)</span> ",node->word, node->quantidade);

						aux = 0;
					}
					if(fontSize >= 22 && aux == 1){
						fprintf(saida, "{\\footnotesize \\textcolor{Verde} {%s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						fprintf(saidaHTML, "<span class=\"cor2 scriptsize\">%s</span><span class=\"cor6 footnotesize\">(%d)</span> ",node->word, node->quantidade);
						aux = 0;
					}
					if(fontSize >= 11 && aux == 1){
						fprintf(saida, "{\\scriptsize \\textcolor{AzulEscuro} {\\bf %s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
						aux = 0;
					}
					if(fontSize >= 1 && aux == 1){
						fprintf(saida, "{\\tiny {\\bf %s}} \\footnotesize{(%d)} ",node->word, node->quantidade);
					}
					if(contador >= 5){
						fprintf(saida, " \\\\ ");
						fprintf(saidaHTML, "<br>");
						contador = 0;
					}
				}
				node = node->next;
			}

		}
	}
	fprintf(saida, "\n \\\\ \\hline\n");
	fprintf(saida, "\\end{longtable}\n");
	fprintf(saida, "\\end{center}\n");
	fprintf(saida, "\\end{document}\n");

	fprintf(saidaHTML, "</div>\n");
	fprintf(saidaHTML, "</body>\n");
	fprintf(saidaHTML, "</html>\n");
}
