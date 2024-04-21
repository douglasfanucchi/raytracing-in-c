#include <minirt.h>

t_sphere *new_sphere(t_point *origin, float radius)
{
    t_sphere    *sphere;

    sphere = malloc(sizeof(t_sphere));
    sphere->origin = origin;
    sphere->radius = radius;
    sphere->transform = new_identity();
    return (sphere);
}

void free_sphere(t_sphere *sphere)
{
    free(sphere->origin);
    free(sphere);
}