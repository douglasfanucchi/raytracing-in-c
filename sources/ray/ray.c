#include <minirt.h>

t_ray *new_ray(t_point *origin, t_vector *direction)
{
    t_ray   *ray;

    ray = malloc(sizeof(t_ray));
    ray->origin = origin;
    ray->direction = direction;
    return (ray);
}