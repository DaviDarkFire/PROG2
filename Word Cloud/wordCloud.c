#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "HashTable.h"

int main(void){

	FILE* dontCare = fopen("palavrasDontCare.in","r");
	char* teste = malloc(46*sizeof(char*));

	List* list = create();
	

	/*for(int i = 0; i < 10; i++){

		fscanf(dontCare, "%s\n", teste);
		Node* no = createNode(teste);
		addSorted(list, no);


	}*/

	scanf("%s", teste);

	printf("teste\n");
	
	Node* no = createNode(teste);	
	printf("teste1\n");
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


	








	return 0;
}
