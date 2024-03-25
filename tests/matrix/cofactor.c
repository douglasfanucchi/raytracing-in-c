#include <minirt.h>

MU_TEST(test_calculate_cofactor_3x3_matrix) {
    t_matrix *A = new_matrix(3);
    A->values[0][0] = 3;
    A->values[0][1] = 5;
    A->values[0][2] = 0;
    A->values[1][0] = 2;
    A->values[1][1] = -1;
    A->values[1][2] = -7;
    A->values[2][0] = 6;
    A->values[2][1] = -1;
    A->values[2][2] = 5;

    float result = cofactor(A, 0, 0);
    float expected = -12;

    mu_assert_double_eq(expected, result);

    result = cofactor(A, 1, 0);
    expected = -25;

    mu_assert_double_eq(expected, result);
}

MU_TEST_SUITE(test_cofactor) {
    MU_RUN_TEST(test_calculate_cofactor_3x3_matrix);
}
