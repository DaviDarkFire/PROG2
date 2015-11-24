#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"


// alocação de memória para um tVector; recebe como parâmetro a quantidade maxima de elementos do vetor;
tVector* create (int capacity)
{
	tVector *newVector = malloc (sizeof(tVector));
	if (!newVector)
	{
		printf("\nMemory allocation problem. Exiting.");	
		exit(1);
	}
  
	// alocação de memória para armazenamento dos elementos 
	newVector->data = malloc (capacity * sizeof(int));   
	if (! (newVector->data))
	{
		printf("\nMemory allocation problem. Exiting.");	
		exit(1);
	}

	newVector->capacity = capacity;
	newVector->numberOfElements = 0;
	return newVector;
}

// inserção do elemento passado como parâmetro no final do vetor
// Complexidade: O(1), pois permite inserção de elementos repetidos. 
void add (tVector* V, int el)
{

	if (V->numberOfElements == V->capacity)
	{
		printf("\nOverflow. We could not add the value %d.", el);
		return;
	}

	V->data[V->numberOfElements] = el;
	(V->numberOfElements)++;
}


// inserção do elemento passado como parâmetro no inicio do vetor
// Complexidade: O(n), pois precisa rearranjar os elementos antes de inserir o novo elemento na posicao 0
// Permite inserção de valores repetidos
void addFirst (tVector* V, int el)
{
	int i;
	if (V->numberOfElements == V->capacity)
	{
		printf("\nOverflow. We could not add the value %d.", el);
		return;
	}


	for (i=1; i<V->numberOfElements; i++)
		V[i] = V[i-1];

	V->data[0] = el;
	(V->numberOfElements)++;
}

// realiza a inserção do elemento el passado como parâmetro no início do vetor V ordenado
// permite inserção de elementos repetidos
// o elemento el deve ser inserido na sua posição correta, considerando que o vetor
// está ordenado
// Complexidade: O(n), pois a busca binária custa O(log n) e o trecho de código seguinte (for) tem custo O(n).  
// O(logn)+ O(n)  = O(n)
void addSorted (tVector* V, int el)
{

	int i;
	if (V->numberOfElements == V->capacity)
	{
		printf("\nOverflow. We could not add the value %d.", el);
		return;
	}
		
	int pos = binarySearchIt (V, el); // O(log_2 n)
	// addAtPosition(V,pos)

	// O(n)
	for (i=pos+1; i<V->numberOfElements; i++)
		V[i] = V[i-1];

	// O(1)
	V->data[pos] = el;
	(V->numberOfElements)++;
}


// verifica se o elemento el já pertence ou não ao conjunto de elementos armazenados em V
// se el não está no conjunto, realiza a inserção de el no final de V
// retorna, caso contrário. 
// Não permite duplicatas
// O(n)
void addWithoutDuplicates (tVector* V, int el)
{
	// O(n)
	int pos = sequentialSearch (V, el);

	// O(1)
	if (pos == -1) add (V,el);
}

// remoção do último elemento do vetor
// Complexidade: O(1)
// A funcao removeElementAtPosition tem complexidade O(n) no pior caso, porém quando o elemento a ser removido está na ultima posicao (numberOfElements-1), a complexidade da função se torna constante
int removeLast (tVector* V)
{
	return removeElementAtPosition (V,(V->numberOfElements)-1);
}

// remoção do primeiro elemento do vetor
// Complexidade: O(n), pois essa é uma situacao de pior caso
// da funcao removeElementAtPosition
int removeFirst (tVector* V)
{
	return removeElementAtPosition (V,0);
}

// remoção de um elemento específico (el) passado como parâmetro
// Se houver duplicatas, a função remove apenas a primeira ocorrência do elemento no vetor
// Complexidade: O(n)
void removeElement (tVector* V, int el)
{
	int pos;
	// O(n)
	if ((pos=sequentialSearch (V,el)) == -1)
	{
		printf("\nThe element %d is not in the array. Returning.", el);
		return;
	}
	// O(n) (no pior caso)
	removeElementAtPosition (V,pos);
}


// remoção do elemento em uma posicao específica (pos)
// Complexidade: O(n), no pior caso (removao do primeiro elemento)
// e O(1), no melhor caso (remocao do ultimo elemento)
int removeElementAtPosition (tVector* V, int pos)
{
	int i;
	// O(1)
	if (isEmpty(V))
	{
		printf("\nEmpty array (removeLast was not performed)");
		return 0; // FIX: there is an inconsistency in this value 
	}

	int removed = V->data[pos];

	// O(n)	
	for (i=pos+1; i<(V->numberOfElements); i++)
	{
		V->data[i-1] = V->data[i];
	}

	// O(1)
	(V->numberOfElements)--;
	return removed;
}


// Imprime a capacidade, a quantidade de elementos e os elementos do vetor V
// Complexidade: O(n)
void print(tVector* V)
{
	int i;
	printf("\nCapacity: %d", V->capacity);
	printf("\nNumber of elements: %d\n", V->numberOfElements);

	for(i=0; i<V->numberOfElements;i++)
		printf ("%d ", V->data[i]);

	printf("\n");
}

// Libera memória alocada para o vetor V
void destroy(tVector *V)
{
	free (V->data);
	free (V);
}


