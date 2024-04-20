#include <minirt.h>

MU_TEST(test_sphere_creation) {
    t_point *origin = new_point(0, 0, 0);
    float radius = 1;
    t_sphere *sphere = new_sphere(origin, radius);

    mu_assert(
        tuplecmp(sphere->origin, origin) == 0 && sphere->radius == radius,
        "Sphere origin should be at (0, 0, 0) and should have a radius of 1"
    );
}

MU_TEST_SUITE(test_sphere) {
    MU_RUN_TEST(test_sphere_creation);
}