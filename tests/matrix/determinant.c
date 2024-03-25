#include <minirt.h>

MU_TEST(test_calculate_determinant_2x2_matrix) {
    t_matrix *A = new_matrix(2);
    A->values[0][0] = 1;
    A->values[0][1] = 2;
    A->values[1][0] = 3;
    A->values[1][1] = 4;
    float result = determinant(A);
    float expected = -2;

    mu_assert_double_eq(expected, result);
}

MU_TEST_SUITE(test_determinant) {
    MU_RUN_TEST(test_calculate_determinant_2x2_matrix);
}
