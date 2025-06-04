/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:12:25 by achu              #+#    #+#             */
/*   Updated: 2025/06/04 11:45:54 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "player.h"
#include "system.h"

void	player_direction(t_player *player, double delta, t_vec2 *old_pos);
void	player_turn(t_player *player, double delta);
bool	is_player(char c);

t_vec2	get_start_pos(t_system sys)
{
	int		y;
	int		x;
	t_vec2	pos;

	y = 0;
	while (sys.grid->map[y])
	{
		x = 0;
		while (sys.grid->map[y][x])
		{
			if (is_player(sys.grid->map[y][x]))
			{
				pos.x = x * PIXEL_SIZE + 16.0f;
				pos.y = y * PIXEL_SIZE + 16.0f;
				return (pos);
			}
			x++;
		}
		y++;
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

t_vec2	get_start_dir(t_system sys, t_vec2 pos)
{
	t_vec2	dir;
	int		x;
	int		y;

	x = (pos.x - 16.0f) / PIXEL_SIZE;
	y = (pos.y - 16.0f) / PIXEL_SIZE;
	dir.x = 0;
	dir.y = -1;
	if (sys.grid->map[y][x] == 'S')
	{
		dir.x = 0;
		dir.y = 1;
	}
	else if (sys.grid->map[y][x] == 'W')
	{
		dir.x = -1;
		dir.y = 0;
	}
	else if (sys.grid->map[y][x] == 'E')
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
	player.controller.mouse_x = 0;
	player.vel = 0;
	player.stf = 0;
	player.pos = get_start_pos(sys);
	player.dir = get_start_dir(sys, player.pos);
	player.fov = 60;
	return (player);
}

static void	player_input(t_input *controller, t_system *sys)
{
	controller->move.x = 0;
	controller->move.y = 0;
	controller->turn.x = 0;
	controller->turn.y = 0;
	if (sys->input[W].hold)
		controller->move.y += 1;
	if (sys->input[S].hold)
		controller->move.y -= 1;
	if (sys->input[D].hold)
		controller->move.x += 1;
	if (sys->input[A].hold)
		controller->move.x -= 1;
	if (sys->input[LEFT].hold)
		controller->turn.x -= 1;
	if (sys->input[RIGHT].hold)
		controller->turn.x += 1;
	controller->mouse_x = -sys->move_x * 0.003f;
	controller->sprint_hold = sys->input[SHIFT].hold;
	sys->move_x = 0;
}

// void	update_player(t_player *player, t_system *sys, double delta)
// {
// 	double	fwd_x;
// 	double	fwd_y;
// 	double	stf_x;
// 	double	stf_y;

// 	fwd_x = player->pos.x + player->vel * player->dir.x * delta;
// 	fwd_y = player->pos.y + player->vel * player->dir.y * delta;
// 	stf_x = player->stf * -player->dir.y * delta;
// 	stf_y = player->stf * player->dir.x * delta;
// 	player_input(&player->controller, sys);
// 	player_turn(player, delta);
// 	player_direction(player, delta);
// 	if (sys->grid->map[(int)(player->pos.y / PIXEL_SIZE)]
// 		[(int)(fwd_x / PIXEL_SIZE)] != '1')
// 		player->pos.x = fwd_x;
// 	if (sys->grid->map[(int)(fwd_y / PIXEL_SIZE)]
// 		[(int)(player->pos.x / PIXEL_SIZE)] != '1')
// 		player->pos.y = fwd_y;
// 	if (sys->grid->map[(int)(player->pos.y / PIXEL_SIZE)]
// 		[(int)((player->pos.x + stf_x) / PIXEL_SIZE)] != '1')
// 		player->pos.x += player->stf * -player->dir.y * delta;
// 	if (sys->grid->map[(int)((player->pos.y + stf_y) / PIXEL_SIZE)]
// 		[(int)(player->pos.x / PIXEL_SIZE)] != '1')
// 		player->pos.y += player->stf * player->dir.x * delta;
// }

void	update_player(t_player *player, t_system *sys, double delta)
{
	t_vec2	fwd;
	t_vec2	stf;
	t_vec2	old_pos;

	(player_input(&player->controller, sys), player_turn(player, delta));
	player_direction(player, delta, &old_pos);
	fwd.x = player->pos.x + player->vel * player->dir.x * delta;
	fwd.y = player->pos.y + player->vel * player->dir.y * delta;
	stf.x = player->stf * -player->dir.y * delta;
	stf.y = player->stf * player->dir.x * delta;
	if (sys->grid->map[(int)(player->pos.y / PIXEL_SIZE)]
		[(int)(fwd.x / PIXEL_SIZE)] != '1')
		old_pos.x = fwd.x;
	if (sys->grid->map[(int)(fwd.y / PIXEL_SIZE)]
		[(int)(old_pos.x / PIXEL_SIZE)] != '1')
		old_pos.y = fwd.y;
	if (sys->grid->map[(int)(old_pos.y / PIXEL_SIZE)]
		[(int)((old_pos.x + stf.x) / PIXEL_SIZE)] != '1')
		old_pos.x += stf.x;
	if (sys->grid->map[(int)((old_pos.y + stf.y) / PIXEL_SIZE)]
		[(int)(old_pos.x / PIXEL_SIZE)] != '1')
		old_pos.y += stf.y;
	player->pos.x = old_pos.x;
	player->pos.y = old_pos.y;
}
