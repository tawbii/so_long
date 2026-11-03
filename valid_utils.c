/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:45:13 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countlignes(char *filename)
{
	char	c;
	int		count;
	int		fd;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	while ((read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			count++;
	}
	count++;
	close(fd);
	return (count);
}

int	ft_countfirstligne(char *filename)
{
	char	c;
	int		count;
	int		fd;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
			return (count);
		count++;
	}
	if (read(fd, &c, 1) == -1)
		return (-1);
	close(fd);
	return (count);
}

int	ft_checklignes(char *filename)
{
	char	c;
	int		count;
	int		fd;
	int		first_ligne;

	count = 0;
	first_ligne = ft_countfirstligne(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((read(fd, &c, 1)) > 0)
	{
		if (c == '\n')
		{	
			if (count != first_ligne)
				return (0);
			count = 0;
		}
		else
			count++;
	}
	return (1);
}

static int	ft_element(char *filename, char s)
{
	char	c;
	int		fd;
	int		count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (c == s)
			count++;
	}
	close(fd);
	return (count);
}

int	ft_checkelements(char *filename)
{
	char	c;
	int		fd;

	if (ft_element(filename, 'P') != 1 || ft_element(filename, 'E') != 1)
		return (0);
	if (ft_element(filename, 'C') < 1)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (!(c == 'P' || c == 'E' || c == 'C'
				|| c == '1' || c == '0' || c == '\n'))
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}
