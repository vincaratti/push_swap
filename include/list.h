/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:16:17 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/13 14:26:05 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H

typedef struct node {
	int		data;
	struct node	*next;
	struct node	*prev;
} node;

typedef struct list {
	int		length;
	struct node	*current;
} list;

#endif
