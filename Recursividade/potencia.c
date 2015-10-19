#include <stdio.h>

int potR(int x, int n){
  if(n == 0) return 1;  
  return x*potR(x, n-1);
  
}

int main(void){
  int x,n,i;
  scanf("%d", &i);
  while(i>0){
    scanf("%d", &x);
    scanf("%d", &n);
    printf("%d\n", potR(x,n));  
    i--;
  }  
  return 0;
}