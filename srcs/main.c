/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:01:08 by tjose             #+#    #+#             */
/*   Updated: 2017/05/09 15:04:45 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*static void	get_rooms(char *line)
{
	add
}*/

static int	get_num_ants(char *line)
{
	int num_ants;

	get_next_line(0, &line);
	while (line[0] == '#')
		get_next_line(0, &line);
	num_ants = ft_atoi(line);
	ft_printf("%s\n%d\n",line,num_ants);
	return (num_ants);
}

int			main()
{
	char	*line;
	int		num_ants;
	//t_room	**rooms;

	line = 0;
	num_ants = get_num_ants(line);
	//get_rooms(line, rooms);
	//get_links(line, rooms);
	free(line);
	return (0);
}
