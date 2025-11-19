/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:14:01 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 01:14:01 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/render.h"

static void	destroy_player_images(t_game *game)
{
	int	i;
	int	j;

	if (game->player_img[0][0])
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 6)
			{
				if (game->player_img[i][j])
					mlx_destroy_image(game->mlx, game->player_img[i][j]);
				j++;
			}
			i++;
		}
	}
}

static void	destroy_exit_images(t_game *game)
{
	int	i;

	if (game->exit_img[0])
	{
		i = 0;
		while (i < 2)
		{
			if (game->exit_img[i])
				mlx_destroy_image(game->mlx, game->exit_img[i]);
			i++;
		}
	}
}

static void	destroy_floor_images(t_game *game)
{
	int	i;

	if (game->floor_img[0])
	{
		i = 0;
		while (i < 6)
		{
			if (game->floor_img[i])
				mlx_destroy_image(game->mlx, game->floor_img[i]);
			i++;
		}
	}
}

static void	destroy_collectible_images(t_game *game)
{
	int	i;

	if (game->collectible_img[0])
	{
		i = 0;
		while (i < 6)
		{
			if (game->collectible_img[i])
				mlx_destroy_image(game->mlx, game->collectible_img[i]);
			i++;
		}
	}
}

void	destroy_images(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img[0])
		destroy_floor_images(game);
	if (game->player_img[0][0])
		destroy_player_images(game);
	if (game->exit_img[0])
		destroy_exit_images(game);
	if (game->collectible_img[0])
		destroy_collectible_images(game);
}
