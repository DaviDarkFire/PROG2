#include <stdio.h>

int h(int n){
  if (n==0) return 0;
  if (n>4) return n;
  return h(2+h(2*n));    
}

int main(void){
  int n;
  scanf("%d", &n);
  printf("%d\n", h(n));  
  return 0;
}