#include <minirt.h>

MU_TEST(test_multiply) {
    t_tuple *tuple = new_tuple(10, 5, 3, 1);
    t_tuple *expected = new_tuple(20, 10, 6, 2);
    t_tuple *result = tuplemultiply(tuple, 2);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "result should be (20, 10, 6, 2)"
    );
}

MU_TEST_SUITE(test_scalar) {
    MU_RUN_TEST(test_multiply);
}
