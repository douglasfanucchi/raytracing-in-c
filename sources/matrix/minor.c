#include <minirt.h>

float minor(t_matrix *A, int row, int column)
{
    t_matrix *sub;
    float    result;

    sub = submatrix(A, row, column);
    result = determinant(sub);
    free(sub->values);
    free(sub);
    return result;
}
