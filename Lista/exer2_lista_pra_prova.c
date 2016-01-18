#include <stdio.h>

int soma(int a, int b){		
	if(b == 0) return a;		
	return soma(++a, --b);
}
int main(void){

	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", soma(a, b));
	return 0;
}