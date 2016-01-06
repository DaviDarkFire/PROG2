#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

void sort(int *a, int *b){
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
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

int partition(int v[MAX], int inicio, int fim){
  int i, j;
  int x = v[inicio];
  i = inicio - 1;
  j = fim + 1;
  while(1){
    do{i++; }while(v[i] < x);
    do{j--; }while(v[j] > x);
    if(i < j) sort(&v[i], &v[j]);
    else return j;
  }
}

void quickSort(int v[MAX], int inicio, int fim){
  if(inicio < fim){
    int meio = partition(v, inicio, fim);
    quickSort(v, inicio, meio);
    quickSort(v, meio+1, fim);
  }
}

int main(void){
  int n;
  scanf("%d", &n);
  int *v = malloc(n * sizeof(int));
  srand(time(NULL));
  for(int i = 0; i < n; i++){
    v[i] = rand()%(n+1);
  }
  for(int i = 0; i < n; i++){
    printf("%d ",v[i]);
  }
  printf("\n");
  quickSort(v, 0, n-1);
  for(int i = 0; i < n; i++){
    printf("%d ",v[i]);
  }
  printf("\n");
  return 0;
}
