#include <minirt.h>

float cofactor(t_matrix *A, int row, int column)
{
    int signal;

    signal = 1;
    if ((row + column) % 2)
        signal = -1;
    return minor(A, row, column) * signal;
}