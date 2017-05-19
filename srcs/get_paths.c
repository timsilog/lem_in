/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:32:11 by tjose             #+#    #+#             */
/*   Updated: 2017/05/18 21:47:30 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** # of links connected to start indicate max number of
** ants that can be deployed at a time (aka max # of paths).
** Finds the shortest path(s) up to max # of paths.
** Prioritizes shortest path(s) over reaching max # of paths.
**
** Total # moves = #ants / #paths + longest_path - 1
*/

static t_rlist	**get_room_arr(t_rlist *room_list, t_mapdata *mapdata)
{
	t_rlist	**room_arr;

	if (!(room_arr = (t_rlist*)malloc(sizeof(t_rlist) * num_rooms)))
		throw_error("ERROR: Memory error\n", room_list);
	while (room_list)
	{
		if (room_list->start)
			mapdata->start_id = room_list->id;
		if (room_list->end)
			mapdata->end_id = room_list->id;
		room_arr[room_list->id] = room_list;
		room_list = room_list->next;
	}
	return (room_arr);
}

static void		init_paths(t_mapdata mapdata,
		int paths[mapdata.links2start][mapdata.num_rooms])
{
	int	i;
	int j;

	i = -1;
	while (++i < mapdata.link2start)
	{
		j = -1;
		while (++j < mapdata.num_rooms)
			paths[i][j] = -1;
	}
}

static void		find_shortest_path(t_mapdata mapdata,
		int map[][mapdata.num_rooms],
		int current[mapdata.num_rooms], int shortest)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (current[j] < 0)
		j++;
	while (++i < mapdata.num_rooms)
	{
		if (!j)
			current[j] = mapdata.start_id;
		else
			if (map[
	}
}

static void		find_paths(t_rlist *room_list, t_rlist **room_arr, t_mapdata mapdata, int map[][mapdata.num_rooms])
{
	int		paths[mapdata.links2start][mapdata.num_rooms];
	int		i;
	int		shortest;

	i = -1;
	shortest = -1;
	init_paths(mapdata, paths);
	while (++i < mapdata.links2start)
	{
		find_shortest_path(mapdata, map, paths[i], shortest);
	}
}

void			get_paths(t_rlist *room_list, t_mapdata mapdata, int map[][mapdata.num_rooms])
{
	int		i;
	t_rlist	**room_arr;

	room_arr = get_room_arr(room_list, &mapdata);
	i = -1;
	mapdata.links2start = 0;
	while (++i < mapdata.num_rooms)
		mapdata.links2start += map[start_end[0]][i];
	find_paths(room_list, room_arr, mapdata, map);
}
