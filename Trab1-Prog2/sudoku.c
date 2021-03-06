#include <stdio.h> //inclui as funções de entrada e saída básicos necessários para o desenvolvimento deste trabalho
#include <math.h>  //inclui funções matemáticas necessárias no desenvolvimento deste software
#define LC 16 //define o tamanho da matriz, pra um jogo 16x16 alterar o valor 9 por 16

//imprime a matriz
void imprime_jogo(int matriz[LC][LC]){
      for (int i = 0; i < LC; i++){
            for (int j = 0; j < LC; j++){
                  printf("%d ", matriz[i][j]);
            }
            printf("\n");
      }
      printf("\n");
}
//preenche a matriz com os valores do usuário
void le_jogo(int matriz[LC][LC]){
      for (int i = 0; i < LC; i++){
            for (int j = 0; j < LC; j++){
                  scanf("%d", &matriz[i][j]);
            }
      }
}

// verifica se um número passado existe naquela linha e coluna
// retorna 0 caso encontre e 1 caso não encontre
int verifica_coluna_e_linha(int matriz[LC][LC], int n, int linha, int coluna){
      int aux = 1;

      for (int j = 0; j < LC; j++){
            if(matriz[linha][j] == n || matriz[j][coluna] == n)
                  aux = 0;
      }
      return aux;
}
//verifica se determinado número existe em uma área
//retorna 0 se existir, e 1 se não existir
int verifica_area(int matriz[LC][LC], int n, int linha, int coluna){
	int aux = sqrt(LC);
	// nas próximas 2 linhas, a variável linha e a variável coluna recebem a conta que faz identificar qual a área que os valores passados estão
	linha = linha-linha%aux;
	coluna = coluna-coluna%aux;
	// as próximas 2 linhas definem qual será o tamanho da área, ou seja, até onde o for vai, no caso de matriz 9x9 ele vai até 3, no caso de 16x16 ele vai até 4
	int l = linha+aux;
	int c = coluna+aux;
	//os for a seguir servem para verificar se o número passado para a função existem na área
	for(int i = linha; i < l; i++){
		for(int j = coluna; j < c; j++){
			if(matriz[i][j] == n){
				return 0;
			}
		}
	}
	return 1;
}
//a seguinte função verifica se um número pode ser colocado em determinada posição
//analisando a área , a coluna e a linha
int pode_preencher(int matriz[LC][LC], int n, int linha, int coluna){
	if(verifica_area(matriz, n, linha, coluna) && verifica_coluna_e_linha(matriz, n, linha, coluna))
		return 1;
	else
		return 0;
}
//a seguinte função verifica se a matriz está totalmente preenchida
//e retorna através de referência o valor da linha e da coluna, estando ela preenchida ou não
int verifica_matriz(int matriz[LC][LC], int *linha, int *coluna){
	for(int i = 0; i < LC; i++){
            *linha = i;
		for(int j = 0; j < LC; j ++){
                  *coluna = j;
			if(matriz[i][j] == 0)
				return 1;
		}
	}
	return 0;

}
void copiar(int matriz[LC][LC], int copia[LC][LC]){
	for(int i = 0; i < LC; i++){
		for(int j = 0; j < LC; j++){
			copia[i][j] = matriz[i][j];

		}
	}
}

//a seguinte função recebe a matriz com os números e resove o jogo
int resolve_sudoku(int matriz[LC][LC], int copia[LC][LC] , int *cont)
{
    int coluna, linha;
	//o if a seguir verifica se a matriz está totalmente preenchida, se estiver retorna 1
	//ou seja essa é a condição de parada
    if (!verifica_matriz(matriz, &linha, &coluna))
       return 1;
	//esse é o for que vai escolher entre os valores de 1 até 9 qual vai ser colocado em um espaço em branco
    for (int num = 1; num <= LC; num++)
    {
	//se for possível preencher a matriz (não hover valores na mesma área, linha ou coluna)
        if (pode_preencher(matriz, num, linha, coluna))
        {
		//a matriz recebe o número testado na função chamada no if acima
            matriz[linha][coluna] = num;
			//o if a seguir faz a chamada recursiva da função e retorna 1 se a próxima posição for preenchida
	        if (resolve_sudoku(matriz, copia, cont))
		    {
		        (*cont)++; //conta uma possibilidade de resolução
		         copiar(matriz, copia); //faz uma copia da resolução pra matriz copia
	               matriz[linha][coluna] = 0; //retorna a posição igual a zero pra testar as outras possibilidades

		    }
		    else
		    {
			//se a próxima posição não for preenchida, isso significa que o valor colocado na posição atual não é bom
			//desse a próxima linha faz essa posição ficar em branco novamente para que ela possa ser testada no pŕoximo loop do for
	                matriz[linha][coluna] = 0;
	        }
        }
    }
	//se o return for zero, a função recursiva continua
    return 0;
}

int main(void){
    int cont = 0; //cria um contador pras armazenar as soluções do sudoku
    int copia[LC][LC]; //cria uma matriz que vai servir pra armazenar o jogo resolvido,
    // visto que a outra matriz vai servir pra contar as possibilidades de resolução
    int matriz[LC][LC]; //cria a matriz
    le_jogo(matriz); //le o jogo
    resolve_sudoku(matriz, copia, &cont); //resolve o jogo
    if(cont){
    	printf("Este jogo possui %2d soluções(ção).\n", cont);
    }
    imprime_jogo(copia); //imprime a matriz passada
    return 0;
}
