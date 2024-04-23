#include <minirt.h>

MU_TEST(test_sphere_creation) {
    t_sphere *sphere = new_sphere();
    t_color  *default_color = new_color(1, 1, 1);

    mu_assert(
        tuplecmp(default_color, sphere->material->color) == 0,
        "Sphere's default color should be (1, 1, 1)"
    );
    mu_assert_double_eq(0.1, sphere->material->ambient);
    mu_assert_double_eq(0.9, sphere->material->diffuse);
    mu_assert_double_eq(0.9, sphere->material->specular);
    mu_assert_double_eq(200, sphere->material->shininess);

    mu_assert(
        matrixcmp(sphere->transform, new_identity()) == 0,
        "Spheres should have identity matrix as default value to transform property"
    );
}

MU_TEST(test_should_change_sphere_material) {
    t_color     *color = new_color(0.5, 0.5, 0.5);
    t_sphere    *sphere = new_sphere();
    t_material  *material = new_material(color, 0.2, 0.7, 0.7, 10);
    set_material(sphere, material);

    mu_assert(
        tuplecmp(material->color, sphere->material->color) == 0,
        "Sphere's color should've changed to (0.5, 0.5, 0.5)"
    );

    mu_assert_double_eq(0.2, sphere->material->ambient);
    mu_assert_double_eq(0.7, sphere->material->diffuse);
    mu_assert_double_eq(0.7, sphere->material->specular);
    mu_assert_double_eq(10, sphere->material->shininess);
}

MU_TEST(test_should_change_transform_matrix_of_sphere) {
    t_sphere    *sphere = new_sphere();
    t_matrix    *matrix = translate(1, 2, 3);
    set_transform(sphere, matrix);

    mu_assert(
        matrixcmp(matrix, sphere->transform) == 0,
        "Transform matrix should be changed to translate(1, 2, 3)"
    );
}

MU_TEST_SUITE(test_sphere) {
    MU_RUN_TEST(test_sphere_creation);
    MU_RUN_TEST(test_should_change_sphere_material);
    MU_RUN_TEST(test_should_change_transform_matrix_of_sphere);
}