/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:19:46 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 14:53:27 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

// *** Movement ***
# define ACCEL 1200
# define DECEL 600
# define TURN_SPEED 180
# define STRAFE_SPEED 80
# define MAX_SPEED 90
# define FOV 0.66
# define PI 3.14159

# define TURN_LEFT -0.5

# include <stdbool.h>
# include "engine/input.h"
# include "engine/image.h"
# include "engine/vector.h"

typedef struct s_system	t_system;

typedef struct s_input
{
	t_vec2	move;
	t_vec2	turn;
	double	mouse_x;
	bool	sprint_hold;
}	t_input;

typedef struct s_player
{
	t_input		controller;
	t_vec2		pos;
	double		vel;
	double		stf;
	t_vec2		dir;
	uint32_t	fov;
}	t_player;

t_player	init_player(t_system sys);
void		update_player(t_player *player, t_system *sys, double delta);

#endif
