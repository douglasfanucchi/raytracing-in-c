#include <minirt.h>

t_vector    *reflect(t_vector *in, t_vector *normal)
{
    t_vector    *result;

    normal = tuplemultiply(normal, 2 * dot(in, normal));
    result = tuplesub(in, normal);
    free(normal);
    return(result);
}
