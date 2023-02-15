#ifndef _MATRIX_H
#define _MATRIX_H
typedef struct
{
	float* x;
	int n;
} TMatrix;

void allocate_matrix(TMatrix** matrix, int n);
void free_matrix(TMatrix** matrix);

void fill_matrix(TMatrix* matrix);
void print_matrix(TMatrix* matrix);

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2);
TMatrix* add_const(TMatrix* matrix, float c);

TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2);
TMatrix* multi_const(TMatrix* matrix, float c);
#endif _MATRIX_H
