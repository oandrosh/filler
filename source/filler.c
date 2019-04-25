/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 00:54:19 by oandrosh          #+#    #+#             */
/*   Updated: 2019/02/22 05:40:13 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		define_player(t_set *set)
{
	char *str;

	get_next_line(0, &str);
	if (!str)
		return (0);
	if (ft_strstr(str, "p1") && ft_strstr(str, "oandrosh.filler"))
	{
		set->my = 'O';
		set->en = 'X';
	}
	if (ft_strstr(str, "p2") && ft_strstr(str, "oandrosh.filler"))
	{
		set->my = 'X';
		set->en = 'O';
	}
	free(str);
	return (1);
}

int		map(t_set *set)
{
	char *str;

	get_next_line(0, &str);
	if (ft_strstr(str, "Plateau"))
	{
		set->m_y = ft_atoi(ft_strchr(str, ' '));
		set->m_x = ft_atoi(ft_strrchr(str, ' '));
		ft_strdel(&str);
		if (get_next_line(0, &str))
			ft_strdel(&str);
		fill_map(set);
		return (1);
	}
	else if (str)
		free(str);
	return (0);
}

int		figure(t_set *set)
{
	char	*str;

	get_next_line(0, &str);
	if (ft_strstr(str, "Piece"))
	{
		set->f_y = ft_atoi(ft_strchr(str, ' '));
		set->f_x = ft_atoi(ft_strrchr(str, ' '));
		ft_strdel(&str);
		fill_figure(set);
		return (1);
	}
	else if (str)
		ft_strdel(&str);
	return (0);
}

int		main(void)
{
	t_set	set;

	set.map = NULL;
	set.fig = NULL;
	if (define_player(&set) == 0)
		return (0);
	while (1)
	{
		if (map(&set) == 0)
			break ;
		if (figure(&set) == 0)
			break ;
		if (find_place(&set) < 0)
			break ;
	}
	return (0);
}
