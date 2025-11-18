#include "../../includes/so_long.h"

void    load_images(t_game *game, void *mlx)
{
    game->wall_img = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", 0, 0);
    game->floor_img = mlx_xpm_file_to_image(mlx, "assets/floor.xpm", 0, 0);
    game->player_img = mlx_xpm_file_to_image(mlx, "assets/player.xpm", 0, 0);
    game->exit_img = mlx_xpm_file_to_image(mlx, "assets/exit.xpm", 0, 0);
    game->collectible_img = mlx_xpm_file_to_image(mlx, "assets/collectible.xpm", 0, 0);
}