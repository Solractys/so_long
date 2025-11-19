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

void	destroy_images(t_game *game)
{
	int	i;

	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->player_img[0])
	{
		i = 0;
		while (i < 4)
		{
			if (game->player_img[i])
				mlx_destroy_image(game->mlx, game->player_img[i]);
			i++;
		}
	}
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
}
