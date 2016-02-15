/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 23:17:40 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/15 17:31:28 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fdf.h"
#include <errno.h>
#include <stdio.h>//retirer
#include <mlx.h>

int			ft_call(int **tab, void *win, void *mlx, int nbl, int nbi)
{
	int	x;
	int	y;
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (!tab)
		return (0);
	while (j < nbl)
	{
		i = 0;
		while (i < nbi - 1)
		{
			y = 50 + (j * 50) - tab[j][i];
			x = 20 + (i * 20);
			while (x <= 20 + ((i + 1) * 20) - tab[j][i])
			{
				if (tab[j][i] == 0)
					mlx_pixel_put(mlx, win, x++, y--, 0xFFFFFF);
				else
					mlx_pixel_put(mlx, win, x++, y--, 0x00FF00);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int			**ft_newtab(char *buf, int nbl, int nbi)
{
	int		i;
	int		j;
	int		k;
	int		**tab;

	j = 0;
	k = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * nbl)))
		return (NULL);
	while (buf[k] != '\0' && j < nbl)
	{
		i = 0;
		if (!(tab[j] = (int *)malloc(sizeof(int) * nbi)))
		{
			while (j-- >= 0)
				free(tab[j]);
			return (NULL);
		}
		while (buf[k] != '\n' && buf[k] != '\0' && j < nbl)
		{
			tab[j][i] = ft_atoi(buf, &k);
			i++;
			if (buf[k] != '\n' && buf[k] != '\0')
			{
				while (buf[k] == ' ')
					k++;
			}
		}
		k++;
		j++;
	}
	return (tab);
}

static void	ft_indicate_error(char *file)
{
	char	*message;

	message = ft_strnew(1);
	message = ft_strjoin(message, "error: ");
	message = ft_strjoin(message, strerror(errno));
	message = ft_strjoin(message, " for ");
	message = ft_strjoin(message, file);
	message = ft_strjoin(message, "\n");
	ft_putstr_fd(message, 2);
}

void		ft_window(int **tab, int nbl, int nbi)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 800, "FdF");
	ft_call(tab, win, mlx, nbl, nbi);
	mlx_loop(mlx);
}

static int	ft_start(char *argv, int argc, int *fd)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./FdF input_file\n", 2);
		return (-1);
	}
	if (BUFF_SIZE < 1)
	{
		ft_putstr_fd("error: BUFF_SIZE must be greater than 0\n", 2);
		return (-1);
	}
	if ((*fd = open(argv, O_RDONLY)) == -1)
	{
		ft_indicate_error(argv);
		return (-1);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		nbl;
	int		nbi;
	int		fd;
	char	*line;
	char	*buf;

	nbl = 0;
	buf = ft_strnew(1);
	if (ft_start(argv[1], argc, &fd) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0 && nbl++ > -1)
		buf = ft_strjoin(ft_strjoin(buf, line), "\n");
	if (get_next_line(fd, &line) != 0)
	{
		ft_putstr_fd("error: get_next_line returned -1\n", 2);
		free(buf);
		return (0);
	}
	if (ft_endbuf(buf, &nbi) != NULL)
	{
		printf("%s\n", buf);//retirer
		printf("nbl: %d nbi: %d\n", nbl, nbi);//retirer
		ft_window(ft_newtab(buf, nbl, nbi), nbl, nbi);
	}
	if (close(fd) == -1)
		ft_indicate_error(argv[1]);
	return (0);
}
