/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:12:25 by achu              #+#    #+#             */
/*   Updated: 2025/05/15 15:04:34 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	player_direction(t_player *player, double delta);
void	player_turn(t_player *player, double delta);

t_player	init_player(void)
{
	t_player	player;
	
	player.controller.move = (t_vec2){.x = 0.0f, .y = 0.0f,};
	player.controller.turn = (t_vec2){.x = 0.0f, .y = 0.0f,};
	player.vel = (t_vec2){.x = 0.0f, .y = 0.0f,};
	player.pos = (t_vec2){
		.x = 5 * PIXEL_SIZE,
		.y = 5 * PIXEL_SIZE,
	};
	player.dir = (t_vec2){
		.x = 0,
		.y = -1,
	};
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
		controller->move.y -= 1;
	if (keybind[S].hold)
		controller->move.y += 1;
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

void	update_player(t_player *player, t_keybind *keybind, double delta)
{
	player_input(&player->controller, keybind);
	player_direction(player, delta);
	player_turn(player, delta);
	player->pos.x += player->vel.x * delta;
	player->pos.y += player->vel.y * delta;
}
