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
	for(int i = n-1; i > 0, i--){
		for(int j = 0; j < i; j++){
			if(v[j] > V[j+1]){
				sort(&v[j], &v[j+1]);
			}
		}
	}
}
void selection_sort(int n, int v[MAX]){

	int min;
	for(int i = 0; i < n-1; i++){
		min = i;

		for(int j = i+1; j < n; j++){
			if(v[min] > v[j]){
				min = j;
			}
		}
		sort(&v[min], &v[i]);
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

	selection_sort(n, v);
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);

	}
	printf("\n");










	return 0;
}