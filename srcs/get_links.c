/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 21:30:01 by tjose             #+#    #+#             */
/*   Updated: 2017/05/16 15:30:37 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_names(char **name1, char **name2, char *line, t_rlist *room_list)
{
	int i;

	i = 0;
	while (line[i] != '-')
		i++;
	if (!line[i])
	{
		free_rlist(room_list);
		throw_error("ERROR: Invalid link");
	}
	if (!(*name1 = malloc(sizeof(char) * i)) || !(*name2 =
				malloc (sizeof(char) * ft_strlen(&line[i + 1]))))
	{
		free_rlist(room_list);
		throw_error("ERROR: Memory error");
	}
	*name1 = ft_strncpy(*name1, line, i);
	(*name1)[i] = '\0';


}

void	get_links(char *line, t_room **rooms)
{
	char	*name1;
	char	*name2;
	t_llist	*link_list;

	if (!line[0])
		throw_error("ERROR: No links\n");
	get_names(&name1, &name2, link);
	
}
