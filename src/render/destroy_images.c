#include "../../includes/so_long.h"

void destroy_images(t_game *game, void *mlx)
{
    if (game->wall_img)
        mlx_destroy_image(mlx, game->wall_img);
    if (game->floor_img)
        mlx_destroy_image(mlx, game->floor_img);
    if (game->player_img)
        mlx_destroy_image(mlx, game->player_img);
    if (game->exit_img)
        mlx_destroy_image(mlx, game->exit_img);
    if (game->collectible_img)
        mlx_destroy_image(mlx, game->collectible_img);
}