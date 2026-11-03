/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:45:19 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkfirstligne(char *filename)
{
	char	c;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			break ;
		else
		{
			if (c != '1')
			{
				close (fd);
				return (0);
			}
		}
	}
	if (read(fd, &c, 1) == -1)
		return (-1);
	close(fd);
	return (1);
}

static int	ft_checkhelper(int fd, int lignes)
{
	int		count;
	char	c;

	count = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (count == lignes)
		{
			if (c != '1' && c != '\n')
			{
				return (0);
			}
		}
		else
		{
			if (c == '\n')
				count++;
		}
	}
	return (1);
}

int	ft_checklastligne(char *filename)
{
	int	fd;
	int	lignes;
	int	result;

	lignes = ft_countlignes(filename);
	if (lignes <= 0)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	result = ft_checkhelper(fd, lignes - 1);
	close(fd);
	return (result);
}
