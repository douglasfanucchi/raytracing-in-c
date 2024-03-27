#include <minirt.h>

MU_TEST(test_scaling_points) {
    t_point *p = new_point(1, 2, 3);
    t_matrix *transformation = scale(3, 5, 10);
    t_point *result = matrixtuplemultiply(transformation, p);
    t_point *expected = new_point(3, 10, 30);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Scaling point p should change its coordinates to (3, 10, 30)"
    );
}

MU_TEST(test_scaling_vectors) {
    t_vector *v = new_vector(1, 2, 3);
    t_matrix *transformation = scale(3, 5, 10);
    t_vector *result = matrixtuplemultiply(transformation, v);
    t_vector *expected = new_vector(3, 10, 30);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Scaling vector v should change its coordinates to (3, 10, 30)"
    );

    transformation = inverse(transformation);
    result = matrixtuplemultiply(transformation, v);
    expected = new_vector(1.f/3.f, 2.f/5.f, 3.f/10.f);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Scaling vector v by the inverse of transformation should divide its components"
    );
}

MU_TEST_SUITE(test_scale_matrix) {
    MU_RUN_TEST(test_scaling_points);
    MU_RUN_TEST(test_scaling_vectors);
}