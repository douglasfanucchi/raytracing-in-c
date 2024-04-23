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

MU_TEST_SUITE(test_material) {
    MU_RUN_TEST(test_should_create_a_material_instance);
}
