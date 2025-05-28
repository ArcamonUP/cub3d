/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:14:36 by achu              #+#    #+#             */
/*   Updated: 2025/05/28 17:21:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdbool.h>
# include "engine/vector.h"

typedef struct s_ray
{
	double		camera;
	t_vec2		plane;
	t_vec2		raydir;

	t_vec2		grid;

	t_vec2		delta_dist;
	t_vec2		side_dist;
	double		raylength;
	t_vec2		step;

	double		perpwall_dist;
	int			side;
}	t_ray;

#endif