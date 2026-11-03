/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:45:28 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_firstvalid(char *filename)
{
	int	line_check;
	int	element_check;

	line_check = ft_checklignes(filename);
	if (line_check != 1)
		return (0);
	element_check = ft_checkelements(filename);
	if (element_check != 1)
		return (0);
	return (1);
}

int	ft_secondvalid(char **mat, char *filename, int rows, int cols)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < rows)
	{
		if (mat[i] == NULL)
		{
			ft_printf("Error: Matrix row %d is NULL\n", i);
			exit (1);
		}
		while (j < cols)
			j++;
		i++;
	}
	if (ft_checkfirstligne(filename) != 1 || ft_checklastligne(filename) != 1)
		return (0);
	return (1);
}

int	ft_valid(char **mat, char *filename, t_matrixschema x)
{
	int				first_valid_result;

	first_valid_result = ft_firstvalid(filename);
	if (x.rows <= 0 || x.cols <= 0)
		return (0);
	if (first_valid_result == 0)
		return (0);
	if (first_valid_result == 1
		&& ft_secondvalid(mat, filename, x.rows, x.cols) == 1)
		return (1);
	return (0);
}
