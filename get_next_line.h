/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:12:27 by aloubar           #+#    #+#             */
/*   Updated: 2021/01/12 17:11:02 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int				ft_end(char **str);
int				ft_free_exit(char **str, char **new_line);
int				ft_strlen_protected(char *str);
int				ft_check_char(char *str, int c);

#endif
