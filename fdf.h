/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 13:44:57 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/17 18:46:36 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <errno.h>
# include <mlx.h>

typedef struct	s_var
{
	int			l;
	int			i;
	int			length;
	int			zoom;
	int			xmove;
	int			ymove;
	int			**tab;
	double		x;
	double		y;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
	void		*mlx;
	void		*win;
}				t_var;

int				ft_init_struct(char *buf, int nbl, int nbi);
int				**ft_newtab(char *buf, int nbl, int nbi);
char			*ft_endbuf(char *buf, int *length);

#endif
