/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:04:49 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/17 13:56:37 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_length_error(char *buf)
{
	int	i;
	int	l;
	int	length;

	i = 0;
	length = -1;
	while (buf[i] != '\0')
	{
		l = 0;
		while (buf[i] != '\n' && buf[i] != '\0')
		{
			while (buf[i] == ' ' && buf[i] != '\n' && buf[i] != '\0')
				i++;
			if (buf[i] != '\n' && buf[i] != '\0')
				l++;
			while (buf[i] != ' ' && buf[i] != '\n' && buf[i] != '\0')
				i++;
		}
		if (length == -1)
			length = l;
		else if (l != length)
			return (-1);
		i++;
	}
	return (length);
}

static int	ft_start_error(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		if ((buf[i] < '0' || buf[i] > '9') && buf[i] != '-')
		{
			ft_putstr_fd("error: lines must only start by a digit or '-'\n", 2);
			return (-1);
		}
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		i++;
	}
	return (1);
}

static int	ft_invalid(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '-' && (buf[i + 1] < '0' || buf[i + 1] > '9'))
		{
			ft_putstr_fd(
					"error: '-' must be followed only by a digit\n", 2);
			return (-1);
		}
		if (buf[i] != '-' && buf[i] != ' ' && buf[i] != '\n'\
			&& !(buf[i] >= '0' && buf[i] <= '9'))
		{
			ft_putstr_fd(
					"error: the file must only contain numbers and spaces", 2);
			return (-1);
		}
		i++;
	}
	return (1);
}

char		*ft_endbuf(char *buf, int *length)
{
	int		i;

	i = 0;
	if (buf[0] == '\0')
	{
		ft_putstr_fd("error: file is empty\n", 2);
		return (NULL);
	}
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	if (ft_start_error(buf) == -1 || ft_invalid(buf) == -1)
		return (NULL);
	if ((*length = ft_length_error(buf)) == -1)
	{
		ft_putstr_fd("error: lines of the file are not the same length\n", 2);
		return (NULL);
	}
	return (buf);
}
