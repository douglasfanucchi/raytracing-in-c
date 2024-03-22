#include <minirt.h>

MU_TEST(test_should_create_color_successfully) {
    t_color *color = new_color(0.2, 0.5, 0.9);

    mu_assert_double_eq(color[0], 0.2);
    mu_assert_double_eq(color[1], 0.5);
    mu_assert_double_eq(color[2], 0.9);
}

MU_TEST(test_add_colors) {
    t_color *c1 = new_color(0.5, 0.4, 0.3);
    t_color *c2 = new_color(0, 0.2, 0.7);
    t_color *result = tupleadd(c1, c2);
    t_color *expected = new_color(0.5, 0.6, 1);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Result color should be (0.5, 0.6, 1)"
    );
}

MU_TEST(test_subtract_colors) {
    t_color *c1 = new_color(1, 0.3, 0.9);
    t_color *c2 = new_color(0.5, 0.1, 1);
    t_color *result = tuplesub(c1, c2);
    t_color *expected = new_color(0.5, 0.2, -0.1);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Result color should be (0.5, 0.2, -0.1)"
    );
}

MU_TEST(test_multiply_color_by_scalar) {
    t_color *c1 = new_color(0.5, 0.1, 1);
    t_color *result = tuplemultiply(c1, 0.1);
    t_color *expected = new_color(0.05, 0.01, 0.1);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Result color should be (0.05, 0.01, 0.1)"
    );
}

MU_TEST(test_mutiply_colors) {
    t_color *c1 = new_color(0.5, 0.1, 1);
    t_color *c2 = new_color(0.3, 0.75, 0.9);
    t_color *result = colorsmultiply(c1, c2);
    t_color *expected = new_color(0.15, 0.075, 0.9);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Result color should be (0.15, 0.075, 0.9)"
    );
}

MU_TEST_SUITE(test_colors) {
    MU_RUN_TEST(test_should_create_color_successfully);
    MU_RUN_TEST(test_add_colors);
    MU_RUN_TEST(test_subtract_colors);
    MU_RUN_TEST(test_multiply_color_by_scalar);
    MU_RUN_TEST(test_mutiply_colors);
}
