#include <minirt.h>

MU_TEST(test_ray_creation) {
    t_point *origin = new_point(0, 0, 0);
    t_vector *direction = new_vector(1, 1, 0);
    t_ray *ray = new_ray(origin, direction);

    mu_assert(
        tuplecmp(ray->origin, origin) == 0,
        "Ray origin should be a point at (0, 0, 0)"
    );

    mu_assert(
        tuplecmp(ray->direction, direction) == 0,
        "Ray direction should be a vector with components (1, 1, 0)"
    );
}

MU_TEST_SUITE(test_ray) {
    MU_RUN_TEST(test_ray_creation);
}