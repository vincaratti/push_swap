/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:00:57 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/14 16:16:49 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"
#include <stdio.h>
static int	skip_spaces(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

static int	get_sign(const char *str, int *counter)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	while (str[*counter] == 45 || str[*counter] == 43)
	{
		if (str[*counter] == 45)
			sign = sign * -1;
		(*counter)++;
		i++;
	}
	if (i > 1)
		return (0);
	return (sign);
}

static int	check_lenght(const char *str, int start)
{
	int	i;

	i = start;
	while(str[i] && str[i] > 47 && str[i] < 58)
		i++;
	if (i - start > 13)
		return (0);
	return (1);
}

int	ps_atoi(long int *result, const char *str)
{
	int		counter;
	int		end_int;
	long int	sign;
	long int	multiplier;

	*result = 0;
	counter = skip_spaces(str);
	sign = get_sign(str, &counter);
	if (sign == 0 && check_lenght(str, counter) == 0)
		return (0);
	end_int = counter;
	while (str[end_int] > 47 && str[end_int] < 58)
		end_int++;
	multiplier = 1;
	*result = 0;
	if (sign == 0 && check_lenght(str, counter) == 0)
	while (end_int-- > counter)
	{
		*result = *result + ((str[end_int] - 48) * multiplier);
		multiplier = multiplier * 10;
	}
	if (sign == 0 && check_lenght(str, counter) == 0)
	if ((sign == -1 && *result > 2147483648) || (sign == 1 && *result > 2147483647))
		return (0);
	*result = *result * sign;
	return (1);
}
