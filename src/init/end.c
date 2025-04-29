/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:12:21 by kbaridon          #+#    #+#             */
/*   Updated: 2025/04/29 13:05:51 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"
#include "libft.h"

void	end(t_vars var)
{
	if (!var.ea.error)
		mlx_destroy_image(var.mlx, var.ea.img);
	if (!var.no.error)
		mlx_destroy_image(var.mlx, var.no.img);
	if (!var.so.error)
		mlx_destroy_image(var.mlx, var.so.img);
	if (!var.we.error)
		mlx_destroy_image(var.mlx, var.we.img);
	if (var.map)
		free_tab(var.map);
	if (var.win)
		mlx_destroy_window(var.mlx, var.win);
	if (var.mlx)
		(mlx_destroy_display(var.mlx), free(var.mlx));
	error("Error.\nInitialisation failed.");
	exit(1);
}
