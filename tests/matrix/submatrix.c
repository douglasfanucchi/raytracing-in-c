#include <minirt.h>

MU_TEST(test_submatrix_of_a_3x3_matrix) {
    t_matrix *A = new_matrix(3);

    A->values[0][0] = 1;
    A->values[0][1] = 5;
    A->values[0][2] = 0;
    A->values[1][0] = -3;
    A->values[1][1] = 2;
    A->values[1][2] = 7;
    A->values[2][0] = 0;
    A->values[2][1] = 6;
    A->values[2][2] = -3;

    t_matrix *result = submatrix(A, 0, 2);
    t_matrix *expected = new_matrix(2);

    expected->values[0][0] = -3;
    expected->values[0][1] = 2;
    expected->values[1][0] = 0;
    expected->values[1][1] = 6;

    mu_assert(
        matrixcmp(expected, result) == 0,
        "Result matrix should be the same as expected."
    );
}

MU_TEST(test_submatrix_of_a_4x4_matrix) {
    t_matrix *A = new_matrix(4);
    A->values[0][0] = -6;
    A->values[0][1] = 1;
    A->values[0][2] = 1;
    A->values[0][3] = 6;
    A->values[1][0] = -8;
    A->values[1][1] = 5;
    A->values[1][2] = 8;
    A->values[1][3] = 6;
    A->values[2][0] = -1;
    A->values[2][1] = 0;
    A->values[2][2] = 8;
    A->values[2][3] = 2;
    A->values[3][0] = -7;
    A->values[3][1] = 1;
    A->values[3][2] = -1;
    A->values[3][3] = 1;

    t_matrix *expected = new_matrix(3);
    expected->values[0][0] = -6;
    expected->values[0][1] = 1;
    expected->values[0][2] = 6;
    expected->values[1][0] = -8;
    expected->values[1][1] = 8;
    expected->values[1][2] = 6;
    expected->values[2][0] = -7;
    expected->values[2][1] = -1;
    expected->values[2][2] = 1;

    t_matrix *result = submatrix(A, 2, 1);
    
    mu_assert(
        matrixcmp(expected, result) == 0,
        "Result matrix should be equal to expected."
    );
}

MU_TEST_SUITE(test_submatrix) {
    MU_RUN_TEST(test_submatrix_of_a_3x3_matrix);
    MU_RUN_TEST(test_submatrix_of_a_4x4_matrix);
}