/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:45:03 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_matrix(char **mat, int rows, int cols)
{
	char	**copy;
	int		i;
	int		j;

	copy = malloc(rows * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		copy[i] = malloc(cols * sizeof(char));
		j = 0;
		while (j < cols)
		{
			copy[i][j] = mat[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}

void	free_matrix(char **mat, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

static int	is_within_bounds(t_matrixschema dims, int i, int j)
{
	return (i >= 0 && i < dims.rows && j >= 0 && j < dims.cols);
}

static int	ft_checksolution(char **mat, int i, int j, t_matrixschema dims)
{
	if (!is_within_bounds(dims, i, j))
		return (0);
	if (mat[i][j] == '1')
		return (0);
	if (mat[i][j] == 'E')
		return (1);
	mat[i][j] = '1';
	if (is_within_bounds(dims, i, j + 1) && mat[i][j + 1] != '1')
		if (ft_checksolution(mat, i, j + 1, dims) == 1)
			return (1);
	if (is_within_bounds(dims, i + 1, j) && mat[i + 1][j] != '1')
		if (ft_checksolution(mat, i + 1, j, dims) == 1)
			return (1);
	if (is_within_bounds(dims, i, j - 1) && mat[i][j - 1] != '1')
		if (ft_checksolution(mat, i, j - 1, dims) == 1)
			return (1);
	if (is_within_bounds(dims, i - 1, j) && mat[i - 1][j] != '1')
		if (ft_checksolution(mat, i - 1, j, dims) == 1)
			return (1);
	return (0);
}

int	ft_solution(char **mat, t_matrixschema max)
{
	int				i;
	int				j;
	char			**mat_copy;
	int				result;

	mat_copy = copy_matrix(mat, max.rows, max.cols);
	if (mat_copy == NULL)
		return (0);
	i = 0;
	while (i++ < max.rows)
	{
		j = 0;
		while (j < max.cols)
		{
			if (mat_copy[i][j] == 'P')
			{
				result = ft_checksolution(mat_copy, i, j, max);
				free_matrix(mat_copy, max.rows);
				return (result);
			}
			j++;
		}
	}
	free_matrix(mat_copy, max.rows);
	return (0);
}
