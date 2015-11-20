#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, j;
    scanf("%d %d", &i, &j);
    int **M; 
    M = malloc( i * sizeof(int*) );
    for(int k = 0; k < i; k++ ){
        M[k] = malloc( j * sizeof(int) );
    }
    
    /*for(int k = 0; k < i; k++){
        for(int l = 0; l < j; l++){
            scanf("%d", &M[i][j]);
        
        
        
        }    
        
        
    }*/
    
    for(int k = 0; k < i; k++){
        for(int l = 0; l < j; l++){
            printf("Linha: %p Coluna: %p Valor: %d", (void*)i, (void*)j, M[i][j]);
        
        
        
        }    
        
        
    }
    
    
    
    
    return 0;
}