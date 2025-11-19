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
#include "../../includes/ft_printf/ft_printf.h"

void	load_player_images(t_game *game)
{
	int	w;
	int	h;

	w = 32;
	h = 32;
	if (game->player_img[0] && game->player_img[1] && game->player_img[2]
		&& game->player_img[3])
		return ;
	game->player_img[0] = mlx_xpm_file_to_image(game->mlx,
			"src/assets/player/up/PLAYER_U1.xpm", &w, &h);
	game->player_img[1] = mlx_xpm_file_to_image(game->mlx,
			"src/assets/player/down/PLAYER_D1.xpm", &w, &h);
	game->player_img[2] = mlx_xpm_file_to_image(game->mlx,
			"src/assets/player/left/PLAYER_L1.xpm", &w, &h);
	game->player_img[3] = mlx_xpm_file_to_image(game->mlx,
			"src/assets/player/right/PLAYER_R1.xpm", &w, &h);
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	w = 32;
	h = 32;
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"src/assets/wall/wall.xpm", &w, &h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx,
			"src/assets/floor/floor.xpm", &w, &h);
	game->exit_img = mlx_xpm_file_to_image(game->mlx,
			"src/assets/exit/exit.xpm", &w, &h);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			"src/assets/collectible/collectible.xpm", &w, &h);
}
