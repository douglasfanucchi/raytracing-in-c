#include <stdio.h>
#include <minirt.h>

float   f(float x)
{
    return x/300 - 1;
}

int rgbToHex(float r, float g, float b) {
    int red = (int)(r * 255);
    int green = (int)(g * 255);
    int blue = (int)(b * 255);
    return (red << 16) + (green << 8) + blue;
}

int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 600, 600, "alo biel");

    t_sphere    *sphere = new_sphere();
    set_transform(sphere, translate(0, 0, 2));
    sphere->material->color = new_color(0.6, 0.3, 0.0);
    t_light     *light = new_light(new_color(1, 1, 1), new_point(0.3, 0.4, 0));
    sphere->material->specular = 0.6;
    sphere->material->shininess = 3.6;
    //set_transform(sphere, scale(1, 0.5, 1));

    for(int i = 0; i <= 600; i++) {
        for(int j = 0; j <= 600; j++) {
            float x = f(i);
            float y = -f(j);
            float z = 1;

            t_ray       *ray = new_ray(
                new_point(0, 0, 0),
                normalize(new_vector(x, y, z))
            );
            t_list      **intersections = intersect(sphere, ray);
            if(ft_lstsize(*intersections) > 0) {
                t_intersection *intersection = hit(intersections);
                t_vector    *normal = normal_at(
                    intersection->object,
                    position(ray, intersection->t)
                );
                t_vector    *eyev = tuplemultiply(ray->direction, -1);
                t_color     *color = lighting(
                    ((t_sphere *)intersection->object)->material,
                    light,
                    position(ray, intersection->t),
                    eyev,
                    normal
                );
                mlx_pixel_put(mlx, window, i, j, rgbToHex(color[0], color[1], color[2]));
            } else {
	    	mlx_pixel_put(mlx, window, i, j, rgbToHex(0.00392156862745098, 0.26666666666666666, 0.29411764705882354));
	    }
        }
    }
    mlx_loop(mlx);
    return 0;
}
