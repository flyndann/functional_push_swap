/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:19:48 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/03 11:20:05 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef struct s_vars
{
	int	min_num;
	int	max_num;
	int	min_pos;
	int	max_pos;
	int	i;
	int	size;
	int	next_num;
}		t_vars;

void	update_min(t_stack **current, int *min_num, int *min_pos, int *i)
{
	if ((*current)->num < *min_num)
	{
		*min_num = (*current)->num;
		*min_pos = *i;
	}
}

void	update_max(t_stack **current, int *max_num, int *max_pos, int *i)
{
	if ((*current)->num > *max_num)
	{
		*max_num = (*current)->num;
		*max_pos = *i;
	}
}

int	largest_or_smallest(int value, int *min_num, int *max_num, int *max_pos,
		int *size)
{
	if (value < *min_num)
		return ((*max_pos + 1) % *size);
	if (value > *max_num)
		return ((*max_pos + 1) % *size);
	return (-1);
}

int	find_insert_position(t_stack *stack, int value)
{
	t_stack *current;
	t_vars var;

	if (!stack)
		return (0);
	current = stack;
	var.min_num = current->num;
	var.max_num = current->num;
	var.min_pos = 0;
	var.max_pos = 0;
	var.i = 0;
	while (current)
	{
		update_min(&current, &var.min_num, &var.min_pos, &var.i);
		update_max(&current, &var.max_num, &var.max_pos, &var.i);
		current = current->next;
		var.i++;
	}
	var.size = var.i;
	if (value < var.min_num || value > var.max_num)
		return (largest_or_smallest(value, &var.min_num, &var.max_num,
				&var.max_pos, &var.size));
	var.i = 0;
	current = stack;
	while (current)
	{
		if (current->next)
			var.next_num = current->next->num;
		else
			var.next_num = stack->num;
		if (current->num < value && value < var.next_num)
			return ((var.i + 1) % var.size);
		current = current->next;
		var.i++;
	}
	return (0);
}