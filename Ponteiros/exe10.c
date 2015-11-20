#include <stdio.h>
#include <stdlib.h>

int main(void){
  int m, n;
  scanf("%d %d", &m, &n);
  
  int **matriz;
  matriz = malloc(m * sizeof(int*));  
  for(int i = 0; i < m; i++){
    matriz[i] = malloc(n * sizeof(int));    
  }
  
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &matriz[i][j]);
      
    }
  }
  
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      printf("Posição: [%d][%d], Valor: %d\n", i, j, matriz[i][j]);
      
    }
  }
  
  
  free(matriz);
  free(*matriz);
  
  
   
  return 0;
}