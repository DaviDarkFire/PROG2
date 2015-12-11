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

void merge(int v[MAX], int inicio, int meio, int fim){
  int i, j, k = 0;

  i = inicio;
  j = meio;

  int *w = malloc((fim-inicio) * sizeof(int));

  while(i < meio && j < fim){
    if(v[i] < v[j]) w[k++] = v[i++];
    else w[k++] = v[j++];
  }
  while(i < meio) w[k++] = v[i++];
  while(j < fim) w[k++] = v[j++];

  for(int l = inicio; i < fim; i++){
    v[l] = w[l-inicio];
  }
  free(w);
}

void mergeSort(int v[MAX], int inicio, int fim){
  if(inicio < fim){
    meio = (inicio+fim)/2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio, fim);
    merge(v, inicio, meio fim);
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
  mergeSort(v, 0, n);
  for(int i = 0; i < n; i++){
    printf("%d ",v[i]);
  }
  printf("\n");
  return 0;
}
