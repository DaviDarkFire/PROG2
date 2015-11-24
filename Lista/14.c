#include <stdio.h>
#include <stdlib.h>

int binarySearch (int *V, int lft, int rgt, int x){
	int m; 
	m = (lft + rgt) / 2;

	if (lft == rgt-1){
		return rgt;
	}	

	if (x > V[m]){
		return binarySearch (V,m,rgt,x);
	}	

	return binarySearch (V,lft,m,x);
}

int main(void){
	
	int n, x;


	
	n = 10;

	// scanf("%d", &x);
	
	int *V = malloc(n * sizeof(int));
	

	for (int i=0; i<n; i++){
		V[i] = i;
	}	

	 for (int i=0; i<n; i++){
	 	printf("%d ", V[i]);
	 }


	printf("\n");
	printf("%d\n", binarySearch(V, -1, n, 0));







	return 0;
}