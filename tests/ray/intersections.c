MU_TEST(test_should_create_a_intersection) {
    t_sphere *sphere = new_sphere(new_point(0, 0, 0), 1);
    t_intersection *intersection = new_intersection(5, sphere);

    mu_assert(
        intersection->object == sphere && intersection->t == 5,
        "Intersection's object should be the sphere and the distance should be 5"
    );
}

MU_TEST(test_ray_should_intersect_sphere_at_two_positive_distances) {
    t_ray           *ray = new_ray(new_point(-5, 0, 0), new_vector(1, 0, 0));
    t_sphere        *sphere = new_sphere(new_point(0, 0, 0), 1);
    t_list          **intersections = intersect(sphere, ray);
    t_intersection  *intersection = (*intersections)->content;
    mu_assert_double_eq(intersection->t, 4);

    intersection = (*intersections)->next->content;
    mu_assert_double_eq(intersection->t, 6);
}

MU_TEST(test_ray_should_be_tangent_to_sphere) {
    t_ray           *ray = new_ray(new_point(-5, 1, 0), new_vector(1, 0, 0));
    t_sphere        *sphere = new_sphere(new_point(0, 0, 0), 1);
    t_list          **intersections = intersect(sphere, ray);
    t_intersection  *intersection = (*intersections)->content;
    mu_assert_double_eq(intersection->t, 5);
    
    intersection = (*intersections)->next->content;
    mu_assert_double_eq(intersection->t, 5);
}

MU_TEST(test_ray_should_not_intersect_sphere) {
    t_ray       *ray = new_ray(new_point(-5, 10, 0), new_vector(1, 0, 0));
    t_sphere    *sphere = new_sphere(new_point(0, 0, 0), 1);
    t_list      **intersections = intersect(sphere, ray);

    mu_assert(
        *intersections == NULL,
        "Ray with origin (-5, 2, 0) should completely miss sphere centered on (0, 0, 0) and radius 1"
    );
}

MU_TEST(test_ray_should_intersect_sphere_at_a_positive_and_negative_distances) {
    t_ray           *ray = new_ray(new_point(0, 0, 0), new_vector(1, 0, 0));
    t_sphere        *sphere = new_sphere(new_point(0, 0, 0), 1);
    t_list          **intersections = intersect(sphere, ray);
    t_intersection  *intersection = (*intersections)->content;
    mu_assert_double_eq(intersection->t, -1);

    intersection = (*intersections)->next->content;
    mu_assert_double_eq(intersection->t, 1);
}

MU_TEST(test_ray_should_intersect_sphere_at_negative_distances) {
    t_ray           *ray = new_ray(new_point(5, 0, 0), new_vector(1, 0, 0));
    t_sphere        *sphere = new_sphere(new_point(0, 0, 0), 1);
    t_list          **intersections = intersect(sphere, ray);
    t_intersection  *intersection = (*intersections)->content;
    mu_assert_double_eq(intersection->t, -6);

    intersection = (*intersections)->next->content;
    mu_assert_double_eq(intersection->t, -4);
}

MU_TEST_SUITE(test_intersections) {
    MU_RUN_TEST(test_should_create_a_intersection);
    MU_RUN_TEST(test_ray_should_intersect_sphere_at_two_positive_distances);
    MU_RUN_TEST(test_ray_should_be_tangent_to_sphere);
    MU_RUN_TEST(test_ray_should_not_intersect_sphere);
    MU_RUN_TEST(test_ray_should_intersect_sphere_at_a_positive_and_negative_distances);
    MU_RUN_TEST(test_ray_should_intersect_sphere_at_negative_distances);
}