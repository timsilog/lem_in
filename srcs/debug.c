/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 21:43:21 by tjose             #+#    #+#             */
/*   Updated: 2017/06/02 11:29:33 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_room_list(t_rlist *room_list)
{
	while (room_list)
	{
		ft_printf("id%d: name: %s\n",
				room_list->id, room_list->name);
		if (room_list->start)
			ft_printf("start^^^\n");
		if (room_list->end)
			ft_printf("end^^^\n");
		room_list = room_list->next;
	}
}

void	print_map(int n, int map[][n])
{
	int i = -1;
	int j;

	ft_printf("   ");
	while (++i < n)
		ft_printf("%d ", i);
	ft_printf("\n");
	i = -1;
	while (++i < n)
	{
		j = -1;
		ft_printf("%d: ", i);
		while (++j < n)
			ft_printf("%d ", map[i][j]);
		ft_printf("\n");
	}
}

void	print_shortest(t_mapdata mapdata, int shortest[mapdata.num_rooms])
{
	int i = -1;

	while (++i < mapdata.num_rooms)
	{
		ft_printf("%d ", shortest[i]);
	}
	ft_printf("\n");
}

void	print_paths(t_mapdata mapdata, int paths[mapdata.links2start][mapdata.num_rooms])
{
	int i = -1;
	while (++i < mapdata.links2start)
	{
		ft_printf("path %d: ", i);
		print_shortest(mapdata, paths[i]);
	}
}
