#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void insert_matrix(int  **m);
int check_horz(int  **m);
void test_h(int **m, int x, int y, int b);
void test_v(int **m, int x, int y, int b);
int box_test(int **m, int x, int y, int b);