#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "matrix.h"
#include <stdlib.h>

void allocate_matrix(TMatrix** matrix, int n)
{
    (*matrix) = (TMatrix*)malloc(sizeof(TMatrix) * 1);
    (*matrix)->n = n;
    (*matrix)->x = (float*)malloc(sizeof(float) * n * n);
}

void fill_matrix(TMatrix* matrix)
{
    
    for (int i = 0; i < matrix->n; i++)
    {
        for (int j = 0; j < matrix->n; j++)
        {
            scanf("%f", &(matrix->x[i * matrix->n + j]));
        }
        printf("\n");
    }
}

void print_matrix(TMatrix* matrix)
{
    int i = 0;
    for (; i < matrix->n; i++)
    {
        int j = 0;
        for (; j < matrix->n; j++) {

            printf("%.3f ", matrix->x[i * matrix->n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_matrix(TMatrix** matrix)
{
    free((*matrix)->x);
    free(*matrix);
}

TMatrix* add_matrix(TMatrix* matrix1, TMatrix* matrix2)
{
    TMatrix* res;
    int i = 0;
    if (matrix1->n != matrix2->n)
    {
        printf("ERROR: Matrix should have the same lenght.\n");
        return NULL;
    }
    allocate_matrix(&res, matrix1->n);
    for (; i < res->n * res->n; i++)
    {
        res->x[i] = matrix1->x[i] + matrix2->x[i];
    }
    return res;
}

TMatrix* add_const(TMatrix* matrix, float c)
{
    TMatrix* res;
    
    allocate_matrix(&res, matrix->n);
    for (int i = 0; i < res->n * res->n; i++)
    {
        res->x[i] = matrix->x[i] + c;
    }
    return res;
}


TMatrix* multi_matrix(TMatrix* matrix1, TMatrix* matrix2)
{
    TMatrix* res;
    allocate_matrix(&res, matrix1->n);
   
    for (int i = 0; i < matrix1->n; i++)
    {
        
        for (int j = 0; j < matrix1->n; j++)
        {
            res->x[i * matrix1->n + j] = 0;
            
            for (int k = 0; k < matrix1->n; k++)
            {
                res->x[i * matrix1->n + j] += matrix1->x[i * matrix1->n + k] * matrix2->x[k * matrix2->n + j];
            }
        }
    }
    return res;
}

TMatrix* multi_const(TMatrix* matrix, float c)
{
    TMatrix* res;
    int i = 0;
    allocate_matrix(&res, matrix->n);
    for (; i < res->n * res->n; i++)
    {
        res->x[i] = matrix->x[i] * c;
    }
    return res;
}