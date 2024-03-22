#include <minirt.h>

t_matrix *new_matrix(int dimension)
{
    t_matrix *matrix;
    int i;

    i = 0;
    matrix = malloc(sizeof(t_matrix));
    matrix->dimension = dimension;
    matrix->values = malloc(sizeof(float*) * dimension);
    while (i < dimension)
    {
        matrix->values[i] = malloc(sizeof(float*) * dimension);
        i++;
    }
    return matrix;
}

char matrixcmp(t_matrix *A, t_matrix *B)
{
    int dimension;
    int i;
    int j;

    if (A->dimension != B->dimension)
        return 1;
    dimension = A->dimension;
    i = 0;
    while (i < dimension)
    {
        j = 0;
        while (j < dimension) {
            if (fabs(A->values[i][j] - B->values[i][j]) > EPSILON) {
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}
