/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjose <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 15:48:14 by tjose             #+#    #+#             */
/*   Updated: 2017/05/10 16:42:12 by tjose            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static long l_atoi(const char *str)
{
	long	num;
	int		count;
	int		neg_flag;

	count = 0;
	num = 0;
	neg_flag = 0;
	while (ft_is_wp(str[count]))
		count++;
	if (str[count] == '-')
	{
		neg_flag = 1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	while (ft_isdigit(str[count]))
	{
		num *= 10;
		num += (str[count] - 48);
		count++;
	}
	if (neg_flag)
		num = -num;
	return (num);
}

int			lem_in_atoi(const char *str)
{
	long	n;

	n = l_atoi(str);
	if (n > 2147483647)
		ft_printf("ERROR: Too many ants! (Exceeds max int)\n");
	else if (n < 0)
		ft_printf("ERROR: Negative ants!\n");
	else if (n == 0)
		ft_printf("ERROR: Invalid/No ants\n");
	else
		return (n);
	exit(-1);
}
