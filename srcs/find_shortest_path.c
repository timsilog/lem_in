/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 14:44:14 by tjose             #+#    #+#             */
/*   Updated: 2017/06/01 15:26:37 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_shortest(t_mapdata mapdata,
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

static int	unused_room(int num_rooms, int current[num_rooms], int check)
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

void		find_shortest_path(t_mapdata mapdata,
		int map[][mapdata.num_rooms],
		int shortest[mapdata.num_rooms],
		int current[mapdata.num_rooms])
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	current[j] = mapdata.start_id;

	while (j > -1)
	{
		i++;
		if (map[current[j]][i] && unused_room(mapdata.num_rooms, current, i))
		{
			current[++j] = i;
			i = -1;
			if (current[j] == mapdata.end_id)
				check_shortest(mapdata, current, shortest);
		}
		while (i == mapdata.num_rooms - 1)
		{
			i = current[j];
			current[j--] = -1;
		}
	}
}
