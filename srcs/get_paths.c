/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:32:11 by tjose             #+#    #+#             */
/*   Updated: 2017/05/28 22:40:02 by tjose            ###   ########.fr       */
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

static void		check_shortest(t_mapdata mapdata,
		int current[mapdata.num_rooms], int shortest[mapdata.num_rooms])
{
	int len_c;
	int	len_s;
	int i;

	i = -1;
	len_c = 0;
	len_s = 0;
	while (++i < mapdata.num_rooms)
	{
		if (current[i] > -1)
			len_c++;
		if (shortest[i] > -1)
			len_s++;
	}
	if (len_c < len_s || !len_s)
	{
		i = -1;
		while (++i < mapdata.num_rooms)
			shortest[i] = current[i];
	}
}

static int		unused_room(int num_rooms, int current[num_rooms], int check)
{
	int	i;

	i = -1;
	while (++i < num_rooms)
	{
		if (current[i] == check)
			return (0);
	}
	return (1);
}

static void		remove_shortest_links(t_mapdata mapdata, int map[][mapdata.num_rooms], int shortest[mapdata.num_rooms])
{
	int i;

	i = -1;
	while (++i + 1 < mapdata.num_rooms)
	{
		map[shortest[i]][shortest[i + 1]] = 0;
		map[shortest[i + 1]][shortest[i]] = 0;
	}
}

static void		find_shortest_path(t_mapdata mapdata,
		int map[][mapdata.num_rooms],
		int current[mapdata.num_rooms],
		int shortest[mapdata.num_rooms])
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	current[j] = mapdata.start_id;

	// check current room for all possible links
	while (++i < mapdata.num_rooms)
	{
		// if current link exists, insert next room, otherwise
		// go through loop again with i++
		if (map[current[j]][i] && unused_room(mapdata.num_rooms, current, j))
		{
			current[++j] = i;
			i = -1;
			// if current room is the end room, check if shortest
			if (current[j] == mapdata.end_id)
			{
				check_shortest(mapdata, current, shortest);
				i = current[j--];
			}
		}
		if (i == mapdata.num_rooms)
			i = current[j--];
	}
}

static void		find_paths(t_rlist *room_list, t_rlist **room_arr, t_mapdata mapdata, int map[][mapdata.num_rooms])
{
	int		paths[mapdata.links2start][mapdata.num_rooms];
	int		i;
	int		shortest[mapdata.num_rooms];

	i = -1;
	init_paths(mapdata, paths);
	while (++i < mapdata.links2start)
	{
		find_shortest_path(mapdata, map, paths[i], shortest);
		if (shortest[0] < 0) // if no paths found 
			ft_printf("no paths found"); // actually do something about it..
		remove_shortest_links(mapdata, map, shortest);
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
		mapdata.links2start += map[mapdata.start_id][i];
	find_paths(room_list, room_arr, mapdata, map);
}
