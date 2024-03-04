#include <minirt.h>

t_tuple *new_tuple(float x, float y, float z, float w)
{
    t_tuple *result;

    result = malloc(sizeof(t_tuple) * 4);
    result[0] = x;
    result[1] = y;
    result[2] = z;
    result[3] = w;
    return result;
}
