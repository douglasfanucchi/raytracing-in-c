#include <minirt.h>

MU_TEST(test_2x2_matrix_creation) {
    t_matrix *matrix = new_matrix(2);
    
    mu_assert_int_eq(2, matrix->dimension);
    
    matrix->values[0][0] = 1;
    matrix->values[0][1] = 2;
    matrix->values[1][0] = 3;
    matrix->values[1][1] = 4;

    mu_assert_double_eq(matrix->values[0][0], 1);
    mu_assert_double_eq(matrix->values[0][1], 2);
    mu_assert_double_eq(matrix->values[1][0], 3);
    mu_assert_double_eq(matrix->values[1][1], 4);
}

MU_TEST(test_3x3_matrix_creation) {
    t_matrix *matrix = new_matrix(3);

    mu_assert_int_eq(3, matrix->dimension);

    matrix->values[0][0] = 1;
    matrix->values[0][1] = 2;
    matrix->values[0][2] = 3;
    matrix->values[1][0] = 4;
    matrix->values[1][1] = 5;
    matrix->values[1][2] = 6;
    matrix->values[2][0] = 7;
    matrix->values[2][1] = 8;
    matrix->values[2][2] = 9;

    mu_assert_double_eq(matrix->values[0][0], 1);
    mu_assert_double_eq(matrix->values[0][1], 2);
    mu_assert_double_eq(matrix->values[0][2], 3);
    mu_assert_double_eq(matrix->values[1][0], 4);
    mu_assert_double_eq(matrix->values[1][1], 5);
    mu_assert_double_eq(matrix->values[1][2], 6);
    mu_assert_double_eq(matrix->values[2][0], 7);
    mu_assert_double_eq(matrix->values[2][1], 8);
    mu_assert_double_eq(matrix->values[2][2], 9);
}

MU_TEST(test_4x4_matrix_creation) {
    t_matrix *matrix = new_matrix(4);

    mu_assert_int_eq(4, matrix->dimension);

    matrix->values[0][0] = 1;
    matrix->values[0][1] = 2;
    matrix->values[0][2] = 3;
    matrix->values[0][3] = 4;
    matrix->values[1][0] = 5;
    matrix->values[1][1] = 6;
    matrix->values[1][2] = 7;
    matrix->values[1][3] = 8;
    matrix->values[2][0] = 9;
    matrix->values[2][1] = 10;
    matrix->values[2][2] = 11;
    matrix->values[2][3] = 12;
    matrix->values[3][0] = 13;
    matrix->values[3][1] = 14;
    matrix->values[3][2] = 15;
    matrix->values[3][3] = 16;

    mu_assert_double_eq(matrix->values[0][0], 1);
    mu_assert_double_eq(matrix->values[0][1], 2);
    mu_assert_double_eq(matrix->values[0][2], 3);
    mu_assert_double_eq(matrix->values[0][3], 4);
    mu_assert_double_eq(matrix->values[1][0], 5);
    mu_assert_double_eq(matrix->values[1][1], 6);
    mu_assert_double_eq(matrix->values[1][2], 7);
    mu_assert_double_eq(matrix->values[1][3], 8);
    mu_assert_double_eq(matrix->values[2][0], 9);
    mu_assert_double_eq(matrix->values[2][1], 10);
    mu_assert_double_eq(matrix->values[2][2], 11);
    mu_assert_double_eq(matrix->values[2][3], 12);
    mu_assert_double_eq(matrix->values[3][0], 13);
    mu_assert_double_eq(matrix->values[3][1], 14);
    mu_assert_double_eq(matrix->values[3][2], 15);
    mu_assert_double_eq(matrix->values[3][3], 16);
}

MU_TEST(test_matrixcmp_to_different_dimensions_matrices) {
    t_matrix *A = new_matrix(5);
    t_matrix *B = new_matrix(3);
    char result = matrixcmp(A, B);
    char expected = 1;

    mu_assert(expected == result, "Matrices of different dimensions should be considered different");
}

MU_TEST(test_matrixcmp_to_equal_matrices) {
    t_matrix *A = new_matrix(2);
    t_matrix *B = new_matrix(2);

    A->values[0][0] = 1;
    A->values[0][1] = 2;
    A->values[1][0] = 3;
    A->values[1][1] = 4;

    B->values[0][0] = 1;
    B->values[0][1] = 2;
    B->values[1][0] = 3;
    B->values[1][1] = 4;

    char result = matrixcmp(A, B);
    char expected = 0;

    mu_assert(
        expected == result,
        "Matrix A should be equal to matrix B"
    );
}

