/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:43:38 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:10:32 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	vars->oldcounter = vars->counter;
	if (keycode == 65307)
	{
		clean_up(vars);
		exit(0);
	}
	else if (keycode == 119)
		key_w(vars);
	else if (keycode == 97)
		key_a(vars);
	else if (keycode == 115)
		key_s(vars);
	else if (keycode == 100)
		key_d(vars);
	if (vars->oldcounter != vars->counter && vars->counter != 0)
		printf("The count of movements is :%d\n", vars->counter);
	return (0);
}

void	key_w(t_vars *vars)
{
	int	new_i;
	int	new_j;

	new_i = vars->player_y - 1;
	new_j = vars->player_x;
	if (is_within_bounds2(vars, new_i, new_j)
		&& vars->matrix[new_i][new_j] != '1')
		move_player(vars, new_i, new_j);
}

void	key_s(t_vars *vars)
{
	int	new_i;
	int	new_j;

	new_i = vars->player_y + 1;
	new_j = vars->player_x;
	if (is_within_bounds2(vars, new_i, new_j)
		&& vars->matrix[new_i][new_j] != '1')
		move_player(vars, new_i, new_j);
}

void	key_d(t_vars *vars)
{
	int	new_i;
	int	new_j;

	new_i = vars->player_y;
	new_j = vars->player_x + 1;
	if (is_within_bounds2(vars, new_i, new_j)
		&& vars->matrix[new_i][new_j] != '1')
		move_player(vars, new_i, new_j);
}

void	key_a(t_vars *vars)
{
	int	new_i;
	int	new_j;

	new_i = vars->player_y;
	new_j = vars->player_x - 1;
	if (is_within_bounds2(vars, new_i, new_j)
		&& vars->matrix[new_i][new_j] != '1')
		move_player(vars, new_i, new_j);
}
