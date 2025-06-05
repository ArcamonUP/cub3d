/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:50:16 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 00:51:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include "engine/window.h"

t_display	*init_window(void)
{
	t_display	*display;
	void		*mlx_ptr;
	void		*win_ptr;

	display = NULL;
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (NULL);
	win_ptr = mlx_new_window(
			mlx_ptr,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (win_ptr == NULL)
		return (NULL);
	display->mlx = mlx_ptr;
	display->win = win_ptr;
	display->width = WINDOW_WIDTH;
	display->height = WINDOW_HEIGHT;
	return (display);
}

void	destroy_window(t_display *window)
{
	if (window->mlx && window->win)
		mlx_destroy_window(window->mlx, window->win);
	if (window->mlx)
	{
		mlx_destroy_display(window->mlx);
		free(window->mlx);
	}
	window->mlx = NULL;
	window->win = NULL;
}
