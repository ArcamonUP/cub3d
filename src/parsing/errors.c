/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:16:57 by kbaridon          #+#    #+#             */
/*   Updated: 2025/05/14 00:34:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_data	destroy_data(t_data data)
{
	if (data.ceiling_color)
		free(data.ceiling_color);
	if (data.floor_color)
		free(data.floor_color);
	if (data.map)
		free_tab(data.map);
	if (data.no_path)
		free(data.no_path);
	if (data.ea_path)
		free(data.ea_path);
	if (data.so_path)
		free(data.so_path);
	if (data.we_path)
		free(data.we_path);
	data = set_null();
	return (data);
}

int	error(char *message)
{
	ft_putstr_fd(message, STDERR_FILENO);
	write(STDERR_FILENO, "\n", 1);
	return (1);
}
