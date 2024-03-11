#include <minirt.h>

MU_TEST(test_tuple_magnitude) {
    t_tuple *tuple = new_tuple(1, 0, 0, 1);
    float result = magnitude(tuple);
    float expected = sqrt(2);

    mu_assert_double_eq(expected, result);
}

MU_TEST(test_vector_magnitude) {
    t_vector *vector = new_vector(3, 4, 0);
    float result = magnitude(vector);
    float expected = 5;

    mu_assert_double_eq(expected, result);
}

MU_TEST_SUITE(test_magnitude) {
    MU_RUN_TEST(test_tuple_magnitude);
    MU_RUN_TEST(test_vector_magnitude);
}
