#include <minirt.h>

MU_TEST(test_rotate_around_x_axis) {
    t_point *p = new_point(0, 1, 0);
    t_matrix *transformation = rotatex(M_PI_2);
    t_point *result = matrixtuplemultiply(transformation, p);
    t_point *expected = new_point(0, 0, 1);

    mu_assert(
        tuplecmp(result, expected) == 0,
        "Result should be the point at (0, 0, 1)"
    );
}

MU_TEST_SUITE(test_rotate_matrices) {
    MU_RUN_TEST(test_rotate_around_x_axis);
}