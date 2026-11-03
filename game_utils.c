/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:43:56 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_put_image_to_window(void *p, t_vars *vars, int j, int i)
{
	mlx_put_image_to_window(vars->mlx, vars->win, p,
		j * vars->cell_width, i * vars->cell_height);
}

void	render_matrix(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->cols)
		{
			if (vars->matrix[i][j] == '1')
				my_mlx_put_image_to_window(vars->cell_img_1, vars, j, i);
			else if (vars->matrix[i][j] == '0')
				my_mlx_put_image_to_window(vars->cell_img_0, vars, j, i);
			else if (vars->matrix[i][j] == 'P')
				my_mlx_put_image_to_window(vars->cell_img_p, vars, j, i);
			else if (vars->matrix[i][j] == 'E')
				my_mlx_put_image_to_window(vars->cell_img_e, vars, j, i);
			else if (vars->matrix[i][j] == 'C')
				my_mlx_put_image_to_window(vars->cell_img_c, vars, j, i);
			j++;
		}
		i++;
	}
}

t_vars	*init_mlx(void)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
	{
		ft_printf("Failed to allocate memory for t_vars\n");
		exit(EXIT_FAILURE);
	}
	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		ft_printf("Failed to initialize MLX\n");
		free(vars);
		exit(EXIT_FAILURE);
	}
	vars->cell_img_1 = NULL;
	vars->cell_img_0 = NULL;
	vars->cell_img_p = NULL;
	vars->cell_img_c = NULL;
	vars->cell_img_e = NULL;
	vars->win = NULL;
	vars->matrix = NULL;
	vars->rows = 0;
	vars->cols = 0;
	return (vars);
}

void	load_resources(t_vars *vars)
{
	vars->cell_img_1 = mlx_xpm_file_to_image(vars->mlx, "xpms/11.xpm",
			&vars->cell_width, &vars->cell_height);
	vars->cell_img_0 = mlx_xpm_file_to_image(vars->mlx, "xpms/00.xpm",
			&vars->cell_width, &vars->cell_height);
	vars->cell_img_p = mlx_xpm_file_to_image(vars->mlx, "xpms/p.xpm",
			&vars->cell_width, &vars->cell_height);
	vars->cell_img_c = mlx_xpm_file_to_image(vars->mlx, "xpms/c.xpm",
			&vars->cell_width, &vars->cell_height);
	vars->cell_img_e = mlx_xpm_file_to_image(vars->mlx, "xpms/e.xpm",
			&vars->cell_width, &vars->cell_height);
	if (!vars->cell_img_1 || !vars->cell_img_0 || !vars->cell_img_p
		|| !vars->cell_img_c || !vars->cell_img_e)
	{
		ft_printf("Failed to load some images\n");
		clean_up(vars);
		exit(EXIT_FAILURE);
	}
	ft_startposition(vars);
	vars->win = mlx_new_window(vars->mlx, vars->cols * vars->cell_width,
			vars->rows * vars->cell_height, "Matrix Display");
}

void	move_player(t_vars *vars, int new_i, int new_j)
{
	if (vars->matrix[new_i][new_j] == 'E')
	{
		if (ft_count_collac(vars) == 0)
		{
			clean_up(vars);
			ft_printf("You win! ");
			exit(0);
		}
	}
	else
	{
		vars->matrix[new_i][new_j] = 'P';
		vars->matrix[vars->player_y][vars->player_x] = '0';
		vars->player_y = new_i;
		vars->player_x = new_j;
		vars->counter++;
		render_matrix(vars);
	}
}
