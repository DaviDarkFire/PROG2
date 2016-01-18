#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int capacity;
	int *data;
	int n;

}MySet;

MySet *create(int capacit){
	MySet *newSet = malloc(capacit * sizeof(MySet));
	newSet->data = malloc(capacit * sizeof(int));

	newSet->capacity = capacit;
	newSet->n = 0;
	return newSet;
}

void print(MySet *s){
	printf("Capacity: %d\n", s->capacity);
	printf("Number of Elements%d\n", s->n);
	for(int i = 0; i < s->n; i++){
		printf("%d ", s->data[i]);
	}
	printf("\n");

}

void destroy(MySet *s){
	free(s->data);
	free(s);
}

int binarySearch(MySet *s, int left, int right, int el){
	int middle;
	if (left > right) return -1;
	middle = (left+right)/2;
	if(s->data[middle] == el) return middle;
	if(s->data[middle] < el) return binarySearch(s, middle+1, right, el);
	else return binarySearch(s, left, middle-1, el);
}

int main(void){
	int n;
	scanf("%d", &n);
	MySet *s;
	s = create(n);
	print(s);
	return 0;
}