// matrice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"



int main()
{

	int mat[9][9] = {1,2,3,4,5,6,7,8,9,
	
					};
	int **matx=0;
	matx = (int **)malloc( 9 * sizeof(int*));
	if (matx == NULL) {
		fprintf(stderr, "Out of memory");
		exit(0);
	}
	for (int j = 0; j < 9; j++) {

	matx[j]= (int *)malloc(9 * sizeof(int));
		
	}
	clock_t t;
	t = clock();
	insert_matrix((int**)matx);
	check_horz((int**)matx);
	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 9; j++) {


			printf("%d\t", matx[i][j]);

		}
		printf(" \n");
	}
	for (int i = 0; i < 9; i++) {
		free(matx[i]);
	}
	free(matx);
	t = clock() - t;
	double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds 

	printf("fun() took %f seconds to execute \n", time_taken);
	
    return 0;
}

