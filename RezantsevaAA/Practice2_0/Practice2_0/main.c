#include <stdio.h>
#include "matrix.h"
int main()
{
    TMatrix* matrix_dynamic, * m1, * m2, * res;
    /*
    allocate_matrix(&matrix_dynamic, 2);
    fill_matrix(matrix_dynamic);
    print_matrix(matrix_dynamic);
    free_matrix(&matrix_dynamic);
    */
    allocate_matrix(&m1, 2);
    allocate_matrix(&m2, 2);
   
    fill_matrix(m1);
    fill_matrix(m2);
   
    res = add_matrix(m1, m2);
    print_matrix(res);
    free_matrix(&res);
   
    res = add_const(m1, 2);
    print_matrix(res);
    free_matrix(&res);

    res = add_const(m2, 2);
    print_matrix(res);
    free_matrix(&res);
   
    res = multi_const(m1, 2);
    print_matrix(res);
    free_matrix(&res);

    res = multi_const(m2, 2);
    print_matrix(res);
    free_matrix(&res);
   
    res = multi_matrix(m1, m2);
    print_matrix(res);
    free_matrix(&res);

    free_matrix(&m1);
    free_matrix(&m2);
    return 0;
}
