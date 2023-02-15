#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

void allocate_matrix(TMatrix** matrix, int n)
{
	(*matrix) = (TMatrix*)malloc(sizeof(TMatrix)*1);
	(*matrix)->n = n;
	(*matrix)->x = (int*)malloc(sizeof(int) * n * n);

}

void fill_matrix(TMatrix* matrix)
{
	int i = 0,j;
	for (; i < matrix->n; i++)
	{
		for (j = 0; j< matrix->n; j++)
		{
			scanf("%.2f ", &(matrix->x[matrix->n * i + j]));
		}
	}
}

void print_matrix(TMatrix* matrix)
{
	int i = 0,j;

	for (; i < matrix->n; i++)
	{
		for (j = 0; j < matrix->n; j++)
		{
			printf("%.2f ", (matrix->x[matrix->n*i +j]));
		}
		
	}
	printf("\n");
}

void free_matrix(TMatrix** matrix)
{
	free((*matrix)->x);
	free(*matrix);
}
