/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:42:52 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean_images(t_vars *vars)
{
	if (vars->cell_img_1)
		mlx_destroy_image(vars->mlx, vars->cell_img_1);
	if (vars->cell_img_0)
		mlx_destroy_image(vars->mlx, vars->cell_img_0);
	if (vars->cell_img_p)
		mlx_destroy_image(vars->mlx, vars->cell_img_p);
	if (vars->cell_img_c)
		mlx_destroy_image(vars->mlx, vars->cell_img_c);
	if (vars->cell_img_e)
		mlx_destroy_image(vars->mlx, vars->cell_img_e);
}

static void	clean_window_and_display(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

void	clean_up(t_vars *vars)
{
	if (vars)
	{
		clean_images(vars);
		clean_window_and_display(vars);
		if (vars->matrix)
			free_matrix(vars->matrix, vars->rows);
		free(vars);
	}
}
