#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int *data;
    int n;
    int capacity;
}MySet;

void add(MySet *s, int x){
    s->data[s->n] = x;
    (s->n)++;
    
}

MySet *create(int n){
    MySet *newSet = malloc(sizeof(MySet));
    newSet->data = malloc(n * sizeof(int));

    newSet->n = 0;
    newSet->capacity = n;
    return newSet;
}

void destroy(MySet *s){
    free(s->data);
    free(s);
}

int binarySearch(MySet *s, int left, int right, int x){
    int middle = (left+right)/2;
    if(left > right) return -1;
    if(s->data[middle] == x) return middle;
    if(s->data[middle] < x) return binarySearch(s, middle+1, right, x);
    else return binarySearch(s, left, middle-1, x);

}
void merge(MySet *s, int inicio, int meio, int fim){
    int i, j, k = 0;
    
    i = inicio;
    j = meio;

    int *w = malloc((fim-inicio) * sizeof(int));

    while(i < meio && j < fim){
        if(s->data[i] < s->data[j]) w[k++] = s->data[i++];
        else w[k++] = s->data[j++];    
    }

    while(i < meio) w[k++] = s->data[i++];
    while(j < fim) w[k++] = s->data[j++];

    for(int cont = inicio; cont < fim; cont++){
        s->data[cont] = w[cont-inicio];
    }
    
}
void mergeSort(MySet *s, int inicio, int fim){
    if(inicio < fim-1){
        int meio = (inicio+fim)/2;
        mergeSort(s, inicio, meio);
        mergeSort(s, meio, fim);
        merge(s, inicio, meio, fim);
        
    }
    
}
int existsSum(MySet *s, int x){
    int res;
    for(int i = 0; i < s->n; i++){
      res = binarySearch(s, 0, s->n, x-(s->data[i]));
    }
    if(res == -1) return 0;
    else return 1;

}

void print(MySet *s){
    printf("Número de Elementos: %d\n", s->n);
    for(int i = 0; i < s->n; i++){        
        printf("%d ", s->data[i]);
    }
    printf("\n");
    
}

int main(void){

    int n;
    scanf("%d", &n);
    MySet *s = create(n);
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        add(s, rand()%(n+1));
    }
    print(s);
    mergeSort(s, 0, n);
    print(s);
    if(existsSum(s, 0)) printf("SIM\n");
    else printf("NÂO\n");
    
    

    return 0;
}
