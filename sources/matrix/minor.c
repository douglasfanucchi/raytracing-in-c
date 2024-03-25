#include <minirt.h>

float minor(t_matrix *A, int row, int column)
{
    t_matrix *sub;

    sub = submatrix(A, row, column);
    free(A->values);
    free(A);
    return determinant(sub);
}
