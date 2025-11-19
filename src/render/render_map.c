/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:47:35 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 00:47:35 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/render.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	load_images(game);
	while (y < game->map->height * 32)
	{
		x = 0;
		while (x < game->map->width * 32)
		{
			draw_tile(game, game->win, x, y);
			x += 32;
		}
		y += 32;
	}
}
