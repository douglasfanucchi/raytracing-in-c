MU_TEST(test_should_create_a_material_instance) {
    t_color *color = new_color(0.5, 0.5, 0.5);
    float       ambient = 0.1;
    float       diffuse = 0.9;
    float       specular = 0.9;
    float       shininess = 200;
    t_material  *result = new_material(color, ambient, diffuse, specular, shininess);

    mu_assert(
        tuplecmp(color, result->color) == 0,
        "Material color should be (0.5, 0.5, 0.5)"
    );
    mu_assert_double_eq(ambient, result->ambient);
    mu_assert_double_eq(diffuse, result->diffuse);
    mu_assert_double_eq(specular, result->specular);
    mu_assert_double_eq(shininess, result->shininess);
}

MU_TEST(test_should_return_lighting_at_its_full_strength) {
    t_material  *material = new_material(new_color(1, 1, 1), 0.1, 0.9, 0.9, 200);
    t_point     *iluminated_position = new_point(0, 0, 0);
    t_vector    *eyev = new_vector(0, 0, -1);
    t_vector    *normalv = new_vector(0, 0, -1);
    t_light     *light = new_light(new_color(1, 1, 1), new_point(0, 0, -10));
    t_color     *result = lighting(material, light, iluminated_position, eyev, normalv);
    t_color     *expected = new_color(1.9, 1.9, 1.9);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "lighting should return color (1.9, 1.9, 1.9)"
    );
}

MU_TEST(test_should_return_lighting_without_specular_value_when_eye_45_degrees_offset_y_axis) {
    t_material  *material = new_material(new_color(1, 1, 1), 0.1, 0.9, 0.9, 200);
    t_point     *iluminated_position = new_point(0, 0, 0);
    t_vector    *eyev = new_vector(0, sqrt(2)/2, -sqrt(2)/2);
    t_vector    *normalv = new_vector(0, 0, -1);
    t_light     *light = new_light(new_color(1, 1, 1), new_point(0, 0, -10));
    t_color     *result = lighting(material, light, iluminated_position, eyev, normalv);
    t_color     *expected = new_color(1.0, 1.0, 1.0);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "lighting should return color (1.0, 1.0, 1.0)"
    );
}

MU_TEST(test_should_return_lighting_with_lower_diffuse_and_without_specular_when_light_source_45_degrees_offset_y_axis) {
    t_material  *material = new_material(new_color(1, 1, 1), 0.1, 0.9, 0.9, 200);
    t_point     *iluminated_position = new_point(0, 0, 0);
    t_vector    *eyev = new_vector(0, 0, -1);
    t_vector    *normalv = new_vector(0, 0, -1);
    t_light     *light = new_light(new_color(1, 1, 1), new_point(0, 10, -10));
    t_color     *result = lighting(material, light, iluminated_position, eyev, normalv);
    t_color     *expected = new_color(0.7364, 0.7364, 0.7364);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "lighting should return color (0.7364, 0.7364, 0.7364)"
    );
}

MU_TEST(test_should_return_lighting_with_lower_diffuse_but_with_full_specular_when_eye_is_on_reflection_vector_path) {
    t_material  *material = new_material(new_color(1, 1, 1), 0.1, 0.9, 0.9, 200);
    t_point     *iluminated_position = new_point(0, 0, 0);
    t_vector    *eyev = new_vector(0, -sqrt(2)/2, -sqrt(2)/2);
    t_vector    *normalv = new_vector(0, 0, -1);
    t_light     *light = new_light(new_color(1, 1, 1), new_point(0, 10, -10));
    t_color     *result = lighting(material, light, iluminated_position, eyev, normalv);
    t_color     *expected = new_color(1.636385, 1.636385, 1.636385);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "lighting should return color (1.636385, 1.636385, 1.636385)"
    );
}

MU_TEST(test_should_return_lighting_with_no_diffuse_and_specular_when_light_source_is_behind_the_iluminated_point) {
    t_material  *material = new_material(new_color(1, 1, 1), 0.1, 0.9, 0.9, 200);
    t_point     *iluminated_position = new_point(0, 0, 0);
    t_vector    *eyev = new_vector(0, 0, -1);
    t_vector    *normalv = new_vector(0, 0, -1);
    t_light     *light = new_light(new_color(1, 1, 1), new_point(0, 0, 10));
    t_color     *result = lighting(material, light, iluminated_position, eyev, normalv);
    t_color     *expected = new_color(0.1, 0.1, 0.1);

    mu_assert(
        tuplecmp(expected, result) == 0,
        "lighting should return color (0.1, 0.1, 0.1)"
    );
}

MU_TEST_SUITE(test_material) {
    MU_RUN_TEST(test_should_create_a_material_instance);
    MU_RUN_TEST(test_should_return_lighting_at_its_full_strength);
    MU_RUN_TEST(test_should_return_lighting_without_specular_value_when_eye_45_degrees_offset_y_axis);
    MU_RUN_TEST(test_should_return_lighting_with_lower_diffuse_and_without_specular_when_light_source_45_degrees_offset_y_axis);
    MU_RUN_TEST(test_should_return_lighting_with_lower_diffuse_but_with_full_specular_when_eye_is_on_reflection_vector_path);
    MU_RUN_TEST(test_should_return_lighting_with_no_diffuse_and_specular_when_light_source_is_behind_the_iluminated_point);
}
