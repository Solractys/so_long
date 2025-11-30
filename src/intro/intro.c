/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-s <csilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:41:38 by csilva-s          #+#    #+#             */
/*   Updated: 2025/11/19 15:41:38 by csilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/intro.h"
#include <sys/time.h>

static long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	load_intro_frames(t_intro *intro)
{
	intro->frames[0] = mlx_xpm_file_to_image(intro->mlx,
			"src/assets/intro/LOGO_1.xpm", &(int){0}, &(int){0});
	intro->frames[1] = mlx_xpm_file_to_image(intro->mlx,
			"src/assets/intro/LOGO_2.xpm", &(int){0}, &(int){0});
	intro->frames[2] = mlx_xpm_file_to_image(intro->mlx,
			"src/assets/intro/LOGO_3.xpm", &(int){0}, &(int){0});
	intro->frames[3] = mlx_xpm_file_to_image(intro->mlx,
			"src/assets/intro/LOGO_4.xpm", &(int){0}, &(int){0});
	intro->frames[4] = mlx_xpm_file_to_image(intro->mlx,
			"src/assets/intro/LOGO_5.xpm", &(int){0}, &(int){0});
	intro->frames[5] = mlx_xpm_file_to_image(intro->mlx,
			"src/assets/intro/LOGO_6.xpm", &(int){0}, &(int){0});
	intro->frames[6] = mlx_xpm_file_to_image(intro->mlx,
			"src/assets/intro/LOGO_7.xpm", &(int){0}, &(int){0});
}

void	loop_frame(t_intro *intro)
{
	int	i;

	if (intro->frame_index >= 7)
	{
		i = 0;
		mlx_destroy_window(intro->mlx, intro->win);
		while (i < 7)
		{
			mlx_destroy_image(intro->mlx, intro->frames[i]);
			i++;
		}
		mlx_loop_end(intro->mlx);
	}
}

int	play_intro_frame(void *param)
{
	long		delay;
	long		current_time;
	long		elapsed_time;
	t_intro		*intro;

	intro = (t_intro *)param;
	delay = 600;
	if (intro->frame_index == 0)
		delay = 1500;
	current_time = get_time_ms();
	elapsed_time = current_time - intro->last_frame_time;
	if (elapsed_time < delay)
		return (0);
	intro->last_frame_time = current_time;
	mlx_clear_window(intro->mlx, intro->win);
	mlx_put_image_to_window(intro->mlx, intro->win,
		intro->frames[intro->frame_index],
		(400 - 200) / 2, (300 - 100) / 2);
	intro->frame_index++;
	loop_frame(intro);
	return (0);
}

void	intro_animation(void)
{
	t_intro	intro;

	intro.mlx = mlx_init();
	intro.win = mlx_new_window(intro.mlx,
			400, 300, "The Legend of Zelda: So Long But So Nice");
	intro.frame_index = 0;
	intro.last_frame_time = get_time_ms();
	load_intro_frames(&intro);
	mlx_loop_hook(intro.mlx, play_intro_frame, &intro);
	mlx_loop(intro.mlx);
	mlx_destroy_display(intro.mlx);
	free(intro.mlx);
}
