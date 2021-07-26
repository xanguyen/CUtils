typedef struct{
	int line;
	int col;
	int** mat;
} intMatrix;

intMatrix* matrixProduct(intMatrix* m1, intMatrix* m2){
	if(m1->col != m2->line){
		printf("Wrong dimensions to do a matrixProduct\n");
		return NULL;
	}

	intMatrix* ans = (intMatrix*) malloc(sizeof(intMatrix));
	if(ans==NULL){printf("Malloc failed\n"); return NULL;}
	ans->line = m1->line;
	ans->col = m2->col;
	ans->mat = (int**) malloc(m1->line * sizeof(int*));
	if(ans->mat==NULL){printf("Malloc failed\n"); return NULL;}

	for(int i=0; i<m1->line; i++){
		ans->mat[i] = (int*) malloc(m2->col * sizeof(int));
	}

	for(int i=0; i<m1->line; i++){
		for(int j=0; j<m2->col; j++){
			for(int k=0; k<m1->col; k++){
				ans->mat[i][j] += m1->mat[i][k]*m2->mat[k][j];
			}
		}
	}

	return ans;
}

intMatrix* transpose(intMatrix* m){
	intMatrix* ans = (intMatrix*) malloc(sizeof(intMatrix));
	if(ans==NULL){printf("Malloc failed\n"); return NULL;}
	ans->line = m->col;
	ans->col = m->line;
	ans->mat = (int**) malloc(m->col * sizeof(int*));
	if(ans->mat==NULL){printf("Malloc failed\n"); return NULL;}
	for(int i=0; i<m->col ; i++){
		ans->mat[i] = (int*) malloc(m->line * sizeof(int));
	}
	for(int i=0; i<m->line; i++){
		for(int j=0; j<m->col; j++){
			ans->mat[j][i] = m->mat[i][j];
		}
	}
	return ans;
}

void printMatrix(intMatrix* m){
	printf("Matrix %dx%d\n", m->line, m->col);
	for(int i=0; i<m->line; i++){
		printf("( ");
		for(int j=0; j<m->col; j++){
			printf("%d ", m->mat[i][j]);
		}
		printf(")\n");
	}
	printf("\n");
}

void freeMatrix(intMatrix* m){
	for(int i=0; i<m->line; i++){
		free(m->mat[i]);
	}
	free(m->mat);
	free(m);
}

int dotProduct(intMatrix* m1, intMatrix* m2){
	int ans = 0;
	if(m1->col != 1 || m2->col != 1){
		printf("Error : vectors should be matrix of size nx1!\n");
		return -2147483648;
	}
	for(int i=0; i<m1->line; i++){
		ans += m1->mat[i][0] * m2->mat[i][0];
	}
	return ans;
}