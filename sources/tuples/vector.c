#include <minirt.h>

t_vector *new_vector(float x, float y, float z)
{
    return new_tuple(x, y, z, 0);
}
