#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include <libft.h>

#ifndef MINIRT
# define MINIRT

#define EPSILON 1E-5
#ifndef M_PI_4
    #define M_PI_4 0.785398163397448309616
#endif

#ifndef M_PI_2
    #define M_PI_2 M_PI_4*2
#endif

#ifndef M_PI
    #define M_PI M_PI_2*2
#endif

typedef struct s_matrix {
    int dimension;
    float **values;
} t_matrix;

typedef float t_tuple;
typedef t_tuple t_point;
typedef t_tuple t_vector;
typedef t_tuple t_color;

typedef struct s_ray {
    t_point *origin;
    t_vector *direction;
} t_ray;

typedef struct s_sphere {
    t_matrix            *transform;
    struct s_material   *material;
} t_sphere;

typedef struct s_intersection {
    void *object;
    float t;
} t_intersection;

typedef struct s_light {
    t_color *intensity;
    t_point *position;
} t_light;

typedef struct s_material {
    t_color *color;
    float   ambient;
    float   diffuse;
    float   specular;
    float   shininess;
} t_material;

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
void free_matrix(t_matrix *matrix);
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
t_matrix    *translate(float x, float y, float z);
t_matrix    *scale(float x, float y, float z);
t_matrix    *rotatex(float angle);
t_matrix    *rotatey(float angle);
t_matrix    *rotatez(float angle);
t_matrix    *skew(float xy, float xz, float yx, float yz, float zx, float zy);
t_ray       *new_ray(t_point *origin, t_vector *direction);
t_point     *position(t_ray *ray, float scalar);
t_sphere    *new_sphere();
t_intersection *new_intersection(float t, void *object);
t_list      **intersect(void *object, t_ray *ray);
t_intersection *hit(t_list **intersections);
t_ray       *transform(t_ray *ray, t_matrix *matrix);
void        set_transform(void *object, t_matrix *matrix);
t_vector    *normal_at(t_sphere *sphere, t_point *point);
t_vector    *reflect(t_vector *in, t_vector *normal);
t_light     *new_light(t_color *color, t_point *position);
void        free_light(t_light *light);
t_material  *new_material(t_color *color, float ambient, float diffuse, float specular, float shininess);
void        free_material(t_material *material);
void        set_material(t_sphere *sphere, t_material *material);
t_color     *lighting(t_material *material, t_light *light, t_point *point, t_vector *eyev, t_vector *normal);

#endif
