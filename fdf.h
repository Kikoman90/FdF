/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 13:44:57 by fsidler           #+#    #+#             */
/*   Updated: 2016/02/17 14:14:43 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <errno.h>
# include <stdio.h>//retirer
# include <mlx.h>

typedef struct	s_var
{
	int 		l;
	int			i;
	int			zoom;
	int			xmove;
	int			ymove;
	int			**tab;
	void		*mlx;
	void		*win;
}				t_var;

int				ft_init_struct(char *buf, int nbl, int nbi);
int				**ft_newtab(char *buf, int nbl, int nbi);
char			*ft_endbuf(char *buf, int *length);

#endif
