#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Vector.h"


void meuBubbleSortPutao(tVector *V){
  int temp;
  for(int i = V->numberOfElements-1; i > 0; i--){
    for(int j = 0; j < i; j++){      
      if (V->data[j] > V->data[j+1]){
	temp = V->data[j];
	V->data[j] = V->data[j+1];
	V->data[j+1] = temp;
      }	
    }   
  }    
}


void meu_BubbleSort_Putao_Recursivo_Interface(tVector *V){
  
  meuBubbleSortPutaoRecursivo(V, V->numberOfElements-1);
  
}


int meuBubbleSortPutaoRecursivo(tVector *V, int i){
  int temp;
  
  if(i == 0) return;
  
  for(int j = 0; j < i; j++){   
    if(V->data[j] > V->data[j+1]){      
      temp = V->data[j+1];
      V->data[j+1] = V->data[j];
      V->data[j] = temp;      
    }    
  }  
  return meuBubbleSortPutaoRecursivo(V, i-1);  
}


int main(void){
  
  int n;
  scanf("%d", &n);
  srand(time(NULL));
  
  tVector *V = create(n);
  
  for(int i = 0; i < n; i++){
    
    add(V, rand()%(n*2));    
  }
  
  print(V);
  
  meu_BubbleSort_Putao_Recursivo_Interface(V);
  
  print(V);  
  return 0;
}