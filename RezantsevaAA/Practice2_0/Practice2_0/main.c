#include "matrix.h"
#include <stdio.h>
int main()
{
	TMatrix* matrix_dynamic, *m1, *m2;
	allocate_matrix(&m1, 2);
	allocate_matrix(&m2, 2);
	fill_matrix(m1);
	fill_matrix(m2);

	print_matrix(m1);
	print_matrix(m2);

	free_matrix(&m1);
	free_matrix(&m1);
	return 0;
}