MU_TEST(test_tuple_creation) {
    t_tuple *t = new_tuple(4.3, -4.1, 3.5, 1);

    mu_assert_double_eq(4.3, t[0]);
    mu_assert_double_eq(-4.1, t[1]);
    mu_assert_double_eq(3.5, t[2]);
    mu_assert_double_eq(1, t[3]);
}

MU_TEST_SUITE(test_tuples) {
    MU_RUN_TEST(test_tuple_creation);
}
