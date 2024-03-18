#include <minirt.h>
#include <math.h>

MU_TEST(test_dot_product_should_return_0_when_angle_between_vectors_is_90) {
    t_vector *v1 = new_vector(5, 0, 0);
    t_vector *v2 = new_vector(0, 5, 0);
    float result = dot(v1, v2);
    float expected = 0;

    mu_assert_double_eq(expected, result);
}

MU_TEST(test_dot_product_should_return_the_angles_cosine_when_unit_vectors) {
    t_vector *v1 = normalize(new_vector(5, 5, 0));
    t_vector *v2 = normalize(new_vector(5, 0, 0));
    float result = dot(v1, v2);
    float expected = cos(M_PI_4);

    mu_assert_double_eq(expected, result);
}

MU_TEST_SUITE(test_dot_product) {
    MU_RUN_TEST(test_dot_product_should_return_0_when_angle_between_vectors_is_90);
    MU_RUN_TEST(test_dot_product_should_return_the_angles_cosine_when_unit_vectors);
}
