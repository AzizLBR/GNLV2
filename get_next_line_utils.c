/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:12:11 by aloubar           #+#    #+#             */
/*   Updated: 2021/01/12 17:44:50 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_char(char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

int		ft_strlen_protected(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int		ft_free_exit(char **str, char **new_line)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (new_line && *new_line)
	{
		free(*new_line);
		*new_line = NULL;
	}
	return (-1);
}

int		ft_end(char **str)
{
	if (str && *str)
		free(*str);
	return (0);
}
