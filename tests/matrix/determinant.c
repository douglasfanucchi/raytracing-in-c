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

MU_TEST(test_calculate_determinant_3x3_matrix) {
    t_matrix *A = new_matrix(3);

    A->values[0][0] = 1;
    A->values[0][1] = 2;
    A->values[0][2] = 6;
    A->values[1][0] = -5;
    A->values[1][1] = 8;
    A->values[1][2] = -4;
    A->values[2][0] = 2;
    A->values[2][1] = 6;
    A->values[2][2] = 4;

    float result = determinant(A);
    float expected = -196;

    mu_assert_double_eq(expected, result);
}

MU_TEST(test_calculate_determinant_4x4_matrix) {
    t_matrix *A = new_matrix(4);

    A->values[0][0] = -2;
    A->values[0][1] = -8;
    A->values[0][2] = 3;
    A->values[0][3] = 5;
    A->values[1][0] = -3;
    A->values[1][1] = 1;
    A->values[1][2] = 7;
    A->values[1][3] = 3;
    A->values[2][0] = 1;
    A->values[2][1] = 2;
    A->values[2][2] = -9;
    A->values[2][3] = 6;
    A->values[3][0] = -6;
    A->values[3][1] = 7;
    A->values[3][2] = 7;
    A->values[3][3] = -9;

    float result = determinant(A);
    float expected = -4071;
}

MU_TEST_SUITE(test_determinant) {
    MU_RUN_TEST(test_calculate_determinant_2x2_matrix);
    MU_RUN_TEST(test_calculate_determinant_3x3_matrix);
    MU_RUN_TEST(test_calculate_determinant_4x4_matrix);
}
