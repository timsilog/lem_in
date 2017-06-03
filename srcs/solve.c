/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:14:19 by tjose             #+#    #+#             */
/*   Updated: 2017/06/02 13:41:41 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	path_length(t_mapdata mapdata, int path[mapdata.num_rooms])
{
	int i;

	i = -1;
	while (++i < mapdata.num_rooms)
	{
		if (path[i] == -1)
			break ;
	}
	return (i - 1);
}

static void	do_one_turn(t_mapdata md,
		int paths[md.links2start][md.num_rooms],
		t_antdata a[md.num_ants], t_rlist **r)
{
	int i;
	int	new;

	i = -1;
	new = -1;
	while (++i < md.num_ants)
	{
		if (a[i].in > 0)
		{
			a[i].pos++;
			ft_printf("L%d-%s ", i + 1, r[paths[a[i].path_id][a[i].pos]]->name);
			if (paths[a[i].path_id][a[i].pos] == md.end_id)
				a[i].in = -1;
		}
		else if (!a[i].in && ++new < md.num_paths)
		{
			a[i].path_id = new && md.num_ants - i < path_length(md, paths[new])
				- path_length(md, paths[new - 1]) ? 0 : new;
			a[i].in = 1;
			a[i].pos++;
			if (paths[a[i].path_id][a[i].pos] == md.end_id)
				a[i].in = -1;
			ft_printf("L%d-%s ", i + 1, r[paths[a[i].path_id][a[i].pos]]->name);
		}
	}
}

static int	done(t_mapdata mapdata, t_antdata ants[mapdata.num_ants])
{
	int i;

	i = -1;
	while (++i < mapdata.num_ants)
	{
		if (ants[i].in > -1)
			return (0);
	}
	return (1);
}

void		solve(t_mapdata mapdata,
		int paths[mapdata.links2start][mapdata.num_rooms], t_rlist **room_arr)
{
	int			i;
	t_antdata	ants[mapdata.num_ants];

	i = -1;
	while (++i < mapdata.num_ants)
	{
		ants[i].in = 0;
		ants[i].pos = 0;
	}
	while (!done(mapdata, ants))
	{
		do_one_turn(mapdata, paths, ants, room_arr);
		ft_printf("\n");
	}
}
