#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
int main(void){
  tVector* V1 = create(10);
  add(V1, 1);
  add(V1, 11);
  add(V1, 21);
  add(V1, 1);
  add(V1, 31);
  add(V1, 87);
  int pos = binarySearch(V1,15,0, V1->numberOfElements-1);
  if(pos==-1)
    printf("Elemento 15 não pertence ao conjunto");
  else
    printf("Elemento 15 está na posição %d", pos);
  //print(V1);
  //removeLast(V1);
  //removeLast(V1);
  printf(V1);
  destroy(V1);
  
  
  
  
  return 0;
}