#include <stdio.h> 
#define MAX 100

int max(int n, int v[MAX]){
  if (n == 0) return v[0];
  if(v[n] > max(n-1, v)){
    return v[n];
  }  
  return max(n-1, v);  
}

int min(int n, int v[MAX]){
  if (n == 0) return v[0];
  if(v[n] < min(n-1, v)){
    return v[n];
  }  
  return min(n-1, v);  
}

int main(void){
  int k, n, v[MAX];
  scanf("%d", &k);
  while(k>0){
      scanf("%d", &n);
      for(int i = 0; i < n; i++){
	scanf("%d", &v[i]);
      }
      
      printf("%d\n%d\n", max(n-1, v), min(n-1, v));    
    k--;
  }
  
  
  
  
  
}
