#include "../includes/so_long.h"
#include "../includes/map.h"
#include "../includes/game.h"
#include "../includes/render.h"

void    game_init(t_game *game, t_map *map)
{
    game->map = map;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, map->width * 32, map->height * 32, "The Legend of Zelda: So Long But So Nice");
    game->moves = 0;
    load_images(game);
    render_map(game);
    mlx_key_hook(game->win, handle_keypress, game);
    mlx_hook(game->win, 17, 0, exit_game, game);
    mlx_loop(game->mlx);
}
