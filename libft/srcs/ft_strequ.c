/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:43:57 by tjose             #+#    #+#             */
/*   Updated: 2016/12/01 15:47:03 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (1);
	else if ((!s1 && s2) || (s1 && !s2))
		return (0);
	else if (!ft_strcmp(s1, s2))
		return (1);
	return (0);
}