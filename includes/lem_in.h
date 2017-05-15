/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:59:10 by tjose             #+#    #+#             */
/*   Updated: 2017/05/15 14:51:08 by tjose            ###   ########.fr       */
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
void				get_rooms(char **line, t_room **rooms);
void				get_link(char *line, t_room **rooms);
void				throw_error(char *msg);
void				free_rlist(t_rlist *room_list);


void print_room_list(t_rlist *room_list);
#endif
