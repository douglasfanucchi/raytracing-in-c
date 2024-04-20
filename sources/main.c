#include <stdio.h>
#include <minirt.h>

float *points(int x, int y)
{
    float *result = malloc(sizeof(float) * 3);
    result[0] = 800/2 + x;
    result[1] = 600/2 - y;
    result[2] = 0;
    return result;
}

int main()
{
    void *mlx;
    void *window;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "alo biel");

    int color = 0xFFFFFF;
    t_matrix *transformation = rotatez(M_PI_2/300);

    t_point *p = new_point(0, 300, 0);
    for(int i = 0; i < 1200; i++) {
        float *coordinates = points(p[0], p[1]);
        printf("%f %f\n", p[0], p[1]);
        mlx_pixel_put(mlx, window, coordinates[0], coordinates[1], color);
        p = matrixtuplemultiply(transformation, p);
    }

    mlx_loop(mlx);
    return 0;
}
