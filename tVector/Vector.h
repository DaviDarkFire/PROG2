// Vector.h

#include <stdbool.h>

typedef struct
{
  int capacity;					// capacidade máxima do vetor
  int numberOfElements;				// quantidade de elementos armazenados 
  int *data;					// elementos 

}tVector;

// funcionalidades de um tVector

tVector *create (int); 				// alocação de memória para um tVector; recebe como parâmetro a quantidade maxima de elementos do vetor;
void add (tVector*, int ); 			// inserção do elemento passado como parâmetro no final do vetor
void addFirst (tVector*, int);	 		// inserção do elemento passado como parâmetro no início do vetor
void addWithoutDuplicates (tVector*, int);
void addSorted (tVector*, int);
int removeFirst (tVector*); 			// remoção do primeiro elemento do vetor
int removeLast (tVector*); 			// remoção do último elemento do vetor
void removeElement (tVector*, int); 		// remoção de um elemento específico do vetor, passado como parâmetro
int removeElementAtPosition (tVector*, int); 	// remoção do elemento em uma posicao específica (pos)
int sequentialSearch (tVector*, int); 		// busca sequencial de um elemento passado como parâmetro
int sequentialSearchRec (tVector*, int); 		// busca sequencial de um elemento passado como parâmetro
int recursiveSearch (tVector*, int, int); 	// busca sequencial recursiva de um elemento passado como parâmetro
int binarySearch(tVector*, int); 	// busca binária recursiva de um elemento passado como parâmetro. 
int binarySearchRec(tVector*, int, int, int); 	// busca binária recursiva de um elemento passado como parâmetro. 
						// Parâmetros: ponteiro para o vetor, o elemento, indice esquerdo e indice direito da porção do vetor onde a busca será realizada
int binarySearchIt(tVector*, int); 		// busca binária iterativa com uma melhoria relativa ao retorno da função
int binarySearchIt_other(tVector* V, int el);   // busca binária iterativa equivalente ao algoritmo recursivo
void destroy(tVector *V); 			// liberação de toda memória alocada para armazenamento do vetor

void print(tVector*); 				// impressão os elementos do vetor
bool isEmpty (tVector*);			// retorna true se o vetor é vazio e false caso contrário

int max (tVector*);				// retorna o maior elemento do vetor
int maxRec (tVector*, int);			// retorna o maior elemento do vetor (recursivo)
int maxSorted (tVector*);			// retorna o maior elemento do vetor ordenado

int min (tVector*);				// retorna o menor elemento do vetor
int minRec (tVector*, int);			// retorna o menor elemento do vetor (recursivo)
int minSorted (tVector*);			// retorna o menor elemento do vetor ordenado
void bubble_sort (tVector*);		//ADVINHA, essa função ordena o vetor pelo método bubble sort
void bubbleSortRecursive (tVector*, int, int); //idem o de cima, só que agora é recursivo
void bubbleSortRec(tVector*);	 	//interface da bubble sort recursiva
void mergeSort (tVector*, int, int);//ordena um vetor recursivamente, utilizando divisão e conquista. Método de ordenação por intercalação.
void merge (tVector*, int, int, int);//realiza a intercalação de dois subvetores (partes de V) já ordenadas e devolve os elementos intercalados para o vetor original



