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
    if( v[i] < v[j]) w[k++] = v[i++];
    else w[k++] = v[j++];
  }

  while(i < meio) w[k++] = v[i++];
  while(j < fim)  w[k++] = v[j++];

  for(int l = inicio; i < fim; i++){
    v[l] = w[l-inicio];
  }
  free(w);
}

void mergeSort(int v[MAX], int inicio, int fim){
  if(inicio < fim-1){
    int meio = (inicio+fim)/2;
    mergeSort(v, inicio, meio);
    mergeSort(v, meio, fim);
    merge(v, inicio, meio, fim);
  }
}

int partition(v[MAX], int inicio, int fim){
  int x = v[inicio];
  int i = inicio;
  int j = fim;
  i = i-1;
  j = j+1;
  do{i++}while(v[i] < x);
  do{j--}while(v[j] > x);
  if(i < j){
    sort(&v[i], &v[j]);

  }else{
    return j;
  }
}

void quickSort(int v[MAX], int inicio, int fim){
  if(inicio < fim){
    int p = partition(v, inicio, fim);
    quickSort(v, inicio, p);
    quikSort(v, p+1, fim);
  }

}

int buscaBinaria(int v[MAX], int inicio, int fim, int el){

  if(fim < inicio) return -1;
  if(inicio == fim-1) return fim;
  else{
    int meio = (inicio+fim)/2;
    if(v[meio] < el) return buscaBinaria(v, meio, fim, el);
    else return buscaBinaria(v, inicio, meio, el)
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
