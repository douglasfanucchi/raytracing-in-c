#include <minirt.h>

t_sphere *new_sphere()
{
    t_sphere    *sphere;

    sphere = malloc(sizeof(t_sphere));
    sphere->transform = new_identity();
    return (sphere);
}

void free_sphere(t_sphere *sphere)
{
    free_matrix(sphere->transform);
    free(sphere);
}