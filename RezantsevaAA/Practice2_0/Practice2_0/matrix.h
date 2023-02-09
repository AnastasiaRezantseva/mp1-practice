#ifndef _MATRIX_H
#define _MATRIX_H
#define N 3
typedef struct
{
	float* x;
	int n;
}TMatrix;

void allocate_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);

void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);

#endif