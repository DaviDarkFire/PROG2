#include <stdio.h>
#include <stdlib.h>

int vectorSum(int *v, int n){  
  
  if(n == 0){
    return v[n];
  }
  
  return vectorSum(v, n-1)+v[n];
   
  
  
  
  
  
}

int main(void){
  int *v, n;
  scanf("%d", &n);
  v = malloc(n * sizeof(int));
  
  for(int i = 0; i < n; i++){
    scanf("%d", &v[i]);    
  }  
  printf("%d\n", vectorSum(v, n-1));
  
  
  
  return 0;
}