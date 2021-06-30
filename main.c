#include <stdlib.h>
#include <stdio.h>
#include "matrixFun.h"

int main(int argc, char **argv){
	intMatrix* m1 = (intMatrix*) malloc(sizeof(intMatrix));
	m1->line = 3;
	m1->col = 2;
	m1->mat = (int**) malloc(3 * sizeof(int*));
	for(int i=0; i<3; i++){
		m1->mat[i] = (int*) malloc(2 * sizeof(int));
	}
	m1->mat[0][0] = 1;
	m1->mat[0][1] = 2;
	m1->mat[1][0] = 3;
	m1->mat[1][1] = 4;
	m1->mat[2][0] = 5;
	m1->mat[2][1] = 6;
	printMatrix(m1);

	intMatrix* m2 = transpose(m1);
	printMatrix(m2);

	intMatrix* m3 = matrixProduct(m2, m1);
	printMatrix(m3);


	freeMatrix(m2);
	freeMatrix(m1);
	freeMatrix(m3);


	return 0;
}