/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaratti <vcaratti@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:26:11 by vcaratti          #+#    #+#             */
/*   Updated: 2024/03/13 14:29:00 by vcaratti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

# include "tools.h"
# include "../libft/libft.h"
# include <stdlib.h>

int	treat_entry(int argc, char **argv, int **nums, int *nums_len);

#endif
