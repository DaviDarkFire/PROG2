// Vector.h

#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
  int capacity;
  int numberOfElements;
  int *data;
    
}tVector;

// funcionalidades de um tVector

tVector *create (int); // aloca memória para um um tVector
void add (tVector*, int ); // inserção no final do vetor
void addFirst (tVector*, int); // inservao no inicio do vetor
int removeFirst (tVector*); // remove o primeiro elemento do vetor
int removeLast (tVector*); // remove o ultimo elemento do vetor
int removeElement (tVector*, int);//remove um elemento especifico do vetor
int sequentialSearch (tVector*, int); //busca um elemento no vetor 
int recursiveSearch (tVector*, int); // busca recursivamente um elemento  no vetor
int binarySearch (tVector*, int, int, int);
void print(tVector*); // imprime os elementos do vetor
bool isEmpty (tVector*);// retorna true se o vetor é vazio e false caso contrario
