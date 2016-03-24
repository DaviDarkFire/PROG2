#include "MyHeap.h"

/************************************************************************
Função de Tratamento de exceção
*************************************************************************/
void exception(int exceptionError)
{

	switch(exceptionError)
	{
		case ALLOC_ERROR:
				printf("\nALLOC ERROR");
				exit(1);
		case OVERFLOW_WARNING:
				printf("\nOVERFLOW WARNING" );
				break;
		case UNDERFLOW_WARNING:
				printf("\nUNDERFLOW WARNING");
				break;
		case DELETE_WARNING:
				printf("\nDELETE WARNING");
				break;
		default:
				printf("\nUNKNOWN ERROR");
				exit(1);
	}
}

/************************************************************************
Função para criação do heap
*************************************************************************/
MyHeap* create (int capacity)
{
	MyHeap *heap = (MyHeap*) malloc (1*sizeof(MyHeap));
	if (heap == NULL) exception (ALLOC_ERROR);

	heap->S = (tElement *) malloc (capacity*sizeof (tElement));
	if (heap->S == NULL) exception (ALLOC_ERROR);

	heap->numberOfElements = 0;
	heap->capacity = capacity;

	return heap;
}


/************************************************************************
Função para liberar memória alocada previamento para o heap
*************************************************************************/
void destroy (MyHeap* heap)
{
	if (heap->S != NULL) free(heap->S);
	if (heap!=NULL) free(heap);
}

/************************************************************************
Função de impressão do heap
*************************************************************************/
void print (MyHeap* heap)
{
	int i;
	printf("\nO conjunto possui %d elementos\n",heap->numberOfElements);
	printf ("\nElementos:");
	for (i=0; i<heap->numberOfElements; i++)
		printElement (heap->S[i]);

}


/************************************************************************
Função de impressão de um elemento do heap
*************************************************************************/
void printElement (tElement s)
{
	printf ("%d ",s.priority);
	// aqui teriamos o printf dos outros campos

}


/************************************************************************
Função para retornar o indice do pai do elemento de indice i do heap
*************************************************************************/
int dad (int i)
{
	if (i==0) return 0;
	return (i-1)/2;
}
/************************************************************************
Função para retornar o indice do filho esquerdo do elemento de indice i
*************************************************************************/
int left (int i)
{
	return 2*i + 1;
}
/************************************************************************
Função para retornar o indice do filho direito do elemento de indice i
*************************************************************************/
int right (int i)
{
	return 2*i + 2;
}
/************************************************************************
Função para descer o elemento de indice i até sua posição correta com
relação aos seus descendentes
*************************************************************************/
void down (MyHeap* heap, int i)
{
			if(i >= heap->numberOfElements)
				return;

			int maior = max(heap, i);

			if(i != maior){
				exchange (heap, i, maior);
				down (heap, maior);
				return;
			}
}

/************************************************************************
Função para subir o elemento de indice i até sua posição correta com
relação aos seus ascendentes
*************************************************************************/
void up (MyHeap* heap, int i)
{
	int k;
	if (i<(heap->numberOfElements))
	{
		k = dad(i);
		if (i==k) return; // chegou na raiz

		if ((heap->S[i]).priority > (heap->S[k]).priority)
		{
			exchange (heap,i,k);
			up (heap,k);
		}
	}
	return;
}

/************************************************************************
Função para trocar a posição de dois elementos do heap
*************************************************************************/
void exchange (MyHeap* heap, int i, int k)
{
	tElement temp = heap->S[i];
	heap->S[i] = heap->S[k];
	heap->S[k] = temp;

}

/************************************************************************
Função que retorna o indice do maior elemento entre o elemento de indice i
e seus dois filhos
*************************************************************************/
int max (MyHeap* heap, int i)
{

	int j = left (i); // filho esquerdo de i
	int k = right (i); // filho direito de i

	int temp_maior = i; // supondo que o maior é o elemento com indice i

 	// se k é um indice valido e a prioridade do elemento de indice k
        // for maior que a prioridade do elemento de indice temp_maior,
	// atualiza temp_maior
	if ((k<heap->numberOfElements) && (heap->S[k].priority > heap->S[temp_maior].priority))
		temp_maior = k;
	// se j é um indice valido e a prioridade do elemento de indice j
        // for maior que a prioridade do elemento de indice temp_maior,
	// atualiza temp_maior
	if ((j<heap->numberOfElements) && (heap->S[j].priority > heap->S[temp_maior].priority))
		temp_maior = j;

	return temp_maior;
}


/************************************************************************
Função para inserir um novo elemento no Heap com garantia de manutenção da
propriedade de ordem dos elementos do heap após a inserção
*************************************************************************/
void add (MyHeap* heap, tElement el)
{
	if (heap->numberOfElements == heap->capacity) exception (OVERFLOW_WARNING);
	else
	{
		heap->S[heap->numberOfElements] = el;
		heap->numberOfElements = heap->numberOfElements + 1;
		up(heap,heap->numberOfElements-1);
	}

}

/************************************************************************
Função para retornar o elemento de maior prioridade no Heap, garantindo
a manutenção da ordem entre os elementos após a remoção
*************************************************************************/
tElement remove_max (MyHeap* heap)
{
	if (heap->numberOfElements == 0) exception (UNDERFLOW_WARNING);
	else
	{
		tElement removed = heap->S[0];
		//corrigir o heap após a remoção
		heap->S[0] = heap->S[heap->numberOfElements-1];
		(heap->numberOfElements)--;
		down(heap, 0);
		return removed;

	}



}
/************************************************************************
Função atualizar a prioridade do elemento de indice i do heap, garantindo
a manutenção da ordem entre os elementos após a atualização
*************************************************************************/
void update (MyHeap* heap, int i, int p)
{
	int old_p = heap->S[i].priority;
	heap->S[i].priority = p;
	if(p > old_p)
		up(heap, i);
	else
		down(heap, i);


}

/************************************************************************
Função para construir um heap a partir de um conjunto de elementos que não
necessariamente possuem relação de ordem entre os elementos. Esse método
é baseado em uma sequencia de descidas (chamadas do método down).
*************************************************************************/
void build (MyHeap* heap)
{
	int i = dad (heap->numberOfElements-1); //recebe o pai do último elemento
	for(; i >= 0; i--){ //começa do pai direto das folhas
		down(heap, i); //tenta trocar

	}
}

void heap_sort(MyHeap *heap){
	int n;
	n = heap->numberOfElements; //recebe o número de elementos
	build(heap); //transforma a sequencia passada em heaps
	for(int i = n-1; i > 0; i--){ //for começando da última folha
		exchange(heap, 0, i); //troca essa última folha com a raíz de todo o heap,
		(heap->numberOfElements)--; //pois ele é o maior, logo a última posição ja está ordenada
		down(heap, 0); //trava a última pos. ja ordenada
		//chama a down pra posição zero pra arrumar o heap se for preciso, afinal
		//o único número que tem-se certeza de sua magnitude é a raíz
		//complexidade O(nlog)
	}
	heap->numberOfElements = n;
}
