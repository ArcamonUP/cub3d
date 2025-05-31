/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:58:43 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/31 11:19:38 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

typedef struct s_wall
{
	double	wall_x;
	int		start_y;
	int		end_y;
	int		line_h;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_wall;

void	draw_wall(t_system *sys, t_ray *ray, int x);
void	do_floor_and_ceiling(t_wall data, t_system *sys, int x);

#endif