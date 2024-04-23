#include <minirt.h>

t_sphere *new_sphere()
{
    t_sphere    *sphere;

    sphere = malloc(sizeof(t_sphere));
    sphere->transform = new_identity();
    sphere->material = new_material(
        new_color(1, 1, 1), 0.1, 0.9, 0.9, 200
    );
    return (sphere);
}

void free_sphere(t_sphere *sphere)
{
    free_material(sphere->material);
    free_matrix(sphere->transform);
    free(sphere);
}