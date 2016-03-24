#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

/*
/* Algumas funções uteis:

FILE* fopen (char *nome_do_arquivo, char * modo) // abre arquivo

modo:
r: leitura
w: escrita
a: adicionar texto no final "append"
r+: leitura e escrita
w+: leitura e escrita
a+: leitura e escrita com "append"
rb: leitura em modo binário
wb: escrita em modo binário
ab: "append" em modo binário


fclose (FILE* ptr) ; // fecha arquivo apontado por ptr


int fgetc (FILE* ptr); // le o proximo caractere do arquivo apontado por ptr, avançando o ponteiro para  apróxima posição. o caractere lido é retornado pela função.
                       // em caso de erro, devolve EOF
int fputc (int caractere, FILE*ptr) // escreve um unico caractere no arquivo , incrementa o ponteiro 
			// em caso de erro, devolve EOF


int fscanf (FILE*, char *formato, ...)   // similar a scanf - primeiro argumento indica o ponteiro para o arquivo, demais argumentos são os mesmos da funcao scanf
int fprintf(FILE*, char *formato, ...)   // similar a printf - primeiro argumento indica o ponteiro para o arquivo, demais argumentos são os mesmos da funcao printf


Ponteiros para arquivo do sistema: (tipo FILE*)
stdin: ponteiro para arquivo do sistema - em geral associado ao teclado
stdout: ponteiro para arquivo do sistema - em geral associado ao monitor 
stderr: ponteiro para arquivo do sistema - em geral associado ao monitor (utili para tratamento de erros e exceções) - arquivo padr~ao de erro

exemplos: 
scanf("%d", &x) =  fscanf(stdin, "%d", &x) // leitura  apartir do teclado
printf("%d", x) =  fprintf(stdout, "%d", x)  // escrita no monitor


*/ 


int main ()
{


	FILE *ptr1, *ptr2/*, *ptr3*/;
	//char x;

	ptr1 = fopen ("in.txt", "r"); // modo = leitura
	if (!ptr1) printf("\nProblemas para abrir o arquivo in.txt");
	ptr2 = fopen ("out.txt", "w"); // modo = escrita
	if (!ptr2) printf("\nProblemas para abrir o arquivo out.txt");
	/*ptr3 = fopen ("out_append.txt", "a"); // modo = adicionar texto "append"
	if (!ptr3) printf("\nProblemas para abrir o arquivo out_append.txt");*/

	/*x = fgetc (ptr1);
	while (x!=EOF) //EOF = final do arquivo(End Of File), ou seja, enquanto eu não chegar no final do arquivo
	{

		fputc(x,ptr2);
		fputc(x,ptr3);
		x = fgetc (ptr1);
	}*/

	
	Queue *Queue = create ();
	while(fgetc(ptr1) != EOF){
		char xMagnitude = fgetc(ptr1); 
		
		int num = fscanf(ptr1, "%d", &num);
		//fazer um print de fila em arquivo e print de node tbm

		if(xMagnitude == '+'){
			Node* node = createNode(num);
			enqueue(Queue, node);


		}else{
			dequeue(Queue);
		}
	}

	printQueue(Queue);

	
	destroy(Queue);
	//remove ("out.txt");
	//rename ("out.txt", "out2.txt");
	fclose (ptr1);
	fclose (ptr2);	
	return 0;
}
