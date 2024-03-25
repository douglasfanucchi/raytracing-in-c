#include <minirt.h>

char    is_invertible(t_matrix *A)
{
    return determinant(A) != 0;
}