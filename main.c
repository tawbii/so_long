/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:44:13 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:16:03 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_and_load_matrix(t_vars *vars, char *filename)
{
	vars->matrix = map2matrix(filename);
	if (!vars->matrix)
	{
		ft_printf("Failed to load matrix from file\n");
		exit (1);
	}
	vars->rows = ft_countlignes(filename);
	vars->cols = ft_countfirstligne(filename);
	return (1);
}

static int	validate_and_solve(t_vars *vars, char *filename)
{
	if (!ft_valid(vars->matrix, filename,
			(t_matrixschema){vars->rows, vars->cols}))
	{
		ft_printf("Map validation failed\n");
		exit (1);
	}
	if (!ft_solution(vars->matrix, (t_matrixschema){vars->rows, vars->cols}))
	{
		ft_printf("No valid solution found\n");
		exit (1);
	}
	return (1);
}

void	main_util(t_vars *vars, char *filename)
{
	if (!init_and_load_matrix(vars, filename))
	{
		clean_up(vars);
		exit (1);
	}
	if (!validate_and_solve(vars, filename))
	{
		clean_up(vars);
		exit (1);
	}
}

int	close_window(void *param)
{
	clean_up((t_vars *)param);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_vars	*vars;
	char	*filename;

	filename = "output.txt";
	vars = init_mlx();
	vars->counter = 0;
	vars->oldcounter = 0;
	if (!vars)
		return (EXIT_FAILURE);
	main_util(vars, filename);
	load_resources(vars);
	mlx_hook(vars->win, 17, 0, close_window, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	render_matrix(vars);
	mlx_loop(vars->mlx);
	clean_up(vars);
	return (EXIT_SUCCESS);
}
