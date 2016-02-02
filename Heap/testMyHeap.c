#include "MyHeap.h"

int main ()
{
	/*MyHeap* heap;
	heap = create (100); // cria um heap com 100 elementos

	tElement el;

	el.priority = 8;
	add(heap,el);
	print (heap);

	el.priority = 9;
	add(heap,el);
	print (heap);

	el.priority = 10;
	add(heap,el);
	print (heap);

	el.priority = 6;
	add(heap,el);
	print (heap);

	el.priority = 5;
	add(heap,el);
	print (heap);

	el.priority = 50;
	add(heap,el);
	print (heap);

	el.priority = 35;
	add(heap,el);
	print (heap);

	el.priority = 15;
	add(heap,el);
	print (heap);


	el = remove_max(heap);
	printf("\nElemento de maior prioridade removido %d",el.priority);
	print (heap);

	el = remove_max(heap);
	printf("\nElemento de maior prioridade removido %d",el.priority);
	print (heap);

	update (heap, 5, 80);
	print (heap);
	update (heap, 2, 0);
	print (heap);

	destroy(heap);*/

	// teste da função build
	MyHeap *newHeap = create(10);

	newHeap->S[0].priority = 30;
	newHeap->S[1].priority = 5;
	newHeap->S[2].priority = 30;
	newHeap->S[3].priority = 129;
	newHeap->S[4].priority = 70;
	newHeap->S[5].priority = 1;
	newHeap->S[6].priority = 87;
	newHeap->S[7].priority = 3;
	newHeap->S[8].priority = 34;
	newHeap->S[9].priority = 4;

	newHeap->numberOfElements = 10;
	print (newHeap);
	heap_sort(newHeap);
	print (newHeap);


	return 0;
}
