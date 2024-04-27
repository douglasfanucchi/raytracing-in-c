#include <stdio.h>
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


t_color *lighting(t_material *material, t_light *light, t_point *point,
    t_vector *eyev, t_vector *normalv)
{
    t_color     *color;
    t_color     *ambient;
    t_tuple     *aux;
    t_color     *diffuse;
    t_color     *specular;
    t_vector    *lightv;
    t_vector    *reflectorv;

    diffuse = new_color(0, 0, 0);
    specular = new_color(0, 0, 0);
    color = colorsmultiply(material->color, light->intensity);
    ambient = tuplemultiply(color, material->ambient);
    lightv = tuplesub(light->position, point);
    aux = lightv;
    lightv = normalize(lightv);
    free(aux);
    if (dot(lightv, normalv) < 0) {
        free(lightv);
        free(color);
        aux = tupleadd(ambient, diffuse);
        free(ambient);
        free(diffuse);
        color = tupleadd(aux, specular);
        free(aux);
        free(specular);
        return (color);
    }
    free(diffuse);
    diffuse = tuplemultiply(color, material->diffuse * dot(lightv, normalv));
    aux = lightv;
    lightv = tuplemultiply(lightv, -1);
    free(aux);
    reflectorv = reflect(lightv, normalv);
    free(lightv);
    if (dot(reflectorv, eyev) > 0) {
        free(specular);
        specular = tuplemultiply(
            light->intensity,
            material->specular * pow(dot(reflectorv, eyev), material->shininess)
        );
    }
    free(color);
    color = tupleadd(ambient, diffuse);
    aux = color;
    color = tupleadd(color, specular);
    free(aux);
    free(ambient);
    free(diffuse);
    free(reflectorv);
    if (color[0] > 1) {
        color[0] = 1;
    }
    if (color[1] > 1) {
        color[1] = 1;
    }
    if (color[2] > 1) {
        color[2] = 1;
    }
    return (color);
}
