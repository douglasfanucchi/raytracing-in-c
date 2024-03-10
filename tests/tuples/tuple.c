MU_TEST(test_tuple_creation) {
    t_tuple *t = new_tuple(4.3, -4.1, 3.5, 1);

    mu_assert_double_eq(4.3, t[0]);
    mu_assert_double_eq(-4.1, t[1]);
    mu_assert_double_eq(3.5, t[2]);
    mu_assert_double_eq(1, t[3]);
}

MU_TEST(test_tuple_comparition) {
    t_tuple *t1 = new_tuple(4.3, -4.1, 3.5, 1);
    t_tuple *t2 = new_tuple(4.3, -4.1, 3.5, 1);

    mu_assert(tuplecmp(t1, t2) == 0, "Tuple t1 and t2 should be equal");

    t1 = new_tuple(4.3, -4.1, 3.5, 1);
    t2 = new_tuple(0, 1, 5, 1);

    mu_assert(tuplecmp(t1, t2) == 1, "Tuple t1 and t2 should be different");

    t1 = new_tuple(4.3, -4.1, 3.5, 1);
    t2 = new_tuple(4.3, -4.1, 3.5, 0);

    mu_assert(tuplecmp(t1, t2) == 1, "Tuple t1 and t2 should be different. (t1 is a point, t2 is a vector)");
}

MU_TEST_SUITE(test_tuples) {
    MU_RUN_TEST(test_tuple_creation);
    MU_RUN_TEST(test_tuple_comparition);
}
