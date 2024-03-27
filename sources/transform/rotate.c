#include <minirt.h>

t_matrix    *rotatex(float angle)
{
    t_matrix    *result;

    result = new_identity();

    result->values[1][1] = cos(angle);
    result->values[1][2] = -sin(angle);
    result->values[2][1] = sin(angle);
    result->values[2][2] = cos(angle);

    return result;
}

t_matrix *rotatey(float angle)
{
    t_matrix    *result;

    result = new_identity();
    result->values[0][0] = cos(angle);
    result->values[0][2] = sin(angle);
    result->values[2][0] = -sin(angle);
    result->values[2][2] = cos(angle);
    return result;
}