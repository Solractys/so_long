#include "../../includes/render.h"

void load_images(t_game *game)
{
    int width;
    int height;

    width = 32;
    height = 32;
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "src/assets/wall.xpm", &width, &height);
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "src/assets/floor.xpm", &width, &height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "src/assets/player.xpm", &width, &height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "src/assets/exit.xpm", &width, &height);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "src/assets/collectible.xpm", &width, &height);
}
