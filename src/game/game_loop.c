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

int	game_loop(t_game *game)
{
	if (!game || !game->map || !game->map->map)
		return (0);
	if (game->animation_timer < 0)
		game->animation_timer = 0;
	if (game->grass_frame < 0 || game->grass_frame >= 6)
		game->grass_frame = 0;
	if (game->collectible_frame < 0 || game->collectible_frame >= 6)
		game->collectible_frame = 0;
	if (game->player_frame < 0 || game->player_frame >= 6)
		game->player_frame = 0;
	game->animation_timer++;
	if (game->animation_timer >= 4000)
	{
		game->animation_timer = 0;
		game->grass_frame = (game->grass_frame + 1) % 6;
		game->collectible_frame = (game->collectible_frame + 1) % 6;
		game->player_frame = (game->player_frame + 1) % 6;
		render_map(game);
	}
	return (0);
}

