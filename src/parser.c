/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:24:27 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/14 16:30:02 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>///

static int	add_space(char **str)
{
	char	*space = " ";

	*str = ft_strjoin(*str, space);
	if (!str)
		return (-1);
	return (0);
}

static int	concat_args(int argc, char **argv, char **res)
{
	int	counter;

	counter = 0;
	*res = ft_strdup(argv[1]);
	if (!*res)
		return (-1);
	if (add_space(res) == -1)
		return (-1);
	while (++counter + 1 < argc)
	{
		*res = ft_strjoin(*res, argv[counter + 1]);
		if (!*res)
			return (-1);
		if (add_space(res) == -1)
			return (-1);
	}
	return (0);
}

static int	verify_string(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (!ft_isdigit(str[counter]) && !is_whitespace(str[counter]))
				return (-1);
		counter++;
	}
	return (0);
}

static int	map_atoi(char **nums_str, int wc, int **nums)
{
	int	counter;
	int	res;
	int	ret;

	counter = 0;
	*nums = malloc(wc * sizeof(int));
	if (*nums == NULL)
		return (-1);

	printf("B\n");fflush(stdout);
	printf("Counter: %d, WC: %d\n", counter, wc);fflush(stdout);
	while (counter < wc)
	{
		printf("%d\n", counter);fflush(stdout);
		ret = ps_atoi((long *)&res, (const char *)nums_str[counter]);
		printf("-->%d", counter);
		if (ret == 0)
			return (-1);
		(*nums)[counter] = res;
		printf("wut");
		printf("counter: %d\n", counter);
		counter = counter + 1;
	}
	return (0);
}

int	treat_entry(int argc, char **argv, int **nums, int *nums_len)
{
	char	*str;
	char 	**nums_str;

	if (argc < 2)
		return (-1);
	if (concat_args(argc, argv, &str) == -1)
		return (-1);
	printf("\n->%s<-\n", str);
	if (verify_string(str) == -1)
		return (-1);
	printf("1\n");
	*nums_len = ps_split(&nums_str, str);
	printf("2\n");
	if (*nums_len == -1)
		return (-1);
	if (map_atoi(nums_str, *nums_len, nums) == -1)
		return (-1);
	printf("3\n");
	return (0);
}

