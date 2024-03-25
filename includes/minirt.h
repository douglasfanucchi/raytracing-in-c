#include <stdlib.h>
#include <math.h>

#ifndef MINIRT
# define MINIRT

#define EPSILON 1E-5
#ifndef M_PI_4
    #define M_PI_4 0.785398163397448309616
#endif

typedef struct s_matrix {
    int dimension;
    float **values;
} t_matrix;

typedef float t_tuple;
typedef t_tuple t_point;
typedef t_tuple t_vector;
typedef t_tuple t_color;

t_tuple *new_tuple(float x, float y, float z, float type);
t_tuple *tupleadd(t_tuple *t1, t_tuple *t2);
t_tuple *tuplesub(t_tuple *t1, t_tuple *t2);
t_tuple *tuplemultiply(t_tuple *tuple, float scalar);
t_tuple *tupledivide(t_tuple *tuple, float scalar);
t_tuple *tuple_opposite(t_tuple *tuple);
t_tuple *new_point(float x, float y, float z);
t_tuple *normalize(t_tuple *tuple);
t_vector *new_vector(float x, float y, float z);
char    tuplecmp(t_tuple *t1, t_tuple *t2);
float magnitude(t_tuple *tuple);
float   dot(t_vector *v1, t_vector *v2);
t_vector   *cross(t_vector *v1, t_vector *v2);
t_color *new_color(float red, float green, float blue);
t_color *colorsmultiply(t_color *c1, t_color *c2);
t_matrix *new_matrix(int dimension);
char    matrixcmp(t_matrix *A, t_matrix *B);
t_matrix    *matricesmultiply(t_matrix *A, t_matrix *B);
t_tuple     *matrixtuplemultiply(t_matrix *A, t_tuple *tuple);
t_matrix    *new_identity();
t_matrix    *transpose(t_matrix *A);
float       determinant(t_matrix *A);
t_matrix    *submatrix(t_matrix *A, int row, int column);
float       minor(t_matrix *A, int row, int column);
float       cofactor(t_matrix *A, int row, int column);
char        is_invertible(t_matrix *A);
t_matrix    *inverse(t_matrix *A);

#endif
