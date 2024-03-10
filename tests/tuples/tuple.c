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

MU_TEST(test_tuple_addition) {
    t_tuple *t1 = new_tuple(3.5, 2.9, 1, 0);
    t_tuple *t2 = new_tuple(4, 5, 1, 1);
    t_tuple *expected = new_tuple(7.5, 7.9, 2, 1);
    t_tuple *result = tupleadd(t1, t2);

    mu_assert(tuplecmp(expected, result) == 0, "result should be (7.5, 7.9, 2, 1)");

    t_point *origin = new_point(0, 0, 0);
    t_vector *direction = new_vector(1, 1, 1);
    t_point *expected_destination = new_point(1, 1, 1); 
    t_point *destination = tupleadd(origin, direction);

    mu_assert(
        tuplecmp(expected_destination, destination) == 0,
        "Destination should be (1, 1, 1)"
    );
}


MU_TEST_SUITE(test_tuples) {
    MU_RUN_TEST(test_tuple_creation);
    MU_RUN_TEST(test_tuple_comparition);
    MU_RUN_TEST(test_tuple_addition);
}
