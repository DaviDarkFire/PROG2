#include <stdio.h>
#define MAX 200
int maxVector(int V[MAX], int n){
  if(n==0) return V[0];
  if(V[n] > maxVector(V, n-1)){
    return V[n];    
  }
  return maxVector(V, n-1);
  
  
  
}

int minVector(int V[MAX], int n){
  if(n==0) return V[0];
  if(V[n] < minVector(V, n-1)){
    return V[n];    
  }
  return minVector(V, n-1);
  
  
  
  
  
}

int main(void){
  int n, i, val;
  int V[MAX];
  scanf("%d", &n);
  for(i = 0; i<n; i++){
    scanf("%d", &V[i]);        
  }
  printf("%d\n%d\n", maxVector(V, n-1), minVector(V, n-1));
  
  
  
  
  
  return 0;
}