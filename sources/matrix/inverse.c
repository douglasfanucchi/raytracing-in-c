#include <minirt.h>

char    is_invertible(t_matrix *A)
{
    return determinant(A) != 0;
}

t_matrix    *inverse(t_matrix *A)
{
    t_matrix    *result;
    int         i;
    int         j;
    float       det;

    if (!is_invertible(A))
        return ((void*)0);
    i = 0;
    det = determinant(A);
    result = new_matrix(A->dimension);
    while (i < A->dimension)
    {
        j = 0;
        while (j < A->dimension)
        {
            result->values[j][i] = cofactor(A, i, j) / det;
            j++;
        }
        i++;
    }
    return result;
}