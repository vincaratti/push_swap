/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:18:43 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/13 14:19:50 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "movements.h"

int	push_a(list *a, list *b)
{
	node	*temp;

	if (!a || !b || !b->current)
		return (0);
	temp = pop_node(b);
	if (temp == NULL)
		return (0);
	insert_node(a, temp);
	return (1);
}

int	push_b(list *a, list *b)
{
	node	*temp;

	if (!a || !b || !a->current)
		return (0);
	temp = pop_node(a);
	if (temp == NULL)
		return (0);
	insert_node(b, temp);
	return (1);
}

int	rotate(list *stack)
{
	if (!stack->current)
		return (0);
	if (!stack->current->next)
		return (0);
	stack->current = stack->current->next;
	return (1);
}

int	r_rotate(list *stack)
{
	if (!stack->current)
		return (0);
	if (!stack->current->prev)
		return (0);
	stack->current = stack->current->prev;
	return (1);
}

int	d_rotate(list *a, list *b)
{
	if (!a->current || !b->current)
		return (0);
	if (!a->current->next || !b->current->next)
		return (0);
	a->current = a->current->next;
	b->current = b->current->next;
	return (1);
}

int	d_r_rotate(list *a, list *b)
{
	if (!a->current || !b->current)
		return (0);
	if (!a->current->prev || !b->current->prev)
		return (0);
	a->current = a->current->prev;
	b->current = b->current->prev;
	return (1);
}

int	swap(list *stack)
{
	node	*temp_1;
	node	*temp_2;

	if (!stack->current)
		return (0);
	if (!stack->current->next)
		return (0);
	temp_1 = pop_node(stack);
	temp_2 = pop_node(stack);
	if (!temp_1 || !temp_2)
		return (0);
	insert_node(stack, temp_1);
	insert_node(stack, temp_2);
	return (1);
}

int	d_swap(list *a, list *b)
{
	if (swap(a) == 0 || swap(b) == 0)
		return (0);
	return (1);
}