// Retorna true quando o vetor V está vazio e false caso constrário
// Complexidade: O(1)
bool isEmpty(tVector *V)
{
	return V->numberOfElements == 0;
}


// Busca sequencial de um elemento passado como parâmetro
// Em caso de existirem duplicatas, o método retorna o índice da primeira ocorrência do valor procurado
// Complexidade: O(n)
int sequentialSearch (tVector*V, int el) 		
{
	int i;
	for (i=0; i<V->numberOfElements; i++)
		if (V->data[i] == el) return i;

	return -1;

}

// Busca sequencial recursiva de um elemento passado como parâmetro
// Em caso de existirem duplicatas, o método retorna o índice da primeira ocorrência do valor procurado
// Complexidade: O(n)
int recursiveSearch (tVector*V, int el, int pos) 	
{

	if (pos == V->numberOfElements) return -1; // não encontrou
	if (V->data[pos] == el) return pos;  // encontrou a primeira ocorrênica

	return recursiveSearch (V, el, pos+1);
}
int sequentialSearchRec (tVector* V, int el)
{
	return  recursiveSearch (V,el,0);

}



int binarySearch (tVector* V, int el)
{
	return binarySearchRec (V,el,0,V->numberOfElements-1);
}

// Busca binária recursiva de um elemento no vetor ordenado
// A busca é realizada sobre os elementos das posicoes left até right 
// Inicialmente, left=0 e right=indice do ultimo elemento
// A cada chamada recursiva, "dividimos" o vetor ao meio 
// Complexidade: O(log_2 n)
int binarySearchRec(tVector* V, int el, int left, int right)
{
  if(left > right) return -1;

  int mid = (left+right)/2;

  if(V->data[mid] == el) return mid;

  else if(V->data[mid] > el) return binarySearchRec(V, el, left, mid-1);

  else return binarySearchRec(V, el, mid+1, right);
}



// Realiza a busca binária de um elemento el no vetor V ordenado de maneira iterativa
// ATENCAO: devolve o indice k tal que V[k-1] < el <= V[k+1]
// Ou seja, retorna o indice do elemento el quando este elemento se encontra em V, 
// ou retorna o indice onde o elemento el deve ser inserido,
// quando o mesmo não se encontra em V
// O(log n)
int binarySearchIt (tVector* V, int el)
{

	int meio;
	int l = -1;
	int r = V->numberOfElements;

	while (l < r-1)
	{
		meio = (l+r)/2;
		if (V->data[meio] < el)  l = meio;

		else r = meio;
	}
	return r;
}


// Outra versão da busca binária iterativa, mais parecida com o algoritmo recursivo
// ATENCAO: devole o indice k tal que el == V[k] 
// ou retorna -1 quando não encontra o elemento 
// Complexidade: O(log n)
int binarySearchIt_other (tVector* V, int el)
{

	int meio;
	int l = 0;
	int r = V->numberOfElements-1;

	while (l <= r)
	{
		meio = (l+r)/2;
		if (V->data[meio] == el)  return meio;
		else if (V->data[meio] < el) l = meio+1;
		else r = meio-1;
	}
	return -1;

}

// Busca o maior elemento do vetor recursivamente
// Complexidade: O(n)
int max (tVector* V)
{
	return maxRec (V,0);
		

}

// Complexidade: O(n)
int maxRec (tVector*V, int k)
{
	if (k == V->numberOfElements-1) 
	 	return V->data[k];

	int max = maxRec (V, k+1);

	if (V->data[k] > max) return V->data[k]; 

	return max; 
		

}


// Busca o maior elemento do vetor recursivamente
// Vetor ordenado
// Complexidade: O(1)
int maxSorted (tVector* V)
{
	return V->data[V->numberOfElements-1];

}



// Complexidade: O(n)
int min (tVector* V)
{
	return minRec (V,0);

}

// Complexidade: O(n)
int minRec (tVector*V, int k)
{
	if (k == V->numberOfElements-1) 
	 	return V->data[k];

	int min = minRec (V, k+1);

	if (V->data[k] < min) return V->data[k]; 

	return min; 
		
}


// Complexidade: O(n)
// Vetor ordenado
// Retorna o menor elemento do vetor
int minSorted (tVector* V)
{
	return V->data[0];
}


void bubble_sort (tVector* V){
  int trocou = 1;
  int i, j, temp;
  for(i = V->numberOfElements-1; i > 0 && trocou == 1; i--){
    trocou = 0;
    for(j = 0; j < i; j++){
      if(V->data[j] > V->data[j+1]){
	temp = V->data[j];
	V->data[j] = V->data[j+1];
	V->data[j+1] = temp;
	trocou = 1;
      }	
      
    }
    
  }
}

void bubbleSortRec(tVector* V){
  bubbleSortRecursive(V, V->numberOfElements-1, 1);
}

void bubbleSortRecursive (tVector* V, int i, int trocou){
  int j, temp;
  
  if(trocou == 0) return;
  
  if (i == 0) return;
  
  trocou = 0;
  
  for(j = 0; j < i; j++){
    
    if(V->data[j] > V->data[j+1]){
	temp = V->data[j];
	V->data[j] = V->data[j+1];
	V->data[j+1] = temp;
	trocou = 1;
    }	
    
  }
  
  bubbleSortRecursive(V, i-1, trocou);
    
  
  
  
  
}





