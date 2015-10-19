#include <stdio.h>
int mdc(int a, int b){
  if(b==0) return a;  
  int r = mdc (b,a%b);
  return r;
  
}

int main(void){
  int a,b,i;
  scanf("%d", &i);
  while(i>0){
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d\n", mdc(a,b));  
    i--;
  }  
  return 0;
}