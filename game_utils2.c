/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:44:05 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_within_bounds2(t_vars *vars, int i, int j)
{
	return (i >= 0 && i < vars->rows && j >= 0 && j < vars->cols);
}

int	ft_count_collac(t_vars *vars)
{
	int	i;
	int	j;
	int	count;
	int	rows;
	int	cols;

	i = 0;
	count = 0;
	rows = vars->rows;
	cols = vars->cols;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (vars->matrix[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_startposition(t_vars *vars)
{
	int	i;
	int	j;
	int	rows;
	int	cols;

	i = 0;
	rows = vars->rows;
	cols = vars->cols;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			if (vars->matrix[i][j] == 'P')
			{
				vars->player_x = j;
				vars->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}
