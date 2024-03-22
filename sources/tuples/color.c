#include <minirt.h>

t_color *new_color(float red, float green, float blue)
{
    return new_tuple(red, green, blue, 0);
}
