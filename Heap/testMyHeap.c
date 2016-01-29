#include "MyHeap.h"

int main ()
{
	MyHeap* heap;
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
	
	destroy(heap);
	

		return 0;
}
