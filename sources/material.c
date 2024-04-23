#include <minirt.h>

t_material  *new_material(t_color *color, float ambient,
    float diffuse, float specular, float shininess)
{
    t_material  *material;

    material = malloc(sizeof(t_material));
    material->color = color;
    material->ambient = ambient;
    material->diffuse = diffuse;
    material->specular = specular;
    material->shininess = shininess;
    return (material);
}

void    free_material(t_material *material)
{
    free(material->color);
    free(material);
}
