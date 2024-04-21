#include <minirt.h>

MU_TEST(test_sphere_creation) {
    t_point *origin = new_point(0, 0, 0);
    float radius = 1;
    t_sphere *sphere = new_sphere(origin, radius);

    mu_assert(
        tuplecmp(sphere->origin, origin) == 0 && sphere->radius == radius,
        "Sphere origin should be at (0, 0, 0) and should have a radius of 1"
    );

    mu_assert(
        matrixcmp(sphere->transform, new_identity()) == 0,
        "Spheres should have identity matrix as default value to transform property"
    );
}

MU_TEST(test_should_change_transform_matrix_of_sphere) {
    t_sphere    *sphere = new_sphere(new_point(0, 0, 0), 1);
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