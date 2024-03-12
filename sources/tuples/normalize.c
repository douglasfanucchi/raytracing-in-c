#include <minirt.h>

t_tuple *normalize(t_tuple *tuple)
{
    float   norma;

    norma = magnitude(tuple);
    return new_tuple(
        tuple[0] / norma,
        tuple[1] / norma,
        tuple[2] / norma,
        tuple[3] / norma
    );
}
