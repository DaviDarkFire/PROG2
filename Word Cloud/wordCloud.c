#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "HashTable.h"
#define CAPACITY 26

int main(void){

	FILE* dontCare = fopen("palavrasDontCare.in","r");
	HashTable* hashDontCare = createHashTable(CAPACITY);
	char* teste = malloc(46*sizeof(char*));

	/*while (fscanf(dontCare, "%s", teste) != EOF) {		
		Node* node = createNode(teste);
		put (hashDontCare, node);				
	}
	printHashTable(hashDontCare);*/
	
	for(int i = 0; i < 100; i++){
		fscanf(dontCare, "%s", teste);				
		Node* node = createNode(teste);
		put (hashDontCare, node);		
	}
	printHashTable(hashDontCare);
	//destroyHash(hashDontCare);
					
	/*scanf("%s", teste);
		
	Node* no = createNode(teste);	
	
	addSorted(list, no);


	scanf("%s", teste);

	Node* no1 = createNode(teste);
	addSorted(list, no1);

	scanf("%s", teste);

	Node* no2 = createNode(teste);
	addSorted(list, no2);

	scanf("%s", teste);

	Node* no3 = createNode(teste);
	addSorted(list, no3);
			
	printList(list);
	
	scanf("%s", teste);
	
	
	printf("Search List:\n");
	
	printNode(searchList(list,teste));*/
		

	return 0;
}
