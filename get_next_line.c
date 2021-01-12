/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:11:37 by aloubar           #+#    #+#             */
/*   Updated: 2021/01/12 18:03:05 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static char			*ft_cat_buff(char *str, char *buff, int *end)
{
	char	*new_line;
	int		len;
	int		j;
	int		k;

	j = 0;
	k = 0;
	len = ft_strlen_protected(str) + ft_strlen_protected(buff);
	if ((new_line = malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	if (str)
	{
		while (str[k])
		{
			new_line[k] = str[k];
			k++;
		}
		new_line[k] = '\0';
	}
	if (buff[j])
	{
		while (buff[j])
		{
			if (buff[j] == '\n')
				*end = 1;
			new_line[k + j] = buff[j];
			j++;
		}
	}
	new_line[k + j] = '\0';
	free(str);
	return (new_line);
}

static char		*ft_get_first_line(char *str, int *end)
{
	char	*first_line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		*end = -1;
	if ((first_line = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	while (j < i)
	{
		first_line[j] = str[j];
		j++;
	}
	first_line[j] = '\0';
	return (first_line);
}

static char		*ft_get_rest(char *str)
{
	int		total_len;
	int		f_line_len;
	int		i;
	char	*new_str;

	i = 0;
	f_line_len = ft_strlen_protected(str, '\n');
	total_len = ft_strlen_protected(str) - f_line_len;
	if ((new_str = malloc(sizeof(char) * (total_len + 1))) == NULL)
		return (NULL);
	new_str[total_len] = '\0';
	while (i < total_len)
	{
		new_str[i] = str[f_line_len + i];
		i++;
	}
	free(str);
	return (new_str);
}

int				get_next_line(int fd, char **line)
{
	int			res;
	char		buff[BUFFER_SIZE + 1];
	static char	*str;
	int			end;
	char		*first_line;

	end = 0;
	if (fd < 0 || line == NULL || read(fd, buff, BUFFER_SIZE) < 0)
		return (-1);
	while ((res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[res] = '\0';
		if ((str = ft_cat_buff(str, buff, &end)) == NULL)
			return (ft_free_exit(&str, NULL));
		if (end == 1)
			break;
	}
	if ((first_line = ft_get_first_line(str, &end)) == NULL)
		return (ft_free_exit(&str, NULL));
	else if ((str = ft_get_rest(str)) == NULL)
		return (ft_free_exit(&str, &first_line));
	*line = first_line;
	free(first_line);
	if (end == -1)
		ft_end(&str);
	return (1);
}

int main (int ac, char **av)
{
	(void)ac;
	int fd;
	fd = open(av[1], O_RDONLY);
	int ret = 0;
	char *line;

	while ((ret = get_next_line(fd, &line)) > 0)
		printf("%s\n", line);
	return (0);
}
