/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:03:32 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 00:39:11 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "game.h"
#include "libft.h"

int	end_game(t_vars *var)
{
	mlx_destroy_image(var->mlx, var->ea.ptr);
	mlx_destroy_image(var->mlx, var->no.ptr);
	mlx_destroy_image(var->mlx, var->so.ptr);
	mlx_destroy_image(var->mlx, var->we.ptr);
	free_tab(var->map);
	mlx_destroy_window(var->mlx, var->win);
	mlx_loop_end(var->mlx);
	(mlx_destroy_display(var->mlx), free(var->mlx));
	exit(1);
	return (1);
}

int	key_hook(int keycode, t_vars *var)
{
	if (keycode == KEY_ESC)
		return (end_game(var));
	return (0);
}

void	event_listener(t_vars var)
{
	mlx_key_hook(var.win, key_hook, &var);
	mlx_hook(var.win, 17, 0, end_game, &var);
	mlx_loop(var.mlx);
}
