#include "../minilibx/mlx.h"
#include "../includes/ft_printf/ft_printf.h"
#include "../includes/map.h"

int check_file_extension_ber(const char *filename)
{
    size_t len = 0;

    while (filename[len] != '\0')
        len++;
    if (len < 4)
        return (0);
    return (filename[len - 4] == '.' &&
            filename[len - 3] == 'b' &&
            filename[len - 2] == 'e' &&
            filename[len - 1] == 'r');
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }
    void    *mlx;
    void    *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 100, 100, "Hello, World!");
    if (!check_file_extension_ber(argv[1]))
    {
        ft_printf("Error: Invalid file extension. Expected .ber\n");
        return (1);
    }
    t_map *map;
    map = read_map(argv[1]);
    if (!validate_map(map))
    {
        ft_printf("Error: Invalid map structure.\n");
        return (1);
    }
    // show map info for testing
    ft_printf("Map Width: %d, Height: %d\n", map->width, map->height);
    ft_printf("Player Position: (%d, %d)\n", map->player_x, map->player_y);
    ft_printf("Exit Position: (%d, %d)\n", map->exit_x, map->exit_y);
    ft_printf("Collectibles: %d\n", map->collectibles);
    free_map(map);
    mlx_loop(mlx);
    mlx_destroy_window(mlx, win);
    mlx_destroy_display(mlx);
    free(mlx);
    return (0);
}