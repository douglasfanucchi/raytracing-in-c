#include <minirt.h>

t_matrix    *scale(float x, float y, float z)
{
    t_matrix    *result;

    result = new_identity();
    result->values[0][0] = x;
    result->values[1][1] = y;
    result->values[2][2] = z;
    return (result);
}