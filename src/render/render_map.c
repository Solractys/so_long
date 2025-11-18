#include "../../includes/so_long.h"
#include "../../includes/render.h"

void render_map(t_game *game)
{
    int x;
    int y;

    y = 0;
    load_images(game);
    while (y < game->map->height * 32)
    {
        x = 0;
        while (x < game->map->width * 32)
        {
            draw_tile(game, game->mlx, game->win, x, y);
            x += 32;
        }
        y += 32;
    }
}