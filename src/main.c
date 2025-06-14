/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:08:52 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 12:34:12 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/render.h"
#include "engine/input.h"
#include "common.h"
#include "system.h"
#include "game.h"
#include "map.h"

void	update_raycasting(t_system *sys);

static void	delta(t_system *sys)
{
	double	curr;

	curr = get_frame();
	sys->delta = curr - sys->last;
	sys->last = curr;
}

static int32_t	update(t_system *sys)
{
	delta(sys);
	clear_buffer(&sys->buffer, 0x505CB2);
	update_player(&sys->game->player, sys, sys->delta);
	update_raycasting(sys);
	update_input(sys->input);
	if (sys->mouse == 1)
		mlx_mouse_move(sys->window.mlx, sys->window.win,
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	render(sys);
	return (0);
}

static int32_t	start(t_system *sys)
{
	sys->last = get_frame();
	sys->game = init_game(sys);
	if (sys->error || !sys->game)
		return (error("Error.\nMalloc failed."), destroy_system(sys), 1);
	mlx_loop_hook(sys->window.mlx, update, sys);
	mlx_hook(sys->window.win, ON_MOUSE, 1L << 6, mouse_move, sys);
	mlx_hook(sys->window.win, ON_KEYPRESS, 1L << 0, input_press, sys);
	mlx_hook(sys->window.win, ON_KEYRELEASE, 1L << 1, input_release, \
		sys->input);
	mlx_hook(sys->window.win, ON_DESTROY, 1L << 17, destroy_system, sys);
	mlx_loop(sys->window.mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_system	*sys;
	t_map		data;

	data = parsing(ac, av);
	if (!data.map)
		return (1);
	sys = init_system();
	if (!sys)
		return (error("Error\nFailed to init system."), destroy_data(data), 1);
	sys->grid = &data;
	return (start(sys));
}
