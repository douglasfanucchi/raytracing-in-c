MU_TEST(test_should_translate_a_ray) {
    t_ray       *ray = new_ray(new_point(1, 2, 3), new_vector(0, 1, 0));
    t_ray       *result = transform(ray, translate(3, 4, 5));
    t_ray       *expected = new_ray(new_point(4, 6, 8), new_vector(0, 1, 0));

    mu_assert(
        tuplecmp(expected->origin, result->origin) == 0,
        "Translated ray's origin should be at (4, 6, 8)"
    );

    mu_assert(
        tuplecmp(expected->direction, result->direction) == 0,
        "Translated ray's direction should be (0, 1, 0)"
    );
}

MU_TEST(test_should_scale_a_ray) {
    t_ray   *ray = new_ray(new_point(1, 2, 3), new_vector(0, 1, 0));
    t_ray   *result = transform(ray, scale(2, 3, 4));
    t_ray   *expected = new_ray(new_point(2, 6, 12), new_vector(0, 3, 0));

    mu_assert(
        tuplecmp(expected->origin, result->origin) == 0,
        "Scaled ray's origin should be at (2, 3, 4)"
    );

    mu_assert(
        tuplecmp(expected->direction, result->direction) == 0,
        "Scaled ray should have direction (0, 3, 0)"
    );
}

MU_TEST_SUITE(test_transform_rays) {
    MU_RUN_TEST(test_should_translate_a_ray);
    MU_RUN_TEST(test_should_scale_a_ray);
}