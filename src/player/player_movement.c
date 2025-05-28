/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:20:07 by achu              #+#    #+#             */
/*   Updated: 2025/05/26 16:10:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "player.h"

# define PI 3.14159

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

	angle = TURN_SPEED * delta;
	theta = angle * (PI/180);
	if (player->controller.turn.x == -1)
		current = -theta;
	else if (player->controller.turn.x == 1)
		current = theta;
	if (player->controller.turn.x != 0)
	{
		player->dir.x = player->dir.x * cos(current) - player->dir.y * sin(current);
		player->dir.y = player->dir.x * sin(current) + player->dir.y * cos(current);
	}
}

void	player_direction(t_player *player, double delta)
{
	t_input		ctrl;

	ctrl = player->controller;
	if (player->controller.move.x == 0)
		player->stf = ft_approach(player->stf, 0, DECEL * delta);
	else
		player->stf = ft_approach(player->stf, ctrl.move.x * STRAFE_SPEED, ACCEL * delta);
	if (player->controller.move.y == 0)
		player->vel = ft_approach(player->vel, 0, DECEL * delta);
	else
		player->vel = ft_approach(player->vel, ctrl.move.y * MAX_SPEED, ACCEL * delta);
}
