#include <minirt.h>

float dot(t_vector *v1, t_vector *v2) {
    return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2] + v1[3]*v2[3];
}
