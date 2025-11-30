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
	char	tile;
	int		grass_idx;
	int		player_idx;
	int		collectible_idx;

	if (!game || !game->map || !game->map->map)
		return ;
	if (y / 32 >= game->map->height || x / 32 >= game->map->width)
		return ;
	tile = game->map->map[y / 32][x / 32];
	grass_idx = game->grass_frame % 6;
	player_idx = game->player_frame % 6;
	collectible_idx = game->collectible_frame % 6;
	if (tile == '1' && game->wall_img)
		mlx_put_image_to_window(game->mlx, win, game->wall_img, x, y);
	else if (tile == '0' && grass_idx >= 0 && grass_idx < 6
		&& game->floor_img[grass_idx])
		mlx_put_image_to_window(game->mlx, win,
			game->floor_img[grass_idx], x, y);
	else if (tile == 'P' && game->player_direction >= 0
		&& game->player_direction < 4 && player_idx >= 0 && player_idx < 6
		&& game->player_img[game->player_direction][player_idx])
	{
		mlx_put_image_to_window(game->mlx, win,
			game->player_img[game->player_direction][player_idx], x, y);
	}
	else if (tile == 'E' && game->exit_status >= 0 && game->exit_status < 2
		&& game->exit_img[game->exit_status])
	{
		mlx_put_image_to_window(game->mlx, win,
			game->exit_img[game->exit_status], x, y);
	}
	else if (tile == 'C' && collectible_idx >= 0 && collectible_idx < 6
		&& game->collectible_img[collectible_idx])
	{
		mlx_put_image_to_window(game->mlx, win,
			game->collectible_img[collectible_idx], x, y);
	}
}
