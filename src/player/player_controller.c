/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:12:25 by achu              #+#    #+#             */
/*   Updated: 2025/06/03 12:30:18 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "system.h"

void	player_direction(t_player *player, double delta);
void	player_turn(t_player *player, double delta);

t_vec2	get_start_pos(t_system sys)
{
	int		i;
	int		j;
	t_vec2	pos;

	i = 0;
	while (sys.grid->map[i])
	{
		j = 0;
		while (sys.grid->map[i][j])
		{
			if (sys.grid->map[i][j] != '0' && sys.grid->map[i][j] != '1')
			{
				pos.x = (j + 0.49) * PIXEL_SIZE;
				pos.y = (i + 0.49) * PIXEL_SIZE;
				return (pos);
			}
			j++;
		}
		i++;
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

t_vec2	get_start_dir(t_system sys, t_vec2 pos)
{
	t_vec2	dir;
	int		i;
	int		j;

	i = (pos.y / PIXEL_SIZE) - 0.49;
	j = (pos.x / PIXEL_SIZE) - 0.49;
	dir.x = 0;
	dir.y = -1;
	if (sys.grid->map[i][j] == 'S')
	{
		dir.x = 0;
		dir.y = 1;
	}
	if (sys.grid->map[i][j] == 'W')
	{
		dir.x = -1;
		dir.y = 0;
	}
	if (sys.grid->map[i][j] == 'E')
	{
		dir.x = 1;
		dir.y = 0;
	}
	return (dir);
}

t_player	init_player(t_system sys)
{
	t_player	player;

	player.controller.move = (t_vec2){.x = 0.0f, .y = 0.0f,};
	player.controller.turn = (t_vec2){.x = 0.0f, .y = 0.0f,};
	player.vel = 0;
	player.stf = 0;
	player.pos = get_start_pos(sys);
	player.dir = get_start_dir(sys, player.pos);
	player.fov = 60;
	return (player);
}

static void	player_input(t_input *controller, t_keybind *keybind)
{
	controller->move.x = 0;
	controller->move.y = 0;
	controller->turn.x = 0;
	controller->turn.y = 0;
	if (keybind[W].hold)
		controller->move.y += 1;
	if (keybind[S].hold)
		controller->move.y -= 1;
	if (keybind[D].hold)
		controller->move.x += 1;
	if (keybind[A].hold)
		controller->move.x -= 1;
	if (keybind[LEFT].hold)
		controller->turn.x -= 1;
	if (keybind[RIGHT].hold)
		controller->turn.x += 1;
	controller->sprint_hold = keybind[SHIFT].hold;
}

#include <stdio.h>

void	update_player(t_player *player, t_keybind *keybind, double delta)
{
	player_input(&player->controller, keybind);
	player_turn(player, delta);
	player_direction(player, delta);
	player->pos.x += player->vel * player->dir.x * delta;
	player->pos.y += player->vel * player->dir.y * delta;
	player->pos.x += player->stf * -player->dir.y * delta;
	player->pos.y += player->stf * player->dir.x * delta;
}
