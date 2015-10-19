#include <stdio.h>

void imprime_alguma_coisa(int n){
  if(n!=0){
    imprime_alguma_coisa(n/2);
    printf("%c", '0'+n%2);       
  }  
}
int main(void){
  int n, k;
  scanf("%d", &k);
  while(k>0){
    scanf("%d", &n);
    imprime_alguma_coisa(n);    
    k--;
  }  
  return 0;
}