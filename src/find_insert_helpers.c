/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_insert_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 10:40:25 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/03 10:40:49 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	traverse_to_update_min(t_stack **current, int *min_num, int *min_pos,
		int *i)
{
	if ((*current)->num < *min_num)
	{
		*min_num = (*current)->num;
		*min_pos = *i;
	}
}
