/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:15:26 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 01:15:26 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/render.h"
#include <sys/time.h>

static long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	game_loop(t_game *game)
{
	long	current_time;
	long	elapsed_time;

	if (!game || !game->map || !game->map->map)
		return (0);
	if (game->grass_frame < 0 || game->grass_frame >= 6)
		game->grass_frame = 0;
	if (game->collectible_frame < 0 || game->collectible_frame >= 6)
		game->collectible_frame = 0;
	if (game->player_frame < 0 || game->player_frame >= 6)
		game->player_frame = 0;
	current_time = get_time_ms();
	elapsed_time = current_time - game->last_frame_time;
	if (elapsed_time >= 150)
	{
		game->last_frame_time = current_time;
		game->grass_frame = (game->grass_frame + 1) % 6;
		game->collectible_frame = (game->collectible_frame + 1) % 6;
		game->player_frame = (game->player_frame + 1) % 6;
		render_map(game);
	}
	return (0);
}

