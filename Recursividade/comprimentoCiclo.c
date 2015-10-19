#include <stdio.h>


int ciclo(int n){  
  int cont = 0;
  while(n != 1){
    printf("%d ",n);
    if(n%2 == 0){
      n = n/2;
    }else{
      n = n*3+1;
    }          
    cont++;    
  }
  printf("%d",n);
  return cont+1;
}


int cicloR(int n){
  int cont = 1;
  printf("%d ", n);
  if(n == 1){     
    return cont;
  }    
  if(n%2 == 0){    
    return cicloR(n/2)+cont;
  }else{
    return cicloR(3*n+1)+cont;  
  }  
}


int main(void){
  int k,n;
  scanf("%d", &k);
  while(k>0){
    scanf("%d", &n);
    printf("\n%d\n", cicloR(n));    
    k--;
  }  
  return 0;
}