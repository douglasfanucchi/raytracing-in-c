#include <minirt.h>

t_intersection *new_intersection(float t, void *object)
{
    t_intersection  *intersection;

    intersection = malloc(sizeof(t_intersection));
    intersection->t = t;
    intersection->object = object;
    return (intersection);
}

void free_intersection(t_intersection *intersection)
{
    free(intersection);
}
