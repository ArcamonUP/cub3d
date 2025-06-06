/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:20:07 by achu              #+#    #+#             */
/*   Updated: 2025/06/04 11:44:20 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "player.h"

bool	is_player(char c)
{
	if (c == 'N')
		return (true);
	else if (c == 'S')
		return (true);
	else if (c == 'W')
		return (true);
	else if (c == 'E')
		return (true);
	return (false);
}

static double	ft_approach(double current, double target, double step)
{
	if (current < target)
		return (fminf(current + step, target));
	else if (current > target)
		return (fmaxf(current - step, target));
	else
		return (target);
}

void	player_turn(t_player *player, double delta)
{
	float	theta;
	float	current;
	float	angle;
	double	temp;

	angle = TURN_SPEED * delta;
	theta = angle * (PI / 180);
	if (player->controller.turn.x == -1)
		current = -theta;
	else if (player->controller.turn.x == 1)
		current = theta;
	if (player->controller.turn.x != 0)
	{
		temp = player->dir.x;
		player->dir.x = temp * cos(current) - player->dir.y * sin(current);
		player->dir.y = temp * sin(current) + player->dir.y * cos(current);
	}
	temp = player->dir.x;
	player->dir.x = temp * cos(player->controller.mouse_x)
		- player->dir.y * sin(player->controller.mouse_x);
	player->dir.y = temp * sin(player->controller.mouse_x)
		+ player->dir.y * cos(player->controller.mouse_x);
}

void	player_direction(t_player *player, double delta, t_vec2 *old_pos)
{
	t_input		ctrl;

	ctrl = player->controller;
	if (player->controller.move.x == 0)
		player->stf = ft_approach(player->stf, 0, DECEL * delta);
	else
		player->stf = ft_approach(player->stf, \
			ctrl.move.x * STRAFE_SPEED, ACCEL * delta);
	if (player->controller.move.y == 0)
		player->vel = ft_approach(player->vel, 0, DECEL * delta);
	else
		player->vel = ft_approach(player->vel, \
			ctrl.move.y * MAX_SPEED, ACCEL * delta);
	old_pos->x = player->pos.x;
	old_pos->y = player->pos.y;
}
