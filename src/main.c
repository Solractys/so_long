#include "../minilibx/mlx.h"
#include <stdio.h>

int main(void)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    if (!mlx)
    {
        printf("Error: mlx_init failed\n");
        return (1);
    }
    win = mlx_new_window(mlx, 100, 100, "Hello, World!");
    if (!win)
    {
        printf("Error: mlx_new_window failed\n");
        return (1);
    }
    mlx_loop(mlx);
    return (0);
}