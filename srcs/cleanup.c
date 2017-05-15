/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 18:36:06 by tjose             #+#    #+#             */
/*   Updated: 2017/05/15 14:07:40 by tjose            ###   ########.fr       */
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

void	throw_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(-1);
}
