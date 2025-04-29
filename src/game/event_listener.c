/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_listener.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:03:32 by kbaridon          #+#    #+#             */
/*   Updated: 2025/04/29 13:12:33 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"
#include "libft.h"

int	end_game(t_vars *var)
{
	mlx_destroy_image(var->mlx, var->ea.img);
	mlx_destroy_image(var->mlx, var->no.img);
	mlx_destroy_image(var->mlx, var->so.img);
	mlx_destroy_image(var->mlx, var->we.img);
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
