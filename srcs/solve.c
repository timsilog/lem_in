/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:14:19 by tjose             #+#    #+#             */
/*   Updated: 2017/06/01 19:40:05 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	advance_rooms(t_mapdata mapdata,
		paths[mapdata.link2start][mapdata.num_rooms], trlist **room_arr)
{
	//advance all full rooms
	int i;
	int j;

	i = -1;
	// check each path starting from the end
	while (++i < mapdata.links2start)
	{
		j = mapdata.num_rooms - 1;
		while (paths[i][j] == -1 || paths[i][j] == mapdata.end_id)
			j--;
		if (room_arr[paths[i][j]]->ant_id)
		{
			//advance ant and print
			room_arr[paths][i][j + 1]->ant_id = room_arr[paths[i][j]]->ant_id;
			ft_printf("L%d-%s ", room_arr[paths[i][j + 1]]->ant_id,
					room_arr[paths[i][j + 1]]->name);
			room_arr[paths][i][j]->ant_id = 0;
		}
	}
}

static void	init_antdata(t_mapdata mapdata, t_antdata ants[mapdata.num_ants])
{
	int i;

	i = -1;
	while (++i < mapdata.num_ants)
		ants[i].in = 0;
}

static int	path_length(t_mapdata mapdata, int path[mapdata.num_rooms])
{
	int i;

	i = -1;
	while (++i < mapdata.num_rooms)
	{
		if (path[i] == -1)
			break ;
	}
	return (i);
}

static void	do_one_turn(t_mapdata mapdata,
		paths[mapdata.links2start][mapdata.num_rooms],
		t_antdata ants[mapdata.num_ants], trlist **room_arr)
{
	int a;
	int	new;
	int	paths[mapdata.num_paths];

	a = -1;
	new = 0;
	while (++a < mapdata.num_ants)
	{
		if (ants[a].in > 0)
		{
			ants[a].pos++;
			ft_printf("L%d-%s ", a + 1, room_arr[paths[ants[a].path_id][ants[a].pos]]->name);
			if (ants[a].pos == mapdata.end_id)
				ants[a].in = -1;
		}
		else if (!ants[a].in && new < mapdata.num_paths)
		{
			//send down path if:
			//first path or path length < remaining ants
			if (!new || mapdata.num_ants - a >=
					path_length(mapdata, paths[new]))
			{
				ants[a].in = 1;
				ants[a].path_id = new++;
				ft_printf("L%d-%s ", a + 1, room_arr[paths[ants[a].path_id][ants[a].pos]]->name);
			}
		}
		else
			break ;
	}
}

static int	done(t_mapdata mapdata, t_antdata ants[mapdata.num_ants])
{
	int i;

	i = -1;
	while (++i < num_ants)
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
		//advance_rooms(mapdata, paths, room_arr);
		//advance_new(&mapdata, paths, room_arr);

		do_one_turn(mapdata, paths, &ants, room_arr);
	}
}
