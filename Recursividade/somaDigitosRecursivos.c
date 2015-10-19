#include <stdio.h>

int soma_digitos(int n){
  int ini, fim;
  //a variável ini recebe o valor de n menos o último dígito
  ini = n/10;
  //a variável fim recebe o último dígito de n
  fim = n%10;  
  if(ini <= 0) return fim; //se a variável ini for menor ou igual a zero isso significa que o número acabou e que deve-se retornar a variável fim, ou o resto
  return fim+soma_digitos(ini); //no mais ele retorna o último digito que esta na variável fim, mais a própria função passando como parâmetro os números que sobraram        
}
int main(void){
  int k, n;
  scanf("%d", &k);
  while(k>0){
   scanf("%d", &n);
   printf("%d\n", soma_digitos(n));    
    k--;
  }  
  return 0;
}