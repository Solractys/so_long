/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:34:46 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 01:34:46 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "./so_long.h"
# include "../minilibx/mlx.h"

void	render_map(t_game *game);
void	load_images(t_game *game);
void	draw_tile(t_game *game, void *win, int x, int y);
void	destroy_images(t_game *game);
void    load_player_images(t_game *game);

#endif
