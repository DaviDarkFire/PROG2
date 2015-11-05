#include <stdio.h>

int soma_digito(int n){
	int ini = n/10;
	int fim = n%10;
	if(ini<=0) return fim;
	return soma_digito(ini)+fim;




}

int main(void){
	int n;
	scanf("%d", &n);
	printf("%d\n", soma_digito(n));
	return 0;
}
