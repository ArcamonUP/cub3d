/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 19:19:46 by achu              #+#    #+#             */
/*   Updated: 2025/05/14 00:35:48 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:09:45 by achu              #+#    #+#             */
/*   Updated: 2025/04/22 03:37:38 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

// *** Movement ***
# define ACCEL 1200
# define TURN 1200
# define DECEL 600
# define MAX_SPEED 90

# include <stdbool.h>
# include "engine/input.h"
# include "engine/image.h"
# include "engine/vector.h"

typedef struct s_input
{
	t_vec2	move;
}	t_input;

typedef struct s_player
{
	t_input		controller;
	t_sprite	sprite;
	t_vec2		start;
	t_vec2		position;
	uint32_t	direction;
}	t_player;

#endif