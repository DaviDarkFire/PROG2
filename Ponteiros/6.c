#include <stdio.h>

int g(int n){
  if(n == 0){
    return 1;
  }
  return 2*g(n-1);  
}

int main(void){
  int k, n;
  scanf("%d", &k);
  while(k>0){
    scanf("%d", &n);
    printf("%d\n", g(n));            
    k--;
  }
        
  return 0;
}