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

#include "game.h"
#include "stdlib.h"
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

t_data	set_null(void)
{
	t_data	data;

	data.ceiling_color = NULL;
	data.floor_color = NULL;
	data.map = NULL;
	data.no_path = NULL;
	data.so_path = NULL;
	data.we_path = NULL;
	data.ea_path = NULL;
	data.map_is_build = 0;
	return (data);
}

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
