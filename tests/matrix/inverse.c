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

MU_TEST_SUITE(test_inverse_matrix) {
    MU_RUN_TEST(test_is_invertible);
}
