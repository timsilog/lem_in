/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:48:14 by tjose             #+#    #+#             */
/*   Updated: 2017/05/11 18:44:49 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int lem_in_atoi(const char *str)
{
	long	num;
	int		count;
	int		neg_flag;

	count = 0;
	num = 0;
	while (ft_is_wp(str[count]))
		count++;
	neg_flag = str[count] == '-' ? 1 : 0;
	if (str[count] == '-' || str[count] == '+')
		count++;
	while (ft_isdigit(str[count]))
		num = num * 10 + (str[count++] - 48);
	num = neg_flag ? -num : num;
	if ((str[count] && str[count] != ' ') || num > 2147483647 || num < 0)
		throw_error("ERROR: invalid number");
	return ((int)num);
}
