/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:30:21 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 00:34:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

int	check_around(char **map, int i, int j)
{
	int	i2;
	int	j2;

	i2 = i;
	j2 = j;
	while ((i >= 0 && (int)ft_strlen(map[i]) >= j) && \
		map[i][j] != '1' && map[i][j] != ' ')
		i--;
	if (i < 0 || (int)ft_strlen(map[i]) < j || map[i][j] == ' ')
		return (1);
	i = i2;
	while ((map[i] && (int)ft_strlen(map[i]) >= j) && \
		map[i][j] != '1' && map[i][j] != ' ')
		i++;
	if (!map[i] || (int)ft_strlen(map[i]) < j || map[i][j] == ' ')
		return (1);
	while (j >= 0 && map[i2][j] != '1' && map[i2][j] != ' ')
		j--;
	if (j < 0 || map[i2][j] == ' ')
		return (1);
	while (map[i2][j2] && map[i2][j2] != '1' && map[i2][j2] != ' ')
		j2++;
	if (!map[i2][j2] || map[i2][j2] == ' ')
		return (1);
	return (0);
}

t_data	check_bords(t_data data)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	result = 0;
	while (data.map[i] && !result)
	{
		j = 0;
		while (data.map[i][j])
		{
			if (data.map[i][j] != '1' && data.map[i][j] != ' ')
				result = check_around(data.map, i, j);
			if (result)
				break ;
			j++;
		}
		i++;
	}
	if (result)
		return (error("Error\nInvalid map."), destroy_data(data));
	return (data);
}

t_data	parse_map(t_data data, int i, int spawn)
{
	int	j;

	if (!data.map)
		return (error("Error\nInvalid map."), data);
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
