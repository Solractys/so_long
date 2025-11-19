/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:15:26 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 01:15:26 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	load_images(t_game *game)
{
	int	width;
	int	height;

	width = 32;
	height = 32;
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "src/assets/wall.xpm",
			&width, &height);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "src/assets/floor.xpm",
			&width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "src/assets/player.xpm",
			&width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "src/assets/exit.xpm",
			&width, &height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"src/assets/collectible.xpm", &width, &height);
}
