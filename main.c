/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 23:17:40 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/03 23:51:27 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main(void)
{
	void *mlx;
	void *win;
	int	x;
	int	y;
	int	start;

	x = 50;
	y = 40;
	start = 100;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FdF");
	/*while (y < 300)
	{
		x = start;
		while (x < 300)
			mlx_pixel_put(mlx, win, x++, y, 0x00FFFFFF);
		start++;
		y++;
	}*/
	/*while (y < 300 && x < 300)
	{
		if (x < 200)
			mlx_pixel_put(mlx, win, x++, y++, 0x00FF00FF);
		else
			mlx_pixel_put(mlx, win, x++, y++, 0x0000FF00);
	}*/
	while (y <= 320)
	{
		x = 40;
		while (x <= 320)
		{
			if (y % 20 == 0)
				mlx_pixel_put(mlx, win, x++, y, 0x000000FF);
			else
				y++;
		}
		y++;
	}
	x = 40;
	while (x <= 320)
	{
		y = 40;
		while (y <= 320)
		{
			if (x % 20 == 0)
				mlx_pixel_put(mlx, win, x, y++, 0x00008080);
			else
				x++;
		}
		x++;
	}
	mlx_loop(mlx);
	return (0);
}
