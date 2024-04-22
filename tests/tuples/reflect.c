MU_TEST(test_should_reflect_a_vector_that_hits_with_45_degrees_the_normal) {
    t_vector    *vector = new_vector(-1, -1, 0);
    t_vector    *normal = new_vector(0, 1, 0);
    t_vector    *result = reflect(vector, normal);
    t_vector    *expected = new_vector(-1, 1, 0);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Reflected vector should be (-1, 1, 0)"
    );
}

MU_TEST(test_vector_should_be_horizontally_reflected_if_normal_45_degrees_slanted)
{
    t_vector    *vector = new_vector(0, -1, 0);
    t_vector    *normal = new_vector(sqrt(2)/2, sqrt(2)/2, 0);
    t_vector    *result = reflect(vector, normal);
    t_vector    *expected = new_vector(1, 0, 0);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Reflected vector should be (-1, 0, 0)"
    );
}

MU_TEST_SUITE(test_reflect) {
    MU_RUN_TEST(test_should_reflect_a_vector_that_hits_with_45_degrees_the_normal);
    MU_RUN_TEST(test_vector_should_be_horizontally_reflected_if_normal_45_degrees_slanted);
}