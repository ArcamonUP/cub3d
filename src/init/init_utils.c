/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaridon <kbaridon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:24:33 by kbaridon          #+#    #+#             */
/*   Updated: 2025/04/29 12:30:58 by kbaridon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

char	**cp_tab(char **tab)
{
	char	**result;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	result = ft_calloc(sizeof(char *), i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		result[i] = ft_strdup(tab[i]);
		if (!result)
			return (free_tab(result), NULL);
		i++;
	}
	return (result);
}

char	*ft_strnjoin(char *s1, char *s2, int len)
{
	char	*result;
	int		i;
	int		y;

	if (!s1 && !s2)
		return (NULL);
	result = ft_calloc(sizeof(char), len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && s1[i] && i < len)
	{
		result[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2 && s2[i] && i < len)
	{
		result[i] = s2[y];
		y++;
		i++;
	}
	return (result);
}

int	get_value(char *str, int *i)
{
	char	*temp;
	int		start;
	int		result;

	temp = NULL;
	start = *i;
	if (!str || !str[*i])
		return (-1);
	while (str[*i] && ft_isdigit(str[*i]))
		(*i)++;
	temp = ft_strnjoin(temp, str + start, *i - start);
	if (!temp)
		return (-1);
	result = ft_atoi(temp);
	free(temp);
	while (str[*i] && !ft_isdigit(str[*i]))
		(*i)++;
	return (result);
}
