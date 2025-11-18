#include "../../includes/so_long.h"

void    draw_tile(t_game *game, void *mlx, void *win, int x, int y)
{
    if (game->map->map[y / 32][x / 32] == '1')
        mlx_put_image_to_window(mlx, win, game->wall_img, x, y);
    else if (game->map->map[y / 32][x / 32] == '0')
        mlx_put_image_to_window(mlx, win, game->floor_img, x, y);
    else if (game->map->map[y / 32][x / 32] == 'P')
        mlx_put_image_to_window(mlx, win, game->floor_img, x, y);
    else if (game->map->map[y / 32][x / 32] == 'E')
        mlx_put_image_to_window(mlx, win, game->exit_img, x, y);
    else if (game->map->map[y / 32][x / 32] == 'C')
        mlx_put_image_to_window(mlx, win, game->collectible_img, x, y);
}