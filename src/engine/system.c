/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   system.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 22:49:34 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 22:55:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "system.h"

double	get_frame(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec + (ts.tv_nsec / 1.0e9));
}

t_system	*init_system(void)
{
	t_system	*sys;
	t_display	temp;

	sys = (t_system *)malloc(sizeof(t_system));
	if (!sys)
		return (NULL);
	temp = init_window();
	if (!temp.height)
		return (free(sys), NULL);
	sys->window = temp;
	sys->buffer = new_img(sys->window, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (sys->buffer.error)
		return (free(sys), destroy_window(&temp), NULL);
	sys->input = init_input();
	sys->move_x = 0;
	sys->last_x = WINDOW_WIDTH / 2;
	sys->last = 0;
	sys->delta = 0;
	sys->mouse = 0;
	return (sys);
}

void	destroy_game(t_game *game)
{
	destroy_img(game->ea);
	destroy_img(game->no);
	destroy_img(game->so);
	destroy_img(game->we);
}

int32_t	destroy_system(t_system	*sys)
{
	destroy_game(sys->game);
	destroy_img(sys->buffer);
	destroy_window(&sys->window);
	destroy_data(*sys->grid);
	if (sys->game)
		free(sys->game);
	if (sys)
		free(sys);
	exit(0);
}
