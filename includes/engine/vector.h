/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:49:47 by achu              #+#    #+#             */
/*   Updated: 2025/05/13 17:49:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdbool.h>

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_rect
{
	t_vec2	pos;
	t_vec2	size;
}	t_rect;

bool	is_point_in_rect(t_vec2 point, t_rect rect);
bool	is_collided(t_rect a, t_rect b);
t_vec2	ft_penetration(t_rect a, t_rect b);

#endif