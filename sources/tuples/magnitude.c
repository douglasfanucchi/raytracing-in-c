#include <minirt.h>

float magnitude(t_tuple *tuple)
{
    return sqrt(
        pow(tuple[0], 2) +
        pow(tuple[1], 2) +
        pow(tuple[2], 2) +
        pow(tuple[3], 2)
    );
}