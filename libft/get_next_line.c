/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 17:18:20 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/04 11:35:30 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_read(char *total, int const fd, int *ret)
{
	char			*buf;
	char			*tmp;

	if (!(buf = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	if ((*ret = read(fd, buf, BUFF_SIZE)) != -1 && *ret > 0)
	{
		buf[*ret] = '\0';
		tmp = ft_strjoin(total, buf);
		free(total);
		free(buf);
		total = tmp;
	}
	if (*ret == -1)
		return (NULL);
	return (total);
}

static int		ft_check(char **total, int ret)
{
	if (ret == 0 && ft_strlen(*total) != 0)
	{
		*total = ft_strnew(1);
		return (1);
	}
	else if (ret == 0 && !(ft_strlen(*total)))
		return (0);
	return (-1);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			*cut;
	static char		*total = NULL;

	ret = 1;
	if ((fd < 0 || !(line) || BUFF_SIZE < 1) ||
		(!total && !(total = (char *)malloc(sizeof(char) * 1))))
		return (-1);
	while (ret > 0)
	{
		if (!(total = ft_read(total, fd, &ret)))
			return (-1);
		if ((cut = ft_strchr(total, '\n')) != NULL)
		{
			*cut = '\0';
			if (!(*line = ft_strdup(total)))
				return (-1);
			ft_memmove(total, cut + 1, ft_strlen(cut + 1) + 1);
			return (1);
		}
	}
	if (!(*line = ft_strdup(total)))
		return (-1);
	return (ft_check(&total, ret));
}
