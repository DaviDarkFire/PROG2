#include <stdio.h>
#include <math.h>
#define LC 9 //linha e coluna

//preenche a matriz com os valores do usuário
void imprime_jogo(int matriz[LC][LC]){
      for (int i = 0; i < LC; i++){
            for (int j = 0; j < LC; j++){
                  printf("%d ", matriz[i][j]);
            }
            printf("\n");
      }
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
	linha = linha-linha%aux;
	coluna = coluna-coluna%aux;
	int l = linha+aux;
	int c = coluna+aux;
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
	if(verifica_area(matriz, n, linha, coluna) && verifica_coluna_e_linha(matriz, n, linha coluna))
		return 1;
	else
		return 0;
}

//a seguinte função recebe a matriz com os números e resove o jogo
int resolve_jogo(matriz[LC][LC], n){
	





}


int main(void){
    int matriz[LC][LC]; //cria a matriz
    le_jogo(matriz);
    imprime_jogo(matriz);

  return 0;
}
