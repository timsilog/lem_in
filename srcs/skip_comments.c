/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_comments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 11:22:30 by tjose             #+#    #+#             */
/*   Updated: 2017/06/02 11:24:55 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	skip_comments(char **line)
{
	while ((*line)[0] == '#')
	{
		get_next_line(0, line);
		ft_printf("%s\n", *line);
	}
}