/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:14:19 by tjose             #+#    #+#             */
/*   Updated: 2017/06/01 23:46:54 by tjose            ###   ########.fr       */
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

static void	do_one_turn(t_mapdata mapdata,
		int paths[mapdata.links2start][mapdata.num_rooms],
		t_antdata ants[mapdata.num_ants], t_rlist **room_arr)
{
	int a;
	int	new;

	a = -1;
	new = -1;
	while (++a < mapdata.num_ants)
	{
		if (ants[a].in > 0)
		{
			ants[a].pos++;
			ft_printf("L%d-%s ", a + 1, room_arr[paths[ants[a].path_id][ants[a].pos]]->name);
			if (paths[ants[a].path_id][ants[a].pos] == mapdata.end_id)
				ants[a].in = -1;
		}
		else if (!ants[a].in && ++new < mapdata.num_paths)
		{	
			if (new && mapdata.num_ants - a < path_length(mapdata, paths[new]))
			{
				ft_printf("in %d\n", path_length(mapdata, paths[new]));
				ants[a].path_id = 0;
			}
			else
				ants[a].path_id = new;
			ants[a].in = 1;
			ants[a].pos++;
			ft_printf("L%d-%s ", a + 1, room_arr[paths[ants[a].path_id][ants[a].pos]]->name);
		}
	}
	ft_printf("\n");
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
		int paths[mapdata.links2start][mapdata.num_rooms],
		t_rlist *room_list, t_rlist **room_arr)
{//check if we need roomlist here (need throw error fun?)
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
	}
	(void)room_list;
}
