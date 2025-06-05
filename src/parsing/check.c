/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:43:57 by kbaridon          #+#    #+#             */
/*   Updated: 2025/06/05 16:09:33 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "map.h"
#include "libft.h"

int	check_xpm(char *str)
{
	int	i;
	int	fd;

	if (str == NULL)
		return (1);
	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (i < 0)
		return (1);
	if (ft_strncmp(str + i, ".xpm", 4) != 0)
		return (error("Error\nFile doesn't end with '.xpm'."), 1);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (error("Error\nUnable to open the file."), 1);
	close(fd);
	return (0);
}

static int	is_valid(char *str)
{
	int	i;
	int	nb;

	if (ft_strlen(str) > 3)
		return (error("Error\nInvalid color."), 0);
	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (error("Error\nInvalid color."), 0);
	}
	if (ft_strlen(str) != 3)
		return (1);
	nb = ft_atoi(str);
	if (nb < 256)
		return (1);
	return (error("Error\nInvalid color."), 0);
}

int	check_color(char *str)
{
	char	**temp;
	int		i;

	temp = ft_split(str, ',');
	if (!temp)
		return (1);
	if (ft_tablen(temp) != 3)
		return (error("Error\nInvalid color."), free_tab(temp), 1);
	i = 0;
	while (temp[i])
	{
		if (!is_valid(temp[i]))
			return (free_tab(temp), 1);
		i++;
	}
	return (free_tab(temp), 0);
}

int	is_not_good(t_map data)
{
	if (!is_all_set(data))
		return (1);
	if (check_xpm(data.ea_path) || check_xpm(data.no_path) || \
		check_xpm(data.so_path) || check_xpm(data.we_path))
		return (1);
	if (check_color(data.ceiling_color) || check_color(data.floor_color))
		return (1);
	return (0);
}
