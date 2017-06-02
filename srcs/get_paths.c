/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:32:11 by tjose             #+#    #+#             */
/*   Updated: 2017/06/01 16:24:02 by tjose            ###   ########.fr       */
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

	if (!(room_arr = (t_rlist**)malloc(sizeof(t_rlist*) * mapdata->num_rooms)))
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
	while (++i < mapdata.links2start)
	{
		j = -1;
		while (++j < mapdata.num_rooms)
			paths[i][j] = -1;
	}
}

static void		remove_shortest_links(t_mapdata mapdata, int map[][mapdata.num_rooms], int shortest[mapdata.num_rooms])
{
	int i;

	i = -1;
	while (++i + 1 < mapdata.num_rooms && shortest[i + 1] != -1)
	{
		map[shortest[i]][shortest[i + 1]] = 0;
		map[shortest[i + 1]][shortest[i]] = 0;
	}
}

static void		find_paths(t_rlist *room_list, t_rlist **room_arr, t_mapdata mapdata, int map[][mapdata.num_rooms])
{
	int		paths[mapdata.links2start][mapdata.num_rooms];
	int		i;
	int		current[mapdata.num_rooms];

	i = -1;
	init_paths(mapdata, paths);
	while (++i < mapdata.links2start)
	{
		find_shortest_path(mapdata, map, paths[i], current);
		//print_shortest(mapdata, paths[i]);////////////////////////////////////////
		if (paths[0][0] < 0) // if no paths found 
			throw_error("ERROR: No paths found\n", room_list);
		remove_shortest_links(mapdata, map, paths[i]);
	}
	print_paths(mapdata, paths);///////////////////////
	i = 0;
	while (i < mapdata.links2start && paths[i][0] != -1)
		i++;
	mapdata.num_paths = i;
	solve(mapdata, paths, room_list, room_arr);
}

void			get_paths(t_rlist *room_list, t_mapdata mapdata, int map[][mapdata.num_rooms])
{
	int		i;
	t_rlist	**room_arr;

	room_arr = get_room_arr(room_list, &mapdata);
	i = -1;
	mapdata.links2start = 0;
	while (++i < mapdata.num_rooms)
		mapdata.links2start += map[mapdata.start_id][i];
	if (!mapdata.links2start)
		throw_error("ERROR: No paths found\n", room_list);
	find_paths(room_list, room_arr, mapdata, map);
}
