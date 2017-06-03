/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links_and_solve.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:30:01 by tjose             #+#    #+#             */
/*   Updated: 2017/06/02 13:30:48 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_id(int *id, char *name, t_rlist *room_list)
{
	t_rlist *temp;

	temp = room_list;
	while (room_list)
	{
		if (!ft_strcmp(room_list->name, name))
		{
			*id = room_list->id;
			return ;
		}
		room_list = room_list->next;
	}
	ft_printf("ERROR: Missing: %s\n", name);
	throw_error("Room name for link doesn't exist\n", temp);
}

static void	get_names(int *id1, int *id2, char *line,
		t_rlist *room_list)
{
	char	*name1;
	char	*name2;
	int		i;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	if (line[0] == '-' || !line[i] || !line[i + 1])
		throw_error("ERROR: Invalid link", room_list);
	if (!(name1 = malloc(sizeof(char) * i + 1)))
		throw_error("ERROR: Memory error", room_list);
	if (!(name2 = malloc(sizeof(char) * ft_strlen(&line[i + 1]) + 1)))
	{
		free(name1);
		throw_error("ERROR: Memory error", room_list);
	}
	name1 = ft_strncpy(name1, line, i);
	name1[i++] = '\0';
	name2 = ft_strcpy(name2, &line[i]);
	get_id(id1, name1, room_list);
	get_id(id2, name2, room_list);
	free(name1);
	free(name2);
}

static void	init_map(int n, int map[][n])
{
	int i;
	int j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			map[i][j] = 0;
	}
	return ;
}

void		get_links_and_solve(char *line, t_rlist *room_list, int num_ants)
{
	int			id1;
	int			id2;
	int			map[room_list->id + 1][room_list->id + 1];
	t_mapdata	mapdata;

	mapdata.num_rooms = room_list->id + 1;
	mapdata.num_ants = num_ants;
	init_map(mapdata.num_rooms, map);
	if (!line[0])
		throw_error("ERROR: No links\n", room_list);
	get_names(&id1, &id2, line, room_list);
	map[id1][id2] = 1;
	map[id2][id1] = 1;
	while (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
		if (line[0] == '#')
			continue ;
		get_names(&id1, &id2, line, room_list);
		map[id1][id2] = 1;
		map[id2][id1] = 1;
	}
	get_paths(room_list, mapdata, map);
}
