#include <stdio.h>
#define MAX 100

float soma(int n, float v[MAX]){
  float s = v[n];
  if(n<0) return s;
  s = soma(n-1, v)+s;  
  return s;
  
}


int main(void){
  int n, k;
  float v[MAX];
  scanf("%d", &k);
  while(k>0){
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
      scanf("%f", &v[i]);            
    }    
    printf("%f\n", soma(n-1, v));
    k--;
  }        
  return 0;
}