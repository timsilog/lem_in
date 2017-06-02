/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:59:10 by tjose             #+#    #+#             */
/*   Updated: 2017/06/01 18:22:10 by tjose            ###   ########.fr       */
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
	int				ant_id;
	int				path_id;
	struct s_rlist	*next;
}					t_rlist;
typedef struct		s_mapdata
{
	int				links2start;
	int				start_id;
	int				end_id;
	int				num_rooms;
	int				num_ants;
	int				num_paths;
}					t_mapdata;
typedef struct		s_antdata
{
	int				path_id;
	int				pos;
}					t_antdata;
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
void				get_paths(t_rlist *room_list, t_mapdata mapdata, int map[][mapdata.num_rooms]);
void				find_shortest_path(t_mapdata mapdata,
		int map[][mapdata.num_rooms],
		int shortest[mapdata.num_rooms],
		int current[mapdata.num_rooms]);

//debug
void print_room_list(t_rlist *room_list);
void print_map(int n, int map[][n]);
void print_shortest(t_mapdata mapdata, int shortest[mapdata.num_rooms]);
void print_paths(t_mapdata mapdata, int paths[mapdata.links2start][mapdata.num_rooms]);
#endif
