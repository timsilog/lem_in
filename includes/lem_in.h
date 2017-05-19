/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:59:10 by tjose             #+#    #+#             */
/*   Updated: 2017/05/18 20:24:20 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct		s_rlist
{
	char			*name;
	int				coord[2];
	int				start;
	int				end;
	int				id;
	int				has_ant;
	struct s_rlist	*next;
}					t_rlist;
typedef struct		s_mapdata
{
	int				links2start;
	int				start_id;
	int				end_id;
	int				num_rooms;
	int				num_ants;
}					t_mapdata;
typedef enum
{
	c_none,
	c_start,
	c_end,
}	t_cond;

int					lem_in_atoi(const char *str);
t_rlist				*get_rooms(char **line);
void				get_links_and_solve(char *line, t_rlist *room_list, int num_ants);
void				throw_error(char *msg, t_rlist *room_list);
void				free_rlist(t_rlist *room_list);
void				get_paths(t_rlist *room_list, t_mapdata mapdata, int map[][n]);


void print_room_list(t_rlist *room_list);
void print_map(int n, int map[][n]);
#endif
