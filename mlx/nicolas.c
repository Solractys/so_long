#include "mlx.h"

typedef struct s_data {
    void *img;
    char *addr;
    int bpp;
    int line_w;
    int endian;
}               t_data;

void change_pixel_color(t_data *img, int x,int y,int color)
{
    char *dst;
    dst = img->addr + (y * img->line_w + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}


int main(void)
{
    void *mlx;
    void *mlx_window;
    t_data mlx_image;
    int y = 0;
    int x = 0;
    void *img;
    char *relative_path = "./zeldaloho.xpm";
    int img_w;
    int img_h;

    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 256, 224, "Futuro Zelda");
    mlx_image.img = mlx_new_image(mlx, 256, 224);
    mlx_image.addr = mlx_get_data_addr(mlx_image.img, &mlx_image.bpp, &mlx_image.line_w, &mlx_image.endian);
    while (x <= 255 && !(y == 224))
    {
        if (x == 255)
        {
            y++;
            x = 0;
        }
        change_pixel_color(&mlx_image, x, y, 0xFF00FF00);
        x++;
    }
    img = mlx_xpm_file_to_image(mlx, relative_path, &img_w, &img_h);
    mlx_put_image_to_window(mlx, mlx_window, mlx_image.img, 0, 0);
    mlx_put_image_to_window(mlx, mlx_window, img, 20, 20);
    mlx_loop(mlx);
    return (0);
}

