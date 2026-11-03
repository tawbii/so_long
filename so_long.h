/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atawbi <atawbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:42:38 by atawbi            #+#    #+#             */
/*   Updated: 2024/12/25 15:17:09 by atawbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# include <stdarg.h>

typedef struct s_vars{
	void	*mlx;
	void	*win;
	void	*cell_img_1;
	void	*cell_img_0;
	void	*cell_img_p;
	void	*cell_img_c;
	void	*cell_img_e;
	int		cell_width;
	int		cell_height;
	int		rows;
	int		cols;
	char	*background_path;
	char	**matrix;
	int		player_x;
	int		player_y;
	int		counter;
	int		oldcounter;
}	t_vars;

typedef struct s_matrixschema
{
	int	rows;
	int	cols;
}	t_matrixschema;

int		ft_countlignes(char *filename);
int		ft_checklignes(char *filename);
int		ft_checkelements(char *filename);
char	**ft_split(char const *s, char c);
int		ft_countfirstligne(char *filename);
int		ft_firstvalid(char *filename);
int		ft_secondvalid(char **mat, char *filename, int rows, int cols);
int		ft_checkfirstligne(char *filename);
int		ft_checklastligne(char *filename);
char	**map2matrix(char *filename);
char	**copy_matrix(char **mat, int rows, int cols);
int		ft_solution(char **mat, t_matrixschema max);
void	free_matrix(char **mat, int rows);
void	clean_up(t_vars *vars);
void	load_resources(t_vars *vars);
t_vars	*init_mlx(void);
void	render_matrix(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
void	key_w(t_vars *vars);
void	key_a(t_vars *vars);
void	key_s(t_vars *vars);
void	key_d(t_vars *vars);
int		is_within_bounds2(t_vars *vars, int i, int j);
int		ft_count_collac(t_vars *vars);
void	ft_startposition(t_vars *vars);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_unputnbr(unsigned int nb);
int		ft_printf(const char *format, ...);
int		ft_smalldecimal(unsigned int n);
int		ft_bigdecimal(unsigned int n);
int		ft_p(void *p);
int		process_format_string(const char *format, va_list args);
int		ft_valid(char **mat, char *filename, t_matrixschema x);
void	move_player(t_vars *vars, int new_i, int new_j);
int		close_window(void *param);
void	main_util(t_vars *vars, char *filename);

#endif
