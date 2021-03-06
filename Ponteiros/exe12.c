#include <stdio.h>
#include <stdlib.h>

void maxMinVector(int *v, int *max, int *min, int n){
  *max = v[0];
  *min = v[0];
  for(int i = 1; i < n; i++){
    if(*max <= v[i]){
      *max = v[i];            
    }
    if(*min >= v[i]){
      *min = v[i];      
    }        
  }  
}

int main(void){
  
  int *v, n, max, min;
  scanf("%d", &n);
  v = malloc(n * sizeof(int));
  
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);    
  }
  
  maxMinVector(v, &max, &min, n);
  printf("Máximo: %d Mínimo: %d\n", max, min);
  
  
  
  
  
  return 0;
}