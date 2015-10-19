#include <stdio.h>

int fib(int i){
  if(i==1) return 1;
  if(i==2) return 1;
  return fib(i-1)+fib(i-2);          
}
int main(void){
  int k, i;
  scanf("%d", &k);
  while(k>0){
   scanf("%d", &i);
   printf("%d\n", fib(i));    
    k--;
  }  
  return 0;
}