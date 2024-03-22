#include <minirt.h>

MU_TEST(test_should_create_color_successfully) {
    t_color *color = new_color(0.2, 0.5, 0.9);

    mu_assert_double_eq(color[0], 0.2);
    mu_assert_double_eq(color[1], 0.5);
    mu_assert_double_eq(color[2], 0.9);
}

MU_TEST_SUITE(test_colors) {
    MU_RUN_TEST(test_should_create_color_successfully);
}
