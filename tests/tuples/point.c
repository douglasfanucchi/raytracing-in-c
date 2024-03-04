MU_TEST(test_point_creation)
{
    t_point *point = new_point(4, -4, 3);

    mu_assert_double_eq(4, point[0]);
    mu_assert_double_eq(-4, point[1]);
    mu_assert_double_eq(3, point[2]);
}

MU_TEST(test_is_point_a_point)
{
    t_point *point = new_point(4, -4, 3);

    mu_assert_double_eq(1, point[3]);
}

MU_TEST_SUITE(test_point)
{
    MU_RUN_TEST(test_point_creation);
    MU_RUN_TEST(test_is_point_a_point);
}