/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:34:24 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/14 11:34:27 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*nums;
	int	nums_len;

	if (treat_entry(argc, argv, &nums, &nums_len) == -1)
		return (0);
	int	counter = 0;
	printf("nums_len: %d\n", nums_len); 
	while (counter < nums_len)
	{
		printf("%d--[%d]\n", nums[counter], counter);
		counter++;
	}
	return (1);
	//left here
}
