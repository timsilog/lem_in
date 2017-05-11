/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:18:43 by tjose             #+#    #+#             */
/*   Updated: 2017/05/10 18:03:19 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * no room
 * no start/end
 * accepts comments
 */

void		get_rooms(char *line)
{
	int	start;
	int	end;

	start = 0;
	end = 0;
	while (1)
	{
		get_next_line(0, &line);
		ft_printf("%s\n", line);
		if (!ft_strcmp(line, "##start"))
			start = 1;
		else if (!ft_strcmp(line, "##end"))
			end = 1;
		else if (line[0] == '#')
			continue ;
		else
			if (!valid_room(line))
			{
				ft_printf("ERROR: Not a valid room\n");
				exit(-1);
			}

	}

}
