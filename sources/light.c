#include <minirt.h>

t_light *new_light(t_color *intensity, t_point *position)
{
    t_light *light;

    light = malloc(sizeof(t_light));
    light->intensity = intensity;
    light->position = position;
    return (light);
}

void    free_light(t_light *light)
{
    free(light->intensity);
    free(light->position);
    free(light);
}
