#include <stdio.h>
#include <stdlib.h>
void medias(int n, int m, int p, float ***matriz){  
  for(int i = 0; i < n; i++){           
    for(int j = 0; j < m; j++){
      float media_disciplina = 0;
      for(int k = 0; k < p; k++){
	media_disciplina += matriz[i][j][k];		         
      }
      printf("Média Disciplina: %f", media_disciplina/p);
    }    
  }
  
  
  
    
}

int main(void){
  int m, n, p;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &p);
  //a partir de agora vou declarar a matriz tridimensional
  float ***matriz = NULL;
  matriz = malloc(n * sizeof(float**));
  
  if(!matriz) exit(1);
  
  for(int i = 0; i < n; i++){
    
    matriz[i] = malloc(m * sizeof(float*));
    
    if(!matriz[i]) exit(1);
    
    for(int j = 0; j < m; j++){
                  
      matriz[i][j] = malloc(p * sizeof(float));      
      
      if(!matriz[i][j]) exit(1);
      
    }    
  }
  
  for(int i = 0; i < n; i++){           
    for(int j = 0; j < m; j++){
      for(int k = 0; k < p; k++){
	scanf("%f", &matriz[i][j][k]);	         
      }        
    }    
  }
  
  medias(n, m, p, matriz);
  
  for(int i = 0; i < n; i++){           
    for(int j = 0; j < m; j++){
      for(int k = 0; k < p; k++){
	printf("%f\n", matriz[i][j][k]);	          
      }        
    }    
  }
            
  return 0;
}