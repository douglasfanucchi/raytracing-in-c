#include <stdlib.h>
#include <math.h>

#define EPSILON 1E-5

typedef float t_tuple;
typedef t_tuple t_point;
typedef t_tuple t_vector;

t_tuple *new_tuple(float x, float y, float z, float type);
t_tuple *tupleadd(t_tuple *t1, t_tuple *t2);
t_tuple *tuplesub(t_tuple *t1, t_tuple *t2);
t_tuple *tuplemultiply(t_tuple *tuple, float scalar);
t_tuple *tupledivide(t_tuple *tuple, float scalar);
t_tuple *tuple_opposite(t_tuple *tuple);
t_tuple *new_point(float x, float y, float z);
t_vector *new_vector(float x, float y, float z);
char    tuplecmp(t_tuple *t1, t_tuple *t2);
