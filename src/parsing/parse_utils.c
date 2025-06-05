/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:59:12 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 00:34:36 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"
#include "libft.h"

int	is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] && line[i] != '\n')
		return (0);
	return (1);
}

int	ft_dupcheck(char *line, char **str, int *map)
{
	int	i;
	int	y;

	if (*str != NULL)
		return (1);
	if (*map == 1)
		*map = 2;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!line[i])
		return (1);
	*str = ft_calloc(sizeof(char), ft_strlen(line + i) + 1);
	if (!*str)
		return (error("Error.\nMalloc failed (invalid format in file)."), 1);
	y = 0;
	while (line[i] && line[i] != '\n')
		(*str)[y++] = line[i++];
	(*str)[y] = '\0';
	return (0);
}

t_map	set_null(void)
{
	t_map	grid;

	grid.ceiling_color = NULL;
	grid.floor_color = NULL;
	grid.map = NULL;
	grid.no_path = NULL;
	grid.so_path = NULL;
	grid.we_path = NULL;
	grid.ea_path = NULL;
	grid.map_is_build = 0;
	return (grid);
}

int	is_all_set(t_map data)
{
	if (!data.ceiling_color)
		return (error("Error\nInvalid file content."), 0);
	if (!data.floor_color)
		return (error("Error\nFloor color not found."), 0);
	if (!data.ea_path)
		return (error("Error\nEA path not found."), 0);
	if (!data.we_path)
		return (error("Error\nWE path not found."), 0);
	if (!data.no_path)
		return (error("Error\nNO path not found."), 0);
	if (!data.so_path)
		return (error("Error\nSO path not found."), 0);
	return (1);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
