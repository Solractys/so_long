/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:30:35 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 00:30:35 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/game.h"
#include "../../includes/render.h"
#include "../../includes/intro.h"
#include <sys/time.h>

void	game_init(t_game *game, t_map *map)
{
	int	i;
	int	j;

	intro_animation();
	game->map = map;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * 32, map->height * 32,
			"The Legend of Zelda: So Long But So Nice");
	game->moves = 0;
	game->player_direction = 1;
	game->wall_img = NULL;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 6)
		{
			game->player_img[i][j] = NULL;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 6)
	{
		game->floor_img[i] = NULL;
		game->collectible_img[i] = NULL;
		i++;
	}
	game->grass_frame = 0;
	game->collectible_frame = 0;
	game->player_frame = 0;
	game->last_frame_time = 0;
	game->exit_status = 0;
	load_images(game);
	load_player_images(game);
	render_map(game);
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
