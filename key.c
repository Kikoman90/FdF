/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 15:05:30 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/18 16:01:40 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>//retirer

void	ft_options(t_var f)
{
	mlx_string_put(f.mlx, f.win, 35, 35, OP_COLOR, "Quit = ESC");
	mlx_string_put(f.mlx, f.win, 35, 55, OP_COLOR, "Move = ^ v < >");
	mlx_string_put(f.mlx, f.win, 35, 75, OP_COLOR, "Zoom = + -");
}

/*int			ft_expose(t_var f)
{
	ft_options(f);
	ft_call(f);
	return (0);
}*/

int			ft_escape(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}
