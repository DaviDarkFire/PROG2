#include <stdio.h>

int piso_log2(int n){
  if(n==1) return 0;
  return piso_log2(n/2)+1;  
}

int main(void){
  int k, n;
  scanf("%d", &k);
  while(k>0){
    scanf("%d", &n);
    printf("%d\n", piso_log2(n));            
    k--;
  }    
  return 0;
}