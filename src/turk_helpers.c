/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:01:16 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 12:01:20 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	find_insert_position(t_stack *stack, int value)
{
	int		i;
	t_stack	*current;
	int		min_num;
	int		min_pos;
	int		max_num;

	if (!stack)
		return (0);
	i = 0;
	current = stack;
	min_num = current->num;
	max_num = current->num;
	min_pos = 0;
	// Find min and max values and min_pos
	while (current)
	{
		if (current->num < min_num)
		{
			min_num = current->num;
			min_pos = i;
		}
		if (current->num > max_num)
		{
			max_num = current->num;
		}
		current = current->next;
		i++;
	}
	// If value is less than min or greater than max, insert at min_pos
	if (value < min_num || value > max_num)
		return (min_pos);
	// Otherwise find the correct place between two consecutive nodes
	i = 0;
	current = stack;
	while (current && current->next)
	{
		if (current->num < value && value < current->next->num)
			return (i + 1);
		current = current->next;
		i++;
	}
	// Fallback to min_pos if no suitable position found
	return (min_pos);
}

void	rotate_to_top(t_stack **stack, int rotations)
{
	int	size;

	size = ft_stack_size(*stack);
	if (rotations <= size / 2)
	{
		while (rotations-- > 0)
		{
			ra(stack);
			ft_printf("ra\n");
		}
	}
	else
	{
		rotations = size - rotations;
		while (rotations-- > 0)
		{
			rra(stack);
			ft_printf("rra\n");
		}
	}
}

int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	cost_a;
	int	cost_b;
	int	size_b;

	cost_a = find_insert_position(stack_a, value);
	cost_b = get_index(stack_b, value);
	size_b = ft_stack_size(stack_b);
	if (cost_b > size_b / 2)
		cost_b = size_b - cost_b;
	return (cost_a + cost_b);
}

int	find_cheapest_value(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;
	int		min_cost;
	int		cheapest;
	int		cost;

	if (!stack_b)
		return (-1);
	current = stack_b;
	min_cost = INT_MAX;
	cheapest = 0;
	while (current)
	{
		cost = calculate_cost(stack_a, stack_b, current->num);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = current->num;
		}
		current = current->next;
	}
	return (cheapest);
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_b) > 0)
	{
		execute_cheapest_move(stack_a, stack_b);
	}
}
