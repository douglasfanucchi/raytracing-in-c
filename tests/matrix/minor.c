#include <minirt.h>

MU_TEST(test_minor_3x3_matrix) {
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

    float result = minor(A, 1, 0);
    float expected = 25;

    mu_assert_double_eq(expected, result);
}

MU_TEST_SUITE(test_minor) {
    MU_RUN_TEST(test_minor_3x3_matrix);
}
