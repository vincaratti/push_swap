/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:36:08 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/14 16:10:29 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
#define TOOLS_H

# include "list.h"
# include <stdlib.h>
# include "../libft/libft.h"

int	is_whitespace(char c);
int	init(list **stack, int *integers, int lenght);
list	*create_list(list **stack);
int	set_first_node(list *stack, int data);
void	insert_node(list *stack, node *temp);
node	*pop_node(list *stack);
int	ps_atoi(long int *result, const char *str);
int     ps_split(char ***ret, char const *s);

#endif
