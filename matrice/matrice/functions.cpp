#include "stdafx.h"
#include "functions.h"


void thread_test();

void matrix_copy(int **o, int **n) {


	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 9; j++) {

			o[i][j] = n[i][j];
			//printf("%d\t", m[i][j]);

		}
		//printf(" \n");
	}

}


void matrix_tripple() {


	int ***matx = 0;
	matx = (int ***)malloc(9 * sizeof(int*));
	for (int i = 0; i < 9; i++) {

		matx[i] = (int **)malloc(9 * sizeof(int));
		if (matx[i] == NULL) {
			fprintf(stderr, "Out of memory");
			exit(0);
		}

		for (int j= 0; j < 9; j++) {
		
			matx[i][j] = (int *)malloc(9 * sizeof(int));
			if (matx[i][j] == NULL) {
				fprintf(stderr, "Out of memory");
				exit(0);
			}
		}



	}
	for (int i = 0; i < 9; i++) {


		for (int j = 0; j < 9; j++) {
			free(matx[i][j]);
		}
		free(matx[i]);
	}
	free(matx);

}

void insert_matrix(int **m) {

	int g[9][9] = {
		0,0,3,
		0,0,0,
		4,2,0,

		6,0,0,
		5,0,0,
		8,0,0,

		0,1,0,2,0,4,0,0,9,0,6,0,0,1,0,0,7,4,2,0,1,0,3,0,5,0,8,4,8,0,0,2,0,0,9,0,5,0,0,3,0,1,0,8,0,0,0,4,0,0,7,0,0,1,0,3,6,0,0,0,7,0,0 };
	//{2, 0, 9, 6, 4, 8, 0, 0, 0,
	//	3, 0, 8, 2, 9, 0, 0, 1, 0,
	//	0, 6, 0, 0, 0, 0, 8, 0, 9,
	//	0, 0, 0, 3, 0, 4, 7, 0, 0, 0, 9, 0, 0, 6, 0, 0, 5, 0, 0, 0, 5, 8, 0, 9, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 3, 0, 0, 8, 0, 0, 2, 1, 6, 0, 7, 0, 0, 0, 4, 3, 5, 1, 0, 2};
	int k = 2;
	for (int i = 0; i < 9; i++) {

		for (int j = 0; j < 9; j++) {

			m[i][j] = g[i][j];
			//printf("%d\t", m[i][j]);

		}
		//printf(" \n");
	}


}

int check_horz(int  **m) {
	int g = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {

			if (m[i][j] == 0) {
				printf("I : %d J : %d \n", i, j);
				for (int b = 1; b <= 9; b++) {
				
					test_h(m, i, j, b);
					if (m[i][j] != 0) {
						g = check_horz(m);
						if (g == 1) {
							m[i][j] = 0;

						}
					}
				}
				if (m[i][j] == 0) {
					//	printf("problem,ne moze ovaj broj tu \n");
					return 1;
				}
			}



		}

	}
	return 0;
}
void test_h(int **m, int x, int y, int b) {
	int br = 0;
	for (int i = 0; i < 9; i++) {

		if (m[x][i] == b) {
			//	printf("ne moze \\\\\\\\\ %d\n", b);
			break;
		}
		else {

			//	printf("moze %d\n",b);
			br++;
		}


	}

	if (br == 9) {
		//	m[x][y] = b; 
		//	printf("treba testirati vertikalno \n");
		test_v(m, x, y, b);
	}


}
void test_v(int **m, int x, int y, int b) {

	int br = 0;
	for (int i = 0; i < 9; i++) {

		if (m[i][y] == b) {
			//	printf("ne moze \\\\\\\\\ %d\n", b);
			break;
		}
		else {

			//	printf("moze %d\n", b);
			br++;
		}


	}

	if (br == 9) {


		box_test(m, x, y, b);

	}


}
int box_test(int **m, int x, int y, int b) {
	int i;
	int j;
	int br = 0;
	switch (x) {
	case 0:
	case 1:
	case 2:
		i = 0;
		break;
	case 3:
	case 4:
	case 5:
		i = 3;
		break;
	case 6:
	case 7:
	case 8:
		i = 6;
		break;

	default:
		printf("something aint right\n");
		break;
	}
	switch (y) {

	case 0:
	case 1:
	case 2:
		j = 0;
		break;
	case 3:
	case 4:
	case 5:
		j = 3;
		break;
	case 6:
	case 7:
	case 8:
		j = 6;
		break;

	default:
		printf("something aint right\n");
		break;
	}
	int g = i;
	int t = j;

	for (g = i; g < i + 3; g++) {

		for (t = j; t < j + 3; t++) {
			//	printf("%d\t", m[g][t]);
			if (m[g][t] == b) {

				return 0;


			}
			else {
				br++;
			}
		}
		//	printf("\n");
	}

	if (br == 9) {

		m[x][y] = b;
		for (int i = 0; i < 9; i++) {

			for (int j = 0; j < 9; j++) {


				//		printf("%d\t", m[i][j]);

			}
			//	printf(" \n");
		}
		//	printf(" \n");
		//	printf(" \n");

	}



	return 0;
}