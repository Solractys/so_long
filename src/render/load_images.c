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
	int	i;
	char	*paths[4][6] = {
		{"src/assets/player/up/PLAYER_U1.xpm", "src/assets/player/up/PLAYER_U2.xpm",
		 "src/assets/player/up/PLAYER_U3.xpm", "src/assets/player/up/PLAYER_U4.xpm",
		 "src/assets/player/up/PLAYER_U5.xpm", "src/assets/player/up/PLAYER_U6.xpm"},
		{"src/assets/player/down/PLAYER_D1.xpm", "src/assets/player/down/PLAYER_D2.xpm",
		 "src/assets/player/down/PLAYER_D3.xpm", "src/assets/player/down/PLAYER_D4.xpm",
		 "src/assets/player/down/PLAYER_D5.xpm", "src/assets/player/down/PLAYER_D6.xpm"},
		{"src/assets/player/left/PLAYER_L1.xpm", "src/assets/player/left/PLAYER_L2.xpm",
		 "src/assets/player/left/PLAYER_L3.xpm", "src/assets/player/left/PLAYER_L4.xpm",
		 "src/assets/player/left/PLAYER_L5.xpm", "src/assets/player/left/PLAYER_L6.xpm"},
		{"src/assets/player/right/PLAYER_R1.xpm", "src/assets/player/right/PLAYER_R2.xpm",
		 "src/assets/player/right/PLAYER_R3.xpm", "src/assets/player/right/PLAYER_R4.xpm",
		 "src/assets/player/right/PLAYER_R5.xpm", "src/assets/player/right/PLAYER_R6.xpm"}
	};

	w = 32;
	h = 32;
	i = 0;
	while (i < 4)
	{
		int	j;

		j = 0;
		while (j < 6)
		{
			game->player_img[i][j] = mlx_xpm_file_to_image(game->mlx,
					paths[i][j], &w, &h);
			j++;
		}
		i++;
	}
}

void	load_images(t_game *game)
{
	int	w;
	int	h;
	int	i;
	char	*grass_paths[6] = {
		"src/assets/floor/GRASS_1.xpm",
		"src/assets/floor/GRASS_2.xpm",
		"src/assets/floor/GRASS_3.xpm",
		"src/assets/floor/GRASS_4.xpm",
		"src/assets/floor/GRASS_5.xpm",
		"src/assets/floor/GRASS_6.xpm"
	};
	char	*collectible_paths[6] = {
		"src/assets/collectible/COLLECTIBLE_1.xpm",
		"src/assets/collectible/COLLECTIBLE_2.xpm",
		"src/assets/collectible/COLLECTIBLE_3.xpm",
		"src/assets/collectible/COLLECTIBLE_4.xpm",
		"src/assets/collectible/COLLECTIBLE_5.xpm",
		"src/assets/collectible/COLLECTIBLE_6.xpm"
	};

	w = 32;
	h = 32;
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"src/assets/wall/WALL.xpm", &w, &h);
	i = 0;
	while (i < 6)
	{
		game->floor_img[i] = mlx_xpm_file_to_image(game->mlx,
				grass_paths[i], &w, &h);
		game->collectible_img[i] = mlx_xpm_file_to_image(game->mlx,
				collectible_paths[i], &w, &h);
		i++;
	}
	game->exit_img[0] = mlx_xpm_file_to_image(game->mlx,
			"src/assets/exit/EXIT.xpm", &w, &h);
	game->exit_img[1] = mlx_xpm_file_to_image(game->mlx,
			"src/assets/exit/EXIT_OPEN.xpm", &w, &h);
}
