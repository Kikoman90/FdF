/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 12:13:58 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/17 14:36:37 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_horizontal(t_var f, int j, int i)
{
	double x0;
	double x1;
	double y0;
	double y1;

	x0 = 400 + (i * 25);
	x1 = 400 + ((i + 1) * 25) + (j * 25);
}

int			ft_call(t_var f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < f.l)
	{
		i = 0;
		while (i < f.i)
		{
			/*y = 50 + (j * 50) - f.tab[j][i];
			x = 20 + (i * 20);
			while (x <= 20 + ((i + 1) * 20) - f.tab[j][i])
			{
				if (f.tab[j][i] == 0)
					mlx_pixel_put(f.mlx, f.win, x++, y--, 0xFFFFFF);
				else
					mlx_pixel_put(f.mlx, f.win, x++, y--, 0x00FF00);
			}*/
			if (i < f.i - 1)
				ft_vertical(f, j, i);
			if (j < f->l - 1)
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