MU_TEST(test_matrixcmp_to_different_matrices) {
    
    t_matrix *A = new_matrix(2);
    t_matrix *B = new_matrix(2);

    A->values[0][0] = 1;
    A->values[0][1] = 2;
    A->values[1][0] = 3;
    A->values[1][1] = 4;

    B->values[0][0] = 4;
    B->values[0][1] = 3;
    B->values[1][0] = 2;
    B->values[1][1] = 1;

    char result = matrixcmp(A, B);
    char expected = 1;

    mu_assert(
        expected == result,
        "Matrix A should be different to matrix B"
    );
}

MU_TEST(test_multiply_matrices) {
    t_matrix *A = new_matrix(4);
    t_matrix *B = new_matrix(4);

    A->values[0][0] = 1;
    A->values[0][1] = 2;
    A->values[0][2] = 3;
    A->values[0][3] = 4;
    A->values[1][0] = 5;
    A->values[1][1] = 6;
    A->values[1][2] = 7;
    A->values[1][3] = 8;
    A->values[2][0] = 9;
    A->values[2][1] = 8;
    A->values[2][2] = 7;
    A->values[2][3] = 6;
    A->values[3][0] = 5;
    A->values[3][1] = 4;
    A->values[3][2] = 3;
    A->values[3][3] = 2;

    B->values[0][0] = -2;
    B->values[0][1] = 1;
    B->values[0][2] = 2;
    B->values[0][3] = 3;
    B->values[1][0] = 3;
    B->values[1][1] = 2;
    B->values[1][2] = 1;
    B->values[1][3] = -1;
    B->values[2][0] = 4;
    B->values[2][1] = 3;
    B->values[2][2] = 6;
    B->values[2][3] = 5;
    B->values[3][0] = 1;
    B->values[3][1] = 2;
    B->values[3][2] = 7;
    B->values[3][3] = 8;

    t_matrix *result = matricesmultiply(A, B);
    t_matrix *expected = new_matrix(4);

    expected->values[0][0] = 20;
    expected->values[0][1] = 22;
    expected->values[0][2] = 50;
    expected->values[0][3] = 48;
    expected->values[1][0] = 44;
    expected->values[1][1] = 54;
    expected->values[1][2] = 114;
    expected->values[1][3] = 108;
    expected->values[2][0] = 40;
    expected->values[2][1] = 58;
    expected->values[2][2] = 110;
    expected->values[2][3] = 102;
    expected->values[3][0] = 16;
    expected->values[3][1] = 26;
    expected->values[3][2] = 46;
    expected->values[3][3] = 42;

    mu_assert(
        matrixcmp(expected, result) == 0,
        "Result matrix should be equal the expected matrix"
    );
}

MU_TEST(test_multiply_matrices_by_a_tuple) {
    t_matrix *A = new_matrix(4);
    t_tuple *tuple = new_tuple(1, 2, 3, 1);

    A->values[0][0] = 1;
    A->values[0][1] = 2;
    A->values[0][2] = 3;
    A->values[0][3] = 4;
    A->values[1][0] = 5;
    A->values[1][1] = 6;
    A->values[1][2] = 7;
    A->values[1][3] = 8;
    A->values[2][0] = 9;
    A->values[2][1] = 10;
    A->values[2][2] = 11;
    A->values[2][3] = 12;
    A->values[3][0] = 13;
    A->values[3][1] = 14;
    A->values[3][2] = 15;
    A->values[3][3] = 16;

    t_tuple *result = matrixtuplemultiply(A, tuple);
    t_tuple *expected = new_tuple(18, 46, 74, 102);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Result tuple should be the same as expected."
    );
}

MU_TEST_SUITE(test_matrix) {
    MU_RUN_TEST(test_2x2_matrix_creation);
    MU_RUN_TEST(test_3x3_matrix_creation);
    MU_RUN_TEST(test_4x4_matrix_creation);
    MU_RUN_TEST(test_matrixcmp_to_different_dimensions_matrices);
    MU_RUN_TEST(test_matrixcmp_to_equal_matrices);
    MU_RUN_TEST(test_matrixcmp_to_different_matrices);
    MU_RUN_TEST(test_multiply_matrices);
    MU_RUN_TEST(test_multiply_matrices_by_a_tuple);
}
