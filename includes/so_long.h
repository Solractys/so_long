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
# include <sys/time.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*wall_img;
	void	*floor_img[6];
	void	*player_img[4][6];
	void	*exit_img[2];
	int		exit_status;
	void	*collectible_img[6];
	int		player_direction;
	int		moves;
	int		grass_frame;
	int		collectible_frame;
	int		player_frame;
	long	last_frame_time;
}	t_game;

#endif
