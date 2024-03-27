#include <minirt.h>

MU_TEST(test_translating_point_should_change_its_coordinates) {
    t_point *p = new_point(0, 0, 0);
    t_matrix *translate_matrix = translate(1, 1, 1);
    t_point *result = matrixtuplemultiply(translate_matrix, p);
    t_point *expected = new_point(1, 1, 1);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Point should be moved to (1, 1, 1) position"
    );
}

MU_TEST(test_translating_vector_should_not_change_its_coordinates) {
    t_vector *v = new_vector(3, 4, 5);
    t_matrix *translate_matrix = translate(1, 1, 1);
    t_vector *result = matrixtuplemultiply(translate_matrix, v);
    t_vector *expected = v;

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Translating a vector should not change its coordinates"
    );
}

MU_TEST_SUITE(test_translate_matrix) {
    MU_RUN_TEST(test_translating_point_should_change_its_coordinates);
    MU_RUN_TEST(test_translating_vector_should_not_change_its_coordinates);
}
