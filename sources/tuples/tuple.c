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

t_tuple *tupleadd(t_tuple *t1, t_tuple *t2)
{
    t_tuple *result;

    result = new_tuple(
        t1[0] + t2[0],
        t1[1] + t2[1],
        t1[2] + t2[2],
        t1[3] + t2[3]
    );
    return result;
}

t_tuple *tuplesub(t_tuple *t1, t_tuple *t2)
{
    t_tuple *result;

    result = new_tuple(
        t1[0] - t2[0],
        t1[1] - t2[1],
        t1[2] - t2[2],
        t1[3] - t2[3]
    );
    return result;
}

t_tuple *tuple_opposite(t_tuple *tuple)
{
    t_tuple *zero;
    t_tuple *result;

    zero = new_tuple(0, 0, 0, 0);
    result = tuplesub(zero, tuple);
    free(zero);
    return result;
}
