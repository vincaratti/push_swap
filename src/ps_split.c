/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:50:12 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/14 16:10:07 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	is_whitespace(char c)
{
	if ((c >= 9  && c <= 13) || c == 32)
		return (1);
	return (0);
}

static int	get_array_len(const char *str)
{
	int	i;
	int	w_counter;
	int	w_len;

	i = 0;
	w_counter = 0;
	w_len = 0;
	while (str[i])
	{
		if (is_whitespace(str[i]) && w_len)
		{
			w_counter++;
			w_len = 0;
		}
		if (!is_whitespace(str[i]))
			w_len++;
		i++;
	}
	if (w_len)
		w_counter++;
	return (w_counter);
}

static int	fill_array(char const *s, char **array, int array_l)
{
	int		i;
	int		j;
	int		x;
	char	*n_word;

	i = 0;
	x = 0;
	while (i < array_l)
	{
		while (is_whitespace(s[x]))
			x++;
		j = 0;
		while (!is_whitespace(s[x + j]) && s[x + j] != '\0')
			j++;
		n_word = ft_substr(s, x, j);
		if (n_word == NULL)
			return (i);
		array[i] = n_word;
		while (s[x] != '\0' && !is_whitespace(s[x]))
			x++;
		i++;
	}
	return (-1);
}

static int	free_all(char **arr, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		free(arr[i++]);
	free(arr);
	return (-1);
}

int	ps_split(char ***ret, char const *s)
{
	int		array_l;
	int		ans;

	if (s == NULL)
		return (-1);
	array_l = get_array_len(s);
	*ret = malloc(sizeof(char *) * (array_l + 1));
	if (*ret == NULL)
		return (-1);
	(*ret)[array_l] = 0;
	ans = fill_array(s, *ret, array_l);
	if (ans != -1)
		return (free_all(*ret, ans - 1));
	return (array_l);
}
