#include "../../includes/render.h"

void load_images(t_game *game)
{
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", 32, 32);
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", 32, 32);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", 32, 32);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", 32, 32);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", 32, 32);
}