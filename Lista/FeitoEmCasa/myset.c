#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;
    int n;
    int capacity;
}MySet;

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



int existsSum(MySet *s, int x){
    int res;
    for(int i = 0; i < s->n; i++){
      res = binarySearch(s, 0, s->n, x-(s->data[i]));
    }
    if(res == -1) return 0;
    else return 1;

}

int main(void){


    return 0;
}
