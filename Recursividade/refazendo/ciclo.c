#include <stdio.h> 

int ciclo(int n){  
  int cu = 1;
  printf("%d ", n);
  
  if(n==1)    //A CONDIÇÃO DE PARADA É NO COMEÇO PAU NO CU ARROMBADO DO CARALHO
    return cu;//A CONDIÇÃO DE PARADA É NO COMEÇO PAU NO CU ARROMBADO DO CARALHO
  
  if(n%2 == 0){
    cu = ciclo(n/2)+1;
    return cu;
  }  
  
  if(n%2 != 0){
    cu = ciclo(3*n+1)+1;
    return cu;
  }  
    
}

int main(void){
  int n;
  scanf("%d", &n);
  printf("\n%d\n", ciclo(n));
  
  return 0;
}
