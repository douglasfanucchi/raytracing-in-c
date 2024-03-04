#include <minirt.h>

t_point *new_point(float x, float y, float z)
{
    t_tuple *tuple;

    tuple = new_tuple(x, y, z, 1);
    return tuple;
}
