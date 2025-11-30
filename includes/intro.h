/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:46:40 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 15:46:40 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTRO_H
# define INTRO_H

# include "game.h"
# include "so_long.h"

typedef struct s_intro
{
	void	*frames[7];
	void	*mlx;
	void	*win;
	int		frame_index;
	long	last_frame_time;
}	t_intro;

void	intro_animation(void);
void	load_intro_frames(t_intro *intro);
int		play_intro_frame(void *param);

#endif
