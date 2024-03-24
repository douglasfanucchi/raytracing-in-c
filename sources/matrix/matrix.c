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

t_matrix *matricesmultiply(t_matrix *A, t_matrix *B)
{
    t_matrix *result;
    int      i;
    int      j;
    int      dimension;

    dimension = A->dimension;
    result = new_matrix(dimension);
    i = 0;
    while (i < dimension)
    {
        j = 0;
        while (j < dimension)
        {
            result->values[i][j] = A->values[i][0] * B->values[0][j]; 
            result->values[i][j] += A->values[i][1] * B->values[1][j]; 
            result->values[i][j] += A->values[i][2] * B->values[2][j]; 
            result->values[i][j] += A->values[i][3] * B->values[3][j]; 
            j++;
        }
        i++;
    }
    return result;
}
