#include <stdlib.h>
#include <stdio.h>
#include "matrixFun.h"

int main(int argc, char **argv){
	intMatrix* m1 = (intMatrix*) malloc(sizeof(intMatrix));
	m1->line = 3;
	m1->col = 1;
	m1->mat = (int**) malloc(3 * sizeof(int*));
	for(int i=0; i<3; i++){
		m1->mat[i] = (int*) malloc(m1->col * sizeof(int));
	}
	m1->mat[0][0] = 1;
	m1->mat[1][0] = 3;
	m1->mat[2][0] = 5;
	printMatrix(m1);

	intMatrix* m2 = transpose(m1);
	printMatrix(m2);

	int ans = dotProduct(m1, m2);
	printf("dot product : %d\n", ans);

	freeMatrix(m2);
	freeMatrix(m1);

	return 0;
}