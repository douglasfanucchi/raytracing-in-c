#include <minirt.h>

t_matrix    *translate(float x, float y, float z)
{
    t_matrix    *result;

    result = new_identity();
    result->values[0][3] = x;
    result->values[1][3] = y;
    result->values[2][3] = z;
    return (result);
}
