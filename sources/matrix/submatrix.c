#include <minirt.h>

t_matrix *submatrix(t_matrix *A, int row, int column)
{
    t_matrix    *result;
    int         i;
    int         j;
    float       **values;

    result = new_matrix(A->dimension - 1);
    values = A->values;
    i = 0;
    while (i < result->dimension)
    {
        if (i == row)
            values++;
        j = 0;
        while (j < result->dimension)
        {
            if (j == column)
                values[i]++;
            result->values[i][j] = values[i][j];
            j++;
        }
        i++;
    }
    return result;
}
