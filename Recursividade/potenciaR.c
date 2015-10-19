#include <stdio.h>

int potencia(int x, int n){
  if(n == 0) return 1;
  if(n%2 == 0){
    return potencia(x, n/2)*potencia(x, n/2);    
  }else{
    return x*potencia(x, n-1);          
  }  
}
int main(void){
  int k, x, n;
  scanf("%d", &k);
  while(k>0){
    scanf("%d", &x);
    scanf("%d", &n);
    printf("%d\n", potencia(x, n));    
    k--;
  }  
  return 0;
}