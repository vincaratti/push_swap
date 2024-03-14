/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:40:36 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/13 14:25:20 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

list *create_list(list **stack)
{
	if (*stack != NULL)
		return (*stack);
	*stack = malloc(sizeof(list));
	if (*stack == NULL)
		return (NULL);
	(*stack)->current = NULL;
	(*stack)->length = 0;
	return (*stack);
}

int	set_first_node(list *stack, int	data)
{
	node	*temp;

	temp = malloc(sizeof(node));
	if (temp == NULL)
		return (0);
	stack->current = temp;
	temp->data = data;
	temp->next = temp;
	temp->prev = temp;
	return (1);
}

void	insert_node(list *stack, node *temp)
{	
	temp->prev = stack->current->prev;
	temp->next = stack->current;
	stack->current->prev->next = temp;	
	stack->current->prev = temp;
	stack->current = temp;
}

node	*pop_node(list *stack)
{
	node	*ret;

	if (stack->current == NULL)
		return (NULL);
	ret = stack->current;
	stack->current->prev->next = stack->current->next;
	stack->current->next->prev = stack->current->prev;
	stack->current = stack->current->next;
	return (ret);
}

int init(list **stack, int *integers, int lenght)
{
	int	counter;
	node	*temp;	

	if (create_list(stack) == NULL || lenght == 0)
		return (0);
	if (set_first_node(*stack, integers[0]) == 0)
		return (0);
	counter = 1;
	while(counter < lenght)
	{
		temp = malloc(sizeof(node));
		if (temp == NULL)
			return (0);
		temp->data = integers[counter];
		insert_node(*stack, temp);
		counter++;
	}
	return (1);
}
