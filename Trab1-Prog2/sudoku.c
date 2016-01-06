#include <stdio.h>
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
// retorna 1 caso encontre e 0 caso não encontre
int verifica_coluna_e_linha(int matriz[LC][LC], int n, int linha, int coluna){
      int aux = 0;

      for (int j = 0; j < LC; j++){
            if(matriz[linha][j] == n || matriz[j][coluna] == n)
                  aux = 1;
      }
      return aux;
}

int verifica_area(int matriz[LC][LC], int n, int linha, int coluna){

}

int main(void){
    int matriz[LC][LC]; //cria a matriz
    le_jogo(matriz);
    imprime_jogo(matriz);

  return 0;
}
