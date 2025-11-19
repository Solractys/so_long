/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:31:30 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 01:31:30 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "map.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*wall_img;
	void	*floor_img;
	void	*player_img[4];
	void	*exit_img[2];
	int		exit_status;
	void	*collectible_img;
	int		player_direction;
	int		moves;
}	t_game;

#endif
