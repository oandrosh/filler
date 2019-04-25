/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 01:50:08 by oandrosh          #+#    #+#             */
/*   Updated: 2019/02/22 05:40:50 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	fill_map2(t_set *set)
{
	int		i;
	char	*str;

	i = 0;
	while (i < set->m_y)
	{
		get_next_line(0, &str);
		set->map[i] = ft_strncpy(set->map[i], str + 4, set->m_x);
		ft_strdel(&str);
		i++;
	}
}

void	fill_map(t_set *set)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (!set->map)
	{
		set->map = (char**)malloc(sizeof(char*) * (set->m_y + 1));
		set->map[set->m_y] = NULL;
		while (i < set->m_y)
		{
			get_next_line(0, &str);
			set->map[i] = ft_strdup(str + 4);
			ft_strdel(&str);
			i++;
		}
	}
	else
		fill_map2(set);
}

void	fill_figure2(t_set *set)
{
	int		i;
	char	*str;

	str = NULL;
	i = -1;
	while (set->fig[++i] != NULL)
		ft_bzero(set->fig[i], set->m_x + 1);
	i = -1;
	while (++i < set->f_y)
	{
		get_next_line(0, &str);
		set->fig[i] = ft_strncpy(set->fig[i], str, set->f_x);
		ft_strdel(&str);
	}
}

void	fill_figure(t_set *set)
{
	int		i;

	i = 0;
	if (!set->fig)
	{
		set->fig = (char**)malloc(sizeof(char*) * (set->m_y + 1));
		set->fig[set->m_y] = NULL;
		while (i < set->m_y)
		{
			set->fig[i] = (char*)malloc(set->m_x + 1);
			i++;
		}
	}
	fill_figure2(set);
}

void	clear_figure(t_set *set)
{
	int i;

	if (!set->fig || !set->fig[0])
		return ;
	i = 0;
	while (set->fig[i] != NULL)
	{
		ft_strdel(&set->fig[i]);
		i++;
	}
	free(set->fig);
	set->fig = NULL;
}
