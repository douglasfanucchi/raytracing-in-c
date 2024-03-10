#include <minirt.h>

t_tuple *new_tuple(float x, float y, float z, float w)
{
    t_tuple *result;

    result = malloc(sizeof(t_tuple) * 4);
    result[0] = x;
    result[1] = y;
    result[2] = z;
    result[3] = w;
    return result;
}

char tuplecmp(t_tuple *t1, t_tuple *t2)
{
    char result;
    int  i;

    result = 0;
    i = 0;

    while(i < 4)
    {
        if (fabs(t1[i] - t2[i]) > EPSILON) {
            result = 1;
            break;
        }
        i++;
    }
    return (result);
}
