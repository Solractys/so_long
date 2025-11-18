#include "../../includes/game.h"
#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/render.h"

int exit_game(t_game *game)
{
    free_map(game->map);
    destroy_images(game);
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}
