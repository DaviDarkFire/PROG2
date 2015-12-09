#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int n;
    int *data;
    int capacidade;

}MySet;

void sort(int *a, int *b){
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

MySet *create(int n){
    MySet *s = malloc(sizeof(MySet));
    s->data = malloc(n * sizeof(int));
    s->n = 0;
    s->capacidade = n;
    return s;
}

void destroy(MySet *s){
    free(s->data);
    free(s);
}

void add(MySet *s, int el){
    s->data[s->n] = el;
    s->n++;
}
void print(MySet *s){
    printf("Número de elementos: %d\n", s->n);
    printf("Capacidade de elementos: %d\n", s->capacidade);
    for(int i = 0; i < s->n; i++){
      printf("%d ", s->data[i]);
    }
    printf("\n");
}

int partition (MySet *s, int p, int r){
    int x = s->data[p]; int i = p-1; int q = r+1;
    while (1) {
      do { q--; } while (s->data[q] > x);
      do { i++; } while (s->data[i] < x);
      if(i < q) {
        sort(&s->data[i], &s->data[q]);
      }
    else return q;
  }
}

void quickSort(MySet *s, int p, int r){
    if (p < r){
      int q = partition (s, p, r);
      quickSort(s, p, q);
      quickSort(s, q+1, r);
    }
}

//ESTUDAR BUSCA BINÁRIA
int buscaBinaria(MySet *s, int inicio, int fim, int el){

    if(fim < inicio) return -1; //condição de parada pra se não encontrou elementos

    if(inicio == fim-1) return fim; //condição de parada pra se encontrou elementos
    else{
      int meio = (inicio+fim)/2; // a partir daqui vc ja sabe como funfa
      if(el > s->data[meio]) return buscaBinaria(s, meio, fim, el);
      else return buscaBinaria(s, inicio, meio, el);
    }
}
int temSoma(MySet *s, int x){
    int res;
    for(int i = 0; i < s->n; i++){
      res = buscaBinaria(s, 0, s->n, x-(s->data[i]));
      if(i == res) res = -1; // essa linha faz com que se a posição somada for a mesma ela não valha
    }
    if (res == -1) return 0;
    else return 1;
}

int main(void){
    int n, x, aux;
    scanf("%d", &n);
    srand(time(NULL));
    MySet *s =  create(n);

    for(int i = 0; i < n; i++){
      //add(s, rand()%(n+1));
      scanf("%d", &aux);
      add(s, aux);
    }
    scanf("%d", &x);
    print(s);
    quickSort(s, 0, s->n-1);
    print(s);

    if(temSoma(s, x)) printf("S\n");
    else printf("N\n");
    destroy(s);

  return 0;
}
