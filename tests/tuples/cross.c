#include <minirt.h>

MU_TEST(test_cross_should_return_a_perpendicular_vector) {
    t_vector *v1 = new_vector(1, 0, 0);
    t_vector *v2 = new_vector(0, 1, 0);
    t_vector *expected = new_vector(0, 0, 1);
    t_vector *result = cross(v1, v2);

    mu_assert(tuplecmp(expected, result) == 0, "Cross should return (0, 0, 1) vector");
}

MU_TEST(test_cross_should_return_a_perpendicular_vector_but_opposite_direction) {
    t_vector *v1 = new_vector(1, 0, 0);
    t_vector *v2 = new_vector(0, 1, 0);
    t_vector *expected = new_vector(0, 0, -1);
    t_vector *result = cross(v2, v1);

    mu_assert(tuplecmp(expected, result) == 0, "Cross should return (0, 0, -1) vector");
}

MU_TEST_SUITE(test_cross_product) {
    MU_RUN_TEST(test_cross_should_return_a_perpendicular_vector);
    MU_RUN_TEST(test_cross_should_return_a_perpendicular_vector_but_opposite_direction);
}
