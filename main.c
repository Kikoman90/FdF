/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 23:17:40 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/08 18:21:10 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <errno.h>
#include <stdio.h>//retirer
#include "mlx.h"

void	ft_indicate_error(char *file)
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


void	ft_window(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FdF");
	mlx_loop(mlx);
}

char	*ft_error(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	return (buf);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	*buf;
	
	buf = ft_strnew(1);
	if (argc != 2)
	{
		write(2, "usage: ./FdF input_file\n", 24);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_indicate_error(argv[1]);
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
		buf = ft_strjoin(ft_strjoin(buf, line), "\n");
	if (get_next_line(fd, &line) != 0)
	{
		write(2, "error: get_next_line returned -1\n", 32);
		free(buf);
		return (0);
	}
	if (!ft_error(buf))
		printf("%s\n", buf);//retirer
	if (close(fd) == -1)
		ft_indicate_error(argv[1]);
	return (fd);
}
