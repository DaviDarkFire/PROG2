#include <stdio.h>
#include <stdbool.h>
#include "Vector.h"


int main(void){
  
	 tVector *V = create(20);

	add (V, 100);
	add (V, 90);
	add (V, 80);
	add (V, 70);
	add (V, 60);
	add (V, 50);
	add (V, 40);
	add (V, 30);
	add (V, 20);
	add (V, 10);
	

	print(V);
	
	bubbleSortRec(V);
	
	print(V);
  
  
  
  
  return 0;
}
