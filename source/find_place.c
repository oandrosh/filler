/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 02:10:42 by oandrosh          #+#    #+#             */
/*   Updated: 2019/02/22 05:42:14 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		distance_for_one(t_set *set, int x, int y)
{
	int		i;
	int		j;
	int		res;
	int		tmp;

	j = -1;
	res = -1;
	while (++j < set->m_y)
	{
		i = -1;
		while (++i < set->m_x)
		{
			if (set->map[j][i] == set->en || set->map[j][i] == set->en + 32)
			{
				tmp = (ft_abs(x - i) + ft_abs(y - j));
				if (res < 0 || res > tmp)
					res = tmp;
			}
		}
	}
	return (res);
}

int		find_distance(t_set *set, t_xyd *tmp)
{
	int		distance;
	int		y;
	int		x;

	distance = 0;
	y = -1;
	while (++y < set->f_y)
	{
		x = -1;
		while (++x < set->f_x)
			if (set->fig[y][x] == '*')
				distance += distance_for_one(set, tmp->x + x, tmp->y + y);
	}
	return (distance);
}

int		try_fill(t_set *set, t_xyd *tmp)
{
	int		x;
	int		y;
	int		n;

	y = -1;
	n = 0;
	while (++y < set->f_y)
	{
		x = -1;
		while (++x < set->f_x)
			if (set->fig[y][x] == '*')
			{
				if (set->map[tmp->y + y][tmp->x + x] == set->my)
					n++;
				if (n > 1 || set->map[tmp->y + y][tmp->x + x] == set->en ||
					set->map[tmp->y + y][tmp->x + x] == set->en + 32)
					return (-1);
			}
	}
	if (n == 1)
		tmp->dist = (find_distance(set, tmp));
	else
		return (-1);
	return (1);
}

int		find_place(t_set *set)
{
	t_xyd	tmp;
	t_xyd	res;

	tmp.y = -1;
	res.dist = -1;
	while (++tmp.y <= set->m_y - set->f_y)
	{
		tmp.x = -1;
		while (++tmp.x <= set->m_x - set->f_x)
		{
			if (try_fill(set, &tmp) == 1)
			{
				if (res.dist == -1 || res.dist > tmp.dist)
					res = tmp;
			}
		}
	}
	if (res.dist >= 0)
		ft_printf("%d %d\n", res.y, res.x);
	else
		ft_printf("0 0\n");
	return (res.dist);
}
