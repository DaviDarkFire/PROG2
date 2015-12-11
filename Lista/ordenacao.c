#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void sort(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

void bubble_sort(int n, int v[MAX]){
	for(int i = n-1; i > 0; i--){ // começa do final do vetor
		for(int j = 0; j < i; j++){ //começa de zero e vai até o i
			if(v[j] >= v[j+1]){ //compara de a posição em que o contador está atualmente é maior que a próxima
				sort(&v[j], &v[j+1]); //se for maior ele usa o método sort pra trocar os valores das posições
			}
		}
	}
}

int bubble_sort_rec(int n, int v[MAX]){

	for(int j = 0; j < n; j++){ //começa de zero e vai até o n
		if(v[j] >= v[j+1]){ //compara de a posição em que o contador está atualmente é maior que a próxima
			sort(&v[j], &v[j+1]); //se for maior ele usa o método sort pra trocar os valores das posições
		}
	}

	if(n == 0) return 0; //condição de parada da função recursiva
	return bubble_sort_rec(n-1, v);	// retorno da função recursiva

}

void selection_sort(int n, int v[MAX]){

	int min; //declara uma variável min(mínimo) que eu não sei se é necessária, mas é usada
	for(int i = 0; i < n-1; i++){ //vai até a penúltima posição do vetor pois na última vez que  laço de fora rodar a última posição ja vai ser o maior vetor
		min = i; // a min recebe o valor do i

		for(int j = i+1; j < n; j++){ //vai começar da posição i+1 e vai até a última posição do vetor
			if(v[min] > v[j]){ // ve se o valor do vetor na posição que foi tomada como menor é menor que o valor da posição atual
				min = j; // se for maior o ´indice do valor mínimo recebe o índice do verdadeiro valor mínimo
			}
		}
		sort(&v[min], &v[i]); // no final do laço interno quando descobriu o verdadeiro valor mínimo em relação ao primeiro que foi tomado
		// faz a troca de posição
	}
}

int selection_sort_rec(int i, int n, int v[MAX]){
	int min = i;
	for(int j = i+1; j < n; j++){ //vai começar da posição i+1 e vai até a última posição do vetor
		if(v[min] > v[j]){ // ve se o valor do vetor na posição que foi tomada como menor é menor que o valor da posição atual
			min = j; // se for maior o ´indice do valor mínimo recebe o índice do verdadeiro valor mínimo
		}
	}
	sort(&v[min], &v[i]); // no final do laço interno quando descobriu o verdadeiro valor mínimo em relação ao primeiro que foi tomado
	// faz a troca de posição

	if(i == n-2) return 0;
	return selection_sort_rec(i+1, n, v);
}

void insertion_sort(int n, int v[MAX]){
	int x, i, j;
	for(i = 1; i < n; i++){ //não faço
		x = v[i];
		for(j = i - 1; j >= 0 && v[j] > x; j--){ //a mínima ideia
			v[j+1] = v[j]; //de como
		}
		v[j+1] = x; //essa pemba funciona
	}
}
void merge(int inicio, int meio, int fim, int v[MAX]){
	int i, j, k = 0;

	i = inicio;
	j = meio;

	int *w = malloc((fim - inicio) * sizeof(int));

	while(i < meio && j < fim){
		if(v[i] < v[j]) w[k++] = v[i++];
		else w[k++] = v[j++];
	}

	while(i < meio) w[k++] = v[i++];
	while(j < fim) w[k++] = v[j++];

	for(int cont = inicio; cont < fim; cont++){
		v[cont] = w[cont-inicio];
	}
	free(w);
}

void merge_sort(int v[MAX], int left, int right){
	if(left < right-1){
		int mediana = (left+right)/2;
		merge_sort(v, left, mediana);
		merge_sort(v, mediana, right);
		merge(left, mediana, right, v);
	}



}

int main(void){
	int n;
	scanf("%d", &n);
	int *v = malloc(n * sizeof(int));
	srand(time(NULL));

	for(int i = 0; i < n; i++){
		v[i] = rand()%n;

	}


	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);

	}
	printf("\n");

	merge_sort(v, 0, n);
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);

	}
	printf("\n");
	return 0;
}
