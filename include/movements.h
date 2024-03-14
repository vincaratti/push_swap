/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:23:51 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/13 14:21:33 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENTS_H
#define MOVEMENTS_H

# include "push_swap.h"
# include <stdlib.h>

int	push_a(list *a, list *b);
int	push_b(list *a, list *b);
int	rotate(list *stack);
int	r_rotate(list *stack);
int	d_rotate(list *a, list *b);
int	d_r_rotate(list *a, list *b);
int	swap(list *stack);
int	d_swap(list *a, list *b);

#endif
