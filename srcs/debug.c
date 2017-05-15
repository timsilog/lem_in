/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 21:43:21 by tjose             #+#    #+#             */
/*   Updated: 2017/05/14 21:19:32 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_room_list(t_rlist *room_list)
{
	while (room_list)
	{
		ft_printf("name: %s\ncoord: %d,%d\n", room_list->name, room_list->coord[0], room_list->coord[1]);
		if (room_list->start)
			ft_printf("start^^^\n");
		if (room_list->end)
			ft_printf("end^^^\n");
		room_list = room_list->next;
	}
}