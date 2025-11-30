/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:37:07 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 00:37:07 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/so_long.h"
#include "../../includes/map.h"
#include "../../includes/render.h"

int	exit_game(t_game *game)
{
	free_map(game->map);
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game);
	exit(0);
	return (0);
}
