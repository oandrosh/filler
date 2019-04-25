/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 00:54:38 by oandrosh          #+#    #+#             */
/*   Updated: 2019/02/22 05:38:20 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "lib/ft_printf.h"

typedef struct	s_set
{
	char	my;
	char	en;
	int		m_x;
	int		m_y;
	int		f_x;
	int		f_y;
	char	**map;
	char	**fig;
}				t_set;

typedef struct	s_xyd
{
	int		x;
	int		y;
	int		dist;
}				t_xyd;

int				define_player(t_set *set);
int				map(t_set *set);
void			fill_map(t_set *set);
void			fill_map2(t_set *set);
int				figure(t_set *set);
void			fill_figure(t_set *set);
void			fill_figure2(t_set *set);
int				find_place(t_set *set);
int				try_fill(t_set *set, t_xyd *tmp);
int				find_distance(t_set *set, t_xyd *tmp);
int				distance_for_one(t_set *set, int x, int y);
void			clear_figure(t_set *set);

#endif
