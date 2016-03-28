#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "HashTable.h"
#define CAPACITY 26

int main(void){

	FILE* dontCare = fopen("palavrasDontCare.in","r");
	HashTable* hashDontCare = createHashTable(CAPACITY);
	char* dontCareWord = malloc(46*sizeof(char*));

	while (fscanf(dontCare, "%s", dontCareWord) != EOF) {				

		lowerCase(dontCareWord);	
		
		Node* node = createNode(dontCareWord);		
		
		put (hashDontCare, node);		

	}			
	printHashTable(hashDontCare);


	destroyHash(hashDontCare);
					
	
		

	return 0;
}
