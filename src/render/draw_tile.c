/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:12:39 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 01:12:39 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_tile(t_game *game, void *win, int x, int y)
{
	if (game->map->map[y / 32][x / 32] == '1')
		mlx_put_image_to_window(game->mlx, win, game->wall_img, x, y);
	else if (game->map->map[y / 32][x / 32] == '0')
		mlx_put_image_to_window(game->mlx, win, game->floor_img, x, y);
	else if (game->map->map[y / 32][x / 32] == 'P')
	{
		mlx_put_image_to_window(game->mlx, win,
			game->player_img[game->player_direction], x, y);
	}
	else if (game->map->map[y / 32][x / 32] == 'E')
	{
		mlx_put_image_to_window(game->mlx, win,
			game->exit_img[game->exit_status], x, y);
	}
	else if (game->map->map[y / 32][x / 32] == 'C')
	{
		mlx_put_image_to_window(game->mlx, win,
			game->collectible_img, x, y);
	}
}
