/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:01:08 by tjose             #+#    #+#             */
/*   Updated: 2017/05/14 21:29:50 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Throws error if num_ants:
** -Exceeds max int
** -Is less than 1
*/

static int	get_num_ants(char *line)
{
	int num_ants;

	get_next_line(0, &line);
	ft_printf("%s\n", line);
	while (line[0] == '#')
	{
		get_next_line(0, &line);
		ft_printf("%s\n", line);
	}
	num_ants = lem_in_atoi(line);
	return (num_ants);
}
// fix it when there's nothing on std input
int			main()
{
	char	*line;
	int		num_ants;
	t_room	**rooms;

	rooms = 0;
	line = 0;
	num_ants = get_num_ants(line);
	get_rooms(&line, rooms);
	//get_links(&line, rooms);
	free(line);
	return (0);
}
