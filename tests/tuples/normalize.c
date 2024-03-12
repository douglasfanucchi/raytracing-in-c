MU_TEST(test_normalize_tuple) {
    t_tuple *tuple = new_tuple(3, 1, 0, 4);
    t_tuple *normalized = normalize(tuple);
    float result = magnitude(normalized);
    float expected = 1.0;

    mu_assert_double_eq(expected, result);
}

MU_TEST(test_normalize_vector) {
    t_vector *vector = new_vector(3, 4, 0);
    t_vector *normalized = normalize(vector);
    float result = magnitude(normalized);
    float expected = 1.0;

    mu_assert_double_eq(expected, result);
}

MU_TEST_SUITE(test_normalize) {
    MU_RUN_TEST(test_normalize_tuple);
    MU_RUN_TEST(test_normalize_vector);
}
