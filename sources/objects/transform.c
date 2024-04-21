#include <minirt.h>

void    set_transform(void *object, t_matrix *matrix)
{
    t_sphere    *sphere;

    sphere = object;
    sphere->transform = matricesmultiply(sphere->transform, matrix);
}