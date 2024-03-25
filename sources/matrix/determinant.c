#include <minirt.h>

float determinant(t_matrix *A)
{
    int     i;
    float   result;

    if (A->dimension == 2)
    {
        return A->values[0][0] * A->values[1][1]
            -  A->values[0][1] * A->values[1][0];
    }
    i = 0;
    result = 0;
    while (i < A->dimension)
    {
        result += A->values[0][i] * cofactor(A, 0, i);
        i++;
    }
    return result;
}
