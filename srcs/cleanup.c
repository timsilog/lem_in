/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:36:06 by tjose             #+#    #+#             */
/*   Updated: 2017/05/17 16:59:30 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_rlist(t_rlist *room_list)
{
	t_rlist *temp;

	while (room_list)
	{
		temp = room_list;
		room_list = room_list->next;
		free(temp->name);
		free(temp);
	}
}

void	throw_error(char *msg, t_rlist *room_list)
{
	if (room_list)
		free_rlist(room_list);
	ft_printf("%s\n", msg);
	exit(-1);
}
