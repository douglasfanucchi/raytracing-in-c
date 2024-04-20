#include <minirt.h>

t_ray *new_ray(t_point *origin, t_vector *direction)
{
    t_ray   *ray;

    ray = malloc(sizeof(t_ray));
    ray->origin = origin;
    ray->direction = direction;
    return (ray);
}

t_point *position(t_ray *ray, float scalar)
{
    t_point *result;
    t_vector *scaled_direction;

    scaled_direction = tuplemultiply(ray->direction, scalar);
    result = tupleadd(ray->origin, scaled_direction);
    free(scaled_direction);
    return (result);
}
