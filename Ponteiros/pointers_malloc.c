#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int main(void){
  /*para criar um array N-dimensional vamos primeiro criar uma variável ponteiro com N pointers
   nesse caso, como queremos um array tridmensional vamos criar uma variável ponteiro com 3 pointers*/
  int ***x;
  /*agora essa variável vai apontar para um espaço na memória criado com malloc que também é um ponteiro com 2 pointers, 
   atente que o int dentro de sizeof é seguido de 2 pointers*/
  x = malloc(MAX * sizeof(int**));  
  for(int i = 0; i < MAX; i++){
    /*o int dentro de sizeof de agora é seguido de apenas 1 pointer*/ 
    x[i] = malloc(MAX * sizeof(int*));
    for(int j = 0; j < MAX; j++){
      x[j] = malloc(MAX * sizeof(int)); //esse espaço na memória é realmente onde estão os dados            
    }        
  }  
  for(int i = 0; i < MAX; i++){
        
    for(int j = 0; j < MAX; j++){
      
      for(int k = 0; k < MAX; k++){
	
	printf("Posição x[%d][%d][%d] do array no endereço de memória: %p\n", i, j, k, (void*)&x[i][j][k]);	
      }
      
    }        
  }
  
  
  
  
  
  
  
  return 0;
}