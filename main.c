/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 23:17:40 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/08 17:08:20 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <stdio.h>//retirer
#include "mlx.h"

void	ft_window(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "FdF");
	mlx_loop(mlx);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	
	if (argc != 2)
	{
		write(2, "usage: ./FdF input_file\n", 24);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(2, "error: No such file or directory\n", 33);
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);//utiliser strjoin avec aussi des /n
	if (get_next_line(fd, &line) != 0)
		write(2, "error: get_next_line returned -1\n", 32);
	//appeller la fonction pour les erreurs
	if (close(fd) == -1)
		write(2, "close error\n", 12);
	return (fd);
}
