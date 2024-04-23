#include <stdio.h>
#include <minirt.h>

float   f(float x)
{
    return x/300 - 1;
}

int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 600, 600, "alo biel");

    int         color = 0xFF0000;
    t_sphere    *sphere = new_sphere();
    set_transform(sphere, translate(0, 0, 100));

    for(int i = 0; i <= 600; i++) {
        for(int j = 0; j <= 600; j++) {
            float x = f(i);
            float y = -f(j);
            float z = 1;

            t_ray   *ray = new_ray(
                new_point(0, 0, 0),
                normalize(new_vector(x, y, z))
            );
            t_list **intersections = intersect(sphere, ray);
            if(ft_lstsize(*intersections) > 0) {
                t_intersection *intersection = hit(intersections);
                mlx_pixel_put(mlx, window, i, j, color / intersection->t);
            }
        }
    }
    mlx_loop(mlx);
    return 0;
}
