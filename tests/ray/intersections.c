MU_TEST(test_should_create_a_intersection) {
    t_sphere *sphere = new_sphere(new_point(0, 0, 0), 1);
    t_intersection *intersection = new_intersection(5, sphere);

    mu_assert(
        intersection->object == sphere && intersection->t == 5,
        "Intersection's object should be the sphere and the distance should be 5"
    );
}

MU_TEST_SUITE(test_intersections) {
    MU_RUN_TEST(test_should_create_a_intersection);
}