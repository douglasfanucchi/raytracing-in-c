#include <minirt.h>

MU_TEST(test_skewing_point_on_x) {
    t_point *p = new_point(0, 1, 0);
    t_matrix *transformation = skew(2, 0, 0, 0, 0, 0);
    t_point *result = matrixtuplemultiply(transformation, p);
    t_point *expected = new_point(2, 1, 0);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Point should be at position (2, 1, 0)"
    );

    p = new_point(0, 0, 0.5);
    transformation = skew(0, 5, 0, 0, 0, 0);
    result = matrixtuplemultiply(transformation, p);
    expected = new_point(2.5, 0, 0.5);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Point should be at position (2.5, 0, 0.5)"
    );
}

MU_TEST(test_skewing_point_on_y) {
    t_point *p = new_point(3, 4, 5);
    t_matrix *transformation = skew(0, 0, 0.5, 0, 0, 0);
    t_point *result = matrixtuplemultiply(transformation, p);
    t_point *expected = new_point(3, 5.5, 5);
    
    mu_assert(
        tuplecmp(expected, result) == 0,
        "Point should be at (3, 5.5, 5)"
    );

    p = new_point(3, 4, 5);
    transformation = skew(0, 0, 0, 1, 0, 0);
    result = matrixtuplemultiply(transformation, p);
    expected = new_point(3, 9, 5);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Point should be at (3, 9, 5)"
    );
}

MU_TEST(test_skewing_point_on_z) {
    t_point *p = new_point(3, 4, 5);
    t_matrix *transformation = skew(0, 0, 0, 0, 1, 0);
    t_point *result = matrixtuplemultiply(transformation, p);
    t_point *expected = new_point(3, 4, 8);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Point should be at (3, 4, 8)"
    );

    p = new_point(3, 4, 5);
    transformation = skew(0, 0, 0, 0, 0, 1);
    result = matrixtuplemultiply(transformation, p);
    expected = new_point(3, 4, 9);
    mu_assert(
        tuplecmp(expected, result) == 0,
        "Point should be at (3, 4, 9)"
    );
}

MU_TEST_SUITE(test_skew_matrix) {
    MU_RUN_TEST(test_skewing_point_on_x);
    MU_RUN_TEST(test_skewing_point_on_y);
    MU_RUN_TEST(test_skewing_point_on_z);
}