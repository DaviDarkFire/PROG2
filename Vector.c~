#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>

bool isEmpty(tVector* V){
  return V->numberOfElements == 0;
}

tVector* create (int capacity) // aloca memória para um um tVector
{
          tVector *newVector = malloc (sizeof(tVector));
          if (!newVector) exit(1);

	 newVector->data = malloc (capacity * sizeof(int));   // "capacity" inteiros apontado por data
         if (! (newVector->data)) exit(1);

	newVector->capacity = capacity;
        newVector->numberOfElements = 0;

}

void add (tVector* V, int el) // inserção no final do vetor
{

         if (V->numberOfElements == V->capacity) 
         {
                        printf("overflow");
			return;
         }
 
        V->data[V->numberOfElements] = el;
	(V->numberOfElements)++;
}

int removeLast (tVector* V) // remove o ultimo elemento do vetor
{
	if (isEmpty(V)) return;

	int removed = V->data[V->numberOfElements-1];
        (V->numberOfElements)--;
        return removed;


}

void print(tVector* V) // imprime os elementos do vetor
{

	int i;
	printf("Capacity: %d", V->capacity);
        printf("Number of elements: %d", V->numberOfElements);

	for (i=0; i<V->numberOfElements;i++)
		printf ("%d ", V->data[i]);

}

void destroy (tVector *V)
{
	free (V->data);
	free (V);
}

int binarySearch (tVector* V, int el, int left, int right)
{
	if ((left == right)&&(V->data[left]!=el)) return -1;
	
	int middle = (left+right)/2;

	if (V->data[middle] == el) return middle;   // sucesso!

	else if (V->data[middle] > el) // procura à esquerda
		return binarySearch ( V, el, left, middle-1);

	else // procura a direita 
		return binarySearch (V, el, middle+1, right);
}

