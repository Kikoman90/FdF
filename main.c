/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 23:17:40 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/08 16:07:41 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <errno.h>
#include <stdio.h>//retirer
#include "mlx.h"

/*static int	ft_nbline(int fd)
{
	char	*buf;
	int		ret;
	int		nb;

	nb = 0;
}*/

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		fd;
	char	*line;
	//int		j;//retirer
	//int	x;
	//int	y;
	//int	start;

	//x = 50;
	//y = 40;
	//start = 100;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FdF");
	if (argc != 2)
	{
		write(1, "usage: ./FdF input_file\n", 24);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(1, "error: No such file or directory\n", 33);//utiliser putstr(strerror(errno));
		return (0);
	}
	/*j = 0;
	while (j < ft_nbline(fd))
	{
		while (i < size_line
		printf("%dft_tab(ft_nbline(fd));//ceci est un test
		j++;
	}*/
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	/*while (y <= 320)
	{
		x = 40;
		while (x <= 320)
		{
			if (y % 20 == 0)
				mlx_pixel_put(mlx, win, x++, y, 0x00008080);
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
	}*/
	mlx_loop(mlx);
	close(fd);
	return (fd);
}
