#include <minirt.h>

MU_TEST(test_sphere_creation) {
    t_sphere *sphere = new_sphere();

    mu_assert(
        matrixcmp(sphere->transform, new_identity()) == 0,
        "Spheres should have identity matrix as default value to transform property"
    );
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
    MU_RUN_TEST(test_should_change_transform_matrix_of_sphere);
}