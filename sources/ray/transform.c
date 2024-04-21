#include <minirt.h>

t_ray   *transform(t_ray *ray, t_matrix *matrix)
{
    t_point *origin;
    t_point *direction;

    origin = matrixtuplemultiply(matrix, ray->origin);
    direction = matrixtuplemultiply(matrix, ray->direction);
    return new_ray(origin, direction);
}