#include <stdlib.h>
#include <math.h>

#define EPSILON 1E-5

typedef float t_tuple;
typedef t_tuple t_point;

t_tuple *new_tuple(float x, float y, float z, float type);
t_tuple *new_point(float x, float y, float z);
char    tuplecmp(t_tuple *t1, t_tuple *t2);
