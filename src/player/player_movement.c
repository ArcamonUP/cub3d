/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:20:07 by achu              #+#    #+#             */
/*   Updated: 2025/05/15 15:02:47 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "player.h"

static double	ft_approach(double current, double target, double step)
{
	if (current < target)
		return (fminf(current + step, target));
	else if (current > target)
		return (fmaxf(current - step, target));
	else
		return (target);
}

void	player_direction(t_player *player, double delta)
{
	double	accel;
	double	turn;
	double	decel;

	accel = ACCEL;
	turn = TURN;
	decel = DECEL;
	if (player->controller.move.x == 0)
		player->vel.x = ft_approach(player->vel.x, 0, decel * delta);
	else
		player->vel.x = ft_approach(player->vel.x,
				player->controller.move.x * MAX_SPEED, accel * delta);
	if (player->controller.move.y == 0)
		player->vel.y = ft_approach(player->vel.y, 0, decel * delta);
	else
		player->vel.y = ft_approach(player->vel.y,
				player->controller.move.y * MAX_SPEED, accel * delta);
}

void	player_turn(t_player *player, double delta)
{
	if (player->controller.turn.x != 0)
	{
		player->dir.x = player->dir.x * cos(-0.5f) - player->dir.y * sin(-0.5f);
	}
}
