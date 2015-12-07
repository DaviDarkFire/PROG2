#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "Vector.h"

int main(void)
{
	int n;
	scanf("%d", &n);

	srand(time(NULL));
	
	tVector *V = create(n);

	for (int i = 0; i < n; i++)
	{
		add (V, rand()%(n+1));
	}

	print(V);


	mergeSort(V, 0, n);
	print(V);
	destroy(V);
	
	
	return 0;
}
