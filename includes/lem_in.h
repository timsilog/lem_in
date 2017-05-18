/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:59:10 by tjose             #+#    #+#             */
/*   Updated: 2017/05/17 17:16:28 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct		s_room
{
	int				has_ant;
	int				start;
	int				end;
	char			*name;
	int				num_links;
	struct s_room	**links;
	int				coord[2];
}					t_room;
typedef struct		s_rlist
{
	char			*name;
	int				coord[2];
	int				start;
	int				end;
	int				id;
	struct s_rlist	*next;
}					t_rlist;
typedef struct		s_llist
{
	t_rlist			*link;
	struct s_llist	*next;
}					t_llist;
typedef enum
{
	c_none,
	c_start,
	c_end,
}	t_cond;

int					lem_in_atoi(const char *str);
t_rlist				*get_rooms(char **line);
void				get_links(char *line, t_rlist *room_list);
void				throw_error(char *msg, t_rlist *room_list);
void				free_rlist(t_rlist *room_list);


void print_room_list(t_rlist *room_list);
void print_map(int n, int map[][n]);
#endif
