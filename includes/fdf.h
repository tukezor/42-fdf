/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptuukkan <ptuukkan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 10:54:27 by ptuukkan          #+#    #+#             */
/*   Updated: 2019/12/18 10:54:29 by ptuukkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "keys.h"
# include <stdint.h>
# include <fcntl.h>
# include "libft.h"
# include <math.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

typedef struct	s_map
{
	int		width;
	int		height;
	int		**altitude;
	float	zoom;
	float	alt_mul;
	int		isometric;
}				t_map;

typedef struct	s_line
{
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	short	x_angle;
	short	y_angle;
	short	z_angle;
	double	x_matrix[9];
	double	y_matrix[9];
	double	z_matrix[9];
	double	matrix[9];
}				t_line;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}				t_mlx;

typedef struct	s_color
{
	int	red;
	int	green;
	int	blue;
}				t_color;

typedef struct	s_img
{
	t_color	color;
	char	*img_data;
	int		line_size;
	int		total_size;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_fdf
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;
	t_line	line;
}				t_fdf;

void			read_map(char *file, t_fdf *fdf);
void			draw_map(t_fdf *fdf);
void			draw_line(t_fdf *fdf);
void			calculate_xy(t_fdf *fdf, int x, int y, int direction);
int				key_events(int key, t_fdf *fdf);

#endif
