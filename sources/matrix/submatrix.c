#include <minirt.h>

t_matrix *submatrix(t_matrix *A, int row, int column)
{
    t_matrix    *result;
    int         i;
    int         j;
    float       **rows;
    float       *columns;

    result = new_matrix(A->dimension - 1);
    rows = A->values;
    i = 0;
    while (i < result->dimension)
    {
        if (i == row)
            rows++;
        columns = rows[i];
        j = 0;
        while (j < result->dimension)
        {
            if (j == column)
                columns++;
            result->values[i][j] = columns[j];
            j++;
        }
        i++;
    }
    return result;
}
