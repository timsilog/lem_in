/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:40:07 by tjose             #+#    #+#             */
/*   Updated: 2016/12/05 14:12:13 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((!s1 && !s2) || !n)
		return (1);
	else if ((!s1 && s2) || (s1 && !s2))
		return (0);
	else if (!ft_strncmp(s1, s2, n))
		return (1);
	return (0);
}
