#include <stdio.h>
#include "Vector.h"
#define MAX 10


int buscaBinariaRecursiva(tVector *V, int esquerda, int direita, int x){
	int m;
	m = (V->numberOfElements-1)/2;

	if(esquerda == direita-1) return direita;

	if(x > V->data[m]){
		return buscaBinariaRecursiva(V, m, direita, x);
	}
	return buscaBinariaRecursiva(V, esquerda, m, x);	
}

void buscaBinariaRecursivaInterface(tVector *V, int x){
	printf("%d\n", buscaBinariaRecursiva(V, 0, V->numberOfElements-1, x));
}


int main(void){
	int x;
	scanf("%d", &x);

	tVector *V = create(MAX);

	for(int i = 0; i < MAX; i++){

		add(V, i);		
	}

	print(V);

	buscaBinariaRecursivaInterface(V, x);





	return 0;
}