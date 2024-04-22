#include <minirt.h>

t_vector *normal_at(t_sphere *sphere, t_point *point)
{
    t_point     *object_point;
    t_matrix    *inverse_transform;
    t_matrix    *transposed;
    t_vector    *object_normal;
    t_vector    *normal;
    t_vector    *normalized;

    inverse_transform = inverse(sphere->transform);
    transposed = transpose(inverse_transform);
    object_point = matrixtuplemultiply(inverse_transform, point);
    object_normal = new_vector(object_point[0], object_point[1], object_point[2]);
    normal = matrixtuplemultiply(transposed, object_normal);
    normal[3] = 0;
    normalized = normalize(normal);
    free(inverse_transform);
    free(transposed);
    free(object_point);
    free(object_normal);
    free(normal);
    return (normalized);
}
