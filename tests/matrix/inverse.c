#include <minirt.h>

MU_TEST(test_is_invertible) {
    t_matrix *A = new_matrix(2);
    A->values[0][0] = 1;
    A->values[0][1] = 2;
    A->values[1][0] = 1;
    A->values[1][1] = 2;

    mu_assert(
        is_invertible(A) == 0,
        "Matrix A should not be considered invertible"
    );

    A = new_matrix(2);
    A->values[0][0] = 1;
    A->values[0][1] = 2;
    A->values[1][0] = 3;
    A->values[1][1] = 4;

    mu_assert(
        is_invertible(A) == 1,
        "Matrix A should be considered invertible"
    );
}

MU_TEST(test_inverse_4x4_matrix) {
    t_matrix *A = new_matrix(4);
    A->values[0][0] = -5;
    A->values[0][1] = 2;
    A->values[0][2] = 6;
    A->values[0][3] = -8;
    A->values[1][0] = 1;
    A->values[1][1] = -5;
    A->values[1][2] = 1;
    A->values[1][3] = 8;
    A->values[2][0] = 7;
    A->values[2][1] = 7;
    A->values[2][2] = -6;
    A->values[2][3] = -7;
    A->values[3][0] = 1;
    A->values[3][1] = -3;
    A->values[3][2] = 7;
    A->values[3][3] = 4;

    t_matrix *expected = new_matrix(4);
    expected->values[0][0] = 0.21805;
    expected->values[0][1] = 0.45113;
    expected->values[0][2] = 0.24060;
    expected->values[0][3] = -0.04511;
    expected->values[1][0] = -0.80827;
    expected->values[1][1] = -1.45677;
    expected->values[1][2] = -0.44361;
    expected->values[1][3] = 0.52068;
    expected->values[2][0] = -0.07895;
    expected->values[2][1] = -0.22368;
    expected->values[2][2] = -0.05263;
    expected->values[2][3] = 0.19737;
    expected->values[3][0] = -0.52256;
    expected->values[3][1] = -0.81391;
    expected->values[3][2] = -0.30075;
    expected->values[3][3] = 0.30639;

    t_matrix *result = inverse(A);

    mu_assert(
        matrixcmp(result, expected) == 0,
        "Inversed matrix should be equal to expected matrix"
    );
}

MU_TEST_SUITE(test_inverse_matrix) {
    MU_RUN_TEST(test_is_invertible);
    MU_RUN_TEST(test_inverse_4x4_matrix);
}
