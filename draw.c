/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:13:58 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/17 17:41:22 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_sqrt(float nb)
{
	float	x;

	x = 0;
	while (x * x < nb)
		x++;
	return (x);
}

void		ft_draw_line(t_var f)
{
	double	tx;
	float	dx;
	float	dy;

	tx = 0.0;
	dx = f.x1 - f.x0;
	dy = f.y1 - f.y0;
	while (tx <= 1)
	{
		f.x = f.x0 + (dx * tx);
		f.y = f.y0 + (dy * tx);
		mlx_pixel_put(f.mlx, f.win, f.x, f.y, 0x00F0F0F0);
		tx += 1. / ft_sqrt((dx * dx) + (dy * dy));
	}
}

void		ft_vertical(t_var f, int j, int i)
{
 	f.x0 = 50 + (i * 25) + (j * 25);
	f.x1 = 50 + (i * 25) + ((j + 1) * 25);
	f.y0 = ((600 + (j * 25)) * 1. / 2.) - (((i * 25) + (4 * f.tab[j][i])) * 1. / 2.);
	f.y1 = ((600 + ((j + 1) * 25)) * 1. / 2.) - (((i * 25) + (4 * f.tab[j + 1][i])) * 1. / 2.);
	ft_draw_line(f);
}

void		ft_horizontal(t_var f, int j, int i)
{
	f.x0 = 50 + (i * 25) + (j * 25);
	f.x1 = 50 + ((i + 1) * 25) + (j * 25);
	f.y0 = ((600 + (j * 25)) * 1. / 2.) - (((i * 25) + (4 * f.tab[j][i])) * 1. / 2.);
	f.y1 = ((600 + (j * 25)) * 1. / 2.) - ((((i + 1) * 25) + (4 * f.tab[j][i + 1])) * 1. / 2.);
	ft_draw_line(f);
}

int			ft_call(t_var f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < f.l - 1)
	{
		i = 0;
		while (i < f.i - 1)
		{
			if (i < f.i - 1)
				ft_vertical(f, j, i);
			if (j < f.l - 1)
				ft_horizontal(f, j, i);
			i++;
		}
		j++;
	}
	return (0);
}

int			ft_init_struct(char *buf, int nbl, int nbi)
{
	t_var	f;

	f.xmove = 0;
	f.ymove = 0;
	f.zoom = 0;
	f.tab = ft_newtab(buf, nbl, nbi);
	f.l = nbl;
	f.i = nbi;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, 800, 800, "fdf");
	ft_call(f);	
	mlx_loop(f.mlx);
	return (0);
}
