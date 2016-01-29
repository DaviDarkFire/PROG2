#include <stdio.h>
#include <stdlib.h>

int main(void){
	 srand(time(NULL));
	 int n;
	 scanf("%d", &n);
	 int field[n][n];
	 int x = rand()%n;
	 for(int i = 0; i < n; i++, x++)
		for(int j = 0; j < n; j++, x+=n)
			for(int k = 0; k < n; k++, x++)
				field[n*i+j][k] = (x % (n*n)) + 1;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d ", field[i][j]);

		}
		printf("\n");
	}


	return 0;
}
