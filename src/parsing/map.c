/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:30:21 by kbaridon          #+#    #+#             */
/*   Updated: 2025/04/24 14:50:28 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	check_bords(t_data data)
{
	return (data);
}

t_data	parse_map(t_data data, int i, int spawn)
{
	int	j;

	if (!data.map)
		return (error("Error\nCannot read the map."), data);
	while (data.map[++i])
	{
		j = -1;
		while (data.map[i][++j])
		{
			if (data.map[i][j] == 'N' || data.map[i][j] == 'S'
				|| data.map[i][j] == 'E' || data.map[i][j] == 'W')
			{
				if (spawn)
					return (error("Error\nInvalid map."), destroy_data(data));
				spawn = 1;
			}
			else if (data.map[i][j] != '1' && \
				data.map[i][j] != '0' && data.map[i][j] != ' ')
				return (error("Error\nInvalid map."), destroy_data(data));
		}
	}
	if (spawn == 0)
		return (error("Error\nInvalid map."), destroy_data(data));
	return (check_bords(data));
}
