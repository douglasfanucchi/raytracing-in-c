#include <minirt.h>

float determinant(t_matrix *A)
{
    return A->values[0][0] * A->values[1][1]
        -  A->values[0][1] * A->values[1][0];
}
