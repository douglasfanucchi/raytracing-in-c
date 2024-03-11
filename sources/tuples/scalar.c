#include <minirt.h>

t_tuple *tuplemultiply(t_tuple *tuple, float scalar)
{
    return new_tuple(
        tuple[0] * scalar,
        tuple[1] * scalar,
        tuple[2] * scalar,
        tuple[3] * scalar
    );
}

t_tuple *tupledivide(t_tuple *tuple, float scalar)
{
    return tuplemultiply(tuple, 1.f/scalar);
}