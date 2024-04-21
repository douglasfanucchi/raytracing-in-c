#include <minirt.h>

t_intersection *new_intersection(float t, void *object)
{
    t_intersection  *intersection;

    intersection = malloc(sizeof(t_intersection));
    intersection->t = t;
    intersection->object = object;
    return (intersection);
}

t_list  **intersect(void *object, t_ray *ray)
{
    float           discriminant;
    t_vector        *sphere_to_ray;
    t_list          **list;
    float           a;
    float           b;
    float           c;

    list = ft_newlist();
    sphere_to_ray = new_vector(ray->origin[0], ray->origin[1], ray->origin[2]);
    a = dot(ray->direction, ray->direction);
    b = dot(sphere_to_ray, ray->direction);
    c = dot(sphere_to_ray, sphere_to_ray) - 1;
    discriminant = pow(b, 2) - a*c;
    if (!(discriminant < 0)) {
        ft_lstadd_back(
            list,
            ft_lstnew(new_intersection((-b - sqrt(discriminant)) / a, object))
        );
        ft_lstadd_back(
            list,
            ft_lstnew(new_intersection((-b + sqrt(discriminant)) / a, object))
        );
    }
    free(sphere_to_ray);
    return (list);
}

void free_intersection(t_intersection *intersection)
{
    free(intersection);
}
