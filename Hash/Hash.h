#include <stdio.h>
#include "List.h"

typedef struct{
	int numberOfElements;
	int capacity;
	List** data;

}HashTable;

HashTable* createHashTable(int);
void put(HashTable*, Node*);
