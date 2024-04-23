MU_TEST(test_should_return_a_normal_at_x_axis) {
    t_sphere    *sphere = new_sphere();
    t_vector    *result = normal_at(sphere, new_point(1, 0, 0));
    t_vector    *expected = new_vector(1, 0, 0);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Normal vector should be (1, 0, 0)"
    );
}

MU_TEST(test_should_return_a_normal_at_y_axis) {
    t_sphere    *sphere = new_sphere();
    t_vector    *result = normal_at(sphere, new_point(0, 1, 0));
    t_vector    *expected = new_vector(0, 1, 0);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Normal vector should be (0, 1, 0)"
    );
}

MU_TEST(test_should_return_a_normal_at_z_axis) {
    t_sphere    *sphere = new_sphere();
    t_vector    *result = normal_at(sphere, new_point(0, 0, 1));
    t_vector    *expected = new_vector(0, 0, 1);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Normal vector should be (0, 0, 1)"
    );
}

MU_TEST(test_should_return_a_non_axial_vector_normal) {
    float       sqrt3_3 = sqrt(3)/3;
    t_sphere    *sphere = new_sphere();
    t_vector    *result = normal_at(sphere, new_point(sqrt3_3, sqrt3_3, sqrt3_3));
    t_vector    *expected = new_vector(sqrt3_3, sqrt3_3, sqrt3_3);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Normal vector should be (√3/3, √3/3, √3/3)"
    );
}

MU_TEST(test_should_return_a_normal_computed_on_a_translated_sphere) {
    t_sphere    *sphere = new_sphere();
    set_transform(sphere, translate(0, 1, 0));
    t_vector    *result = normal_at(sphere, new_point(0, 1.70711, -0.70711));
    t_vector    *expected = new_vector(0, 0.70711, -0.70711);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Normal vector should (0, 0.70711, -0.70711)"
    );
}

MU_TEST(test_should_return_a_normal_computed_on_a_rotated_scaled_sphere) {
    float       sqrt2_2 = sqrt(2)/2;
    t_sphere    *sphere = new_sphere();
    set_transform(sphere, scale(1, 0.5, 1));
    set_transform(sphere, rotatez(M_PI/5));
    t_vector    *result = normal_at(sphere, new_point(0, sqrt2_2, -sqrt2_2));
    t_vector    *expected = new_vector(0, 0.97014, -0.24254);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "Normal vector should be (0, 0.97014, -0.24254)"
    );
}

MU_TEST_SUITE(test_normal_computation) {
    MU_RUN_TEST(test_should_return_a_normal_at_x_axis);
    MU_RUN_TEST(test_should_return_a_normal_at_y_axis);
    MU_RUN_TEST(test_should_return_a_normal_at_z_axis);
    MU_RUN_TEST(test_should_return_a_non_axial_vector_normal);
    MU_RUN_TEST(test_should_return_a_normal_computed_on_a_translated_sphere);
    MU_RUN_TEST(test_should_return_a_normal_computed_on_a_rotated_scaled_sphere);
}