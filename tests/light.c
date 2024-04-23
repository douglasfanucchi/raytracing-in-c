MU_TEST(test_should_create_light_instance) {
    t_color *intensity = new_color(1, 1, 1);
    t_point *position = new_point(0, 0, 0);
    t_light *result = new_light(intensity, position);

    mu_assert(
        tuplecmp(intensity, result->intensity) == 0 &&
        tuplecmp(position, result->position) == 0,
        "Light source should have intensity (1, 1, 1) and be positioned at (0, 0, 0)"
    );
}

MU_TEST_SUITE(test_light) {
    MU_RUN_TEST(test_should_create_light_instance);
}