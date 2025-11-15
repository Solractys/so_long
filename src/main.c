#include "../minilibx/mlx.h"
#include "../includes/ft_printf/ft_printf.h"
#include "../includes/map.h"

int main(void)
{
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    if (!mlx)
    {
        ft_printf("Error: mlx_init failed\n");
        return (1);
    }
    win = mlx_new_window(mlx, 100, 100, "Hello, World!");
    if (!win)
    {
        ft_printf("Error: mlx_new_window failed\n");
        mlx_destroy_display(mlx);
        free(mlx);
        return (1);
    }
    ft_printf("Window created successfully!\n");
    t_map *map;
    map = read_map("maps/map.ber");
    if (!map)
    {
        ft_printf("Error: read_map failed\n");
        mlx_destroy_window(mlx, win);
        mlx_destroy_display(mlx);
        free(mlx);
        return (1);
    }
    int x;
    int y;
    y = 0;
    x = 0;
    while (map->map[y])
    {
        x = 0;
        while (map->map[y][x])
        {
            ft_printf("%c", map->map[y][x]);
            x++;
        }
        ft_printf("\n");
        y++;
    }
    mlx_loop(mlx);
    return (0);
}