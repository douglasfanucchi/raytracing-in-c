MU_TEST(test_vector_creation) {
    t_vector *vector = new_vector(5, 1.5, -3);

    mu_assert(vector[3] == 0, "vector must have last parameter as 0");
}

MU_TEST_SUITE(test_vectors) {
    MU_RUN_TEST(test_vector_creation);
}