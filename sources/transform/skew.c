#include <minirt.h>

t_matrix    *skew(float xy, float xz, float yx, float yz, float zx, float zy)
{
    t_matrix    *result;

    result = new_identity();
    result->values[0][1] = xy;
    result->values[0][2] = xz;
    result->values[1][0] = yx;
    result->values[1][2] = yz;
    result->values[2][0] = zx;
    result->values[2][1] = zy;
    return result;
}