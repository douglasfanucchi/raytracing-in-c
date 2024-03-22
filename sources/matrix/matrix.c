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
