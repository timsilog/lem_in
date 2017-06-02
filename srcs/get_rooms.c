/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:18:43 by tjose             #+#    #+#             */
/*   Updated: 2017/06/01 16:42:50 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
 * no room
 * no start/end
 * accepts comments
 */

static void	add_room(t_rlist **room_list, int coord[2],
		char *name, t_cond cond)
{
	t_rlist		*temp;
	static int	id;

	if (!(temp = malloc(sizeof(t_rlist))))
		throw_error("ERROR: Memory error\n", *room_list);
	temp->name = name;
	temp->coord[0] = coord[0];
	temp->coord[1] = coord[1];
	temp->start = cond == c_start ? 1 : 0;
	temp->end = cond == c_end ? 1 : 0;
	temp->next = *room_list;
	temp->id = id++;
	temp->ant = 0;
	*room_list = temp;
}

static void	check_dupes(t_rlist *room_list, char *name, int coord[2])
{
	while (room_list)
	{
		if (!ft_strcmp(name, room_list->name))
			throw_error("ERROR: Duplicate room names\n", room_list);
		if (coord[0] == room_list->coord[0] && coord[1] == room_list->coord[1])
			throw_error("ERROR: Duplicate room coordinates\n", room_list);
		room_list = room_list->next;
	}
}

/*
** Returns 1 and creates the room if it's a valid room
** Returns 0 if there were no spaces indicating we're done reading rooms
*/

static int	valid_room(char **line, t_rlist **room_list, t_cond cond)
{
	int		size;
	char	*name;
	int		coord[2];

	size = 0;
	if (cond == c_start || cond == c_end)
	{
		get_next_line(0, line);
		ft_printf("%s\n", *line);
	}
	while ((*line)[size] && (*line)[size] != ' ')
		size++;
	if (size == (int)ft_strlen(*line))
		return (1);
	if (!size)
		throw_error("ERROR: Not a valid room", 0);
	coord[0] = lem_in_atoi(&(*line)[size + 1]);
	coord[1] = lem_in_atoi(&(*line)[size + 2 + ft_numlen(coord[0])]);
	if (!(name = malloc(sizeof(char) * size + 1)))
		throw_error("ERROR: Memory error", 0);
	name = ft_strncpy(name, *line, size);
	name[size] = '\0';
	check_dupes(*room_list, name, coord);
	add_room(room_list, coord, name, cond);
	return (0);
}

static void	check_rooms(char **line, int *start, int *end, t_rlist **room_list)
{
	int finished;

	while (get_next_line(0, line))
	{
		ft_printf("%s\n", *line);
		if (!ft_strcmp(*line, "##start"))
		{
			*start = 1;
			finished = valid_room(line, room_list, c_start);
		}
		else if (!ft_strcmp(*line, "##end"))
		{
			*end = 1;
			finished = valid_room(line, room_list, c_end);
		}
		else if ((*line)[0] == '#')
			continue ;
		else
			finished = valid_room(line, room_list, c_none);
		if (finished)
			return ;
	}
}

t_rlist		*get_rooms(char **line)
{
	int		start;
	int		end;
	t_rlist	*room_list;

	room_list = 0;
	start = 0;
	end = 0;
	check_rooms(line, &start, &end, &room_list);
	print_room_list(room_list);/////////////////////////
	if (!start || !end)
		throw_error("Error: Missing start or end", 0);
	return (room_list);
}
