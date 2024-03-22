#include <minirt.h>

t_color *new_color(float red, float green, float blue)
{
    return new_tuple(red, green, blue, 0);
}

t_color *colorsmultiply(t_color *c1, t_color *c2)
{
    return new_color(
        c1[0] * c2[0],
        c1[1] * c2[1],
        c1[2] * c2[2]
    );
}
