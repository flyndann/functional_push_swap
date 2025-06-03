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

// rotates target to the top of be using the minimum number of rotations
void	rotate_target_to_top(int rot_b, int size_b, t_stack **stack_b,
		int target)
{
	if ((rot_b) > (size_b) / 2)
	{
		while ((*stack_b)->num != target)
		{
			rrb(stack_b);
			ft_printf("rrb\n");
		}
	}
	else
	{
		while ((*stack_b)->num != target)
		{
			rb(stack_b);
			ft_printf("rb\n");
		}
	}
}

int	calculate_cost(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	cost_a;
	int	cost_b;
	int	size_a;
	int	size_b;

	cost_a = find_insert_position(stack_a, value);
	cost_b = get_index(stack_b, value);
	size_a = ft_stack_size(stack_a);
	size_b = ft_stack_size(stack_b);
	if (cost_a > size_a / 2)
		cost_a = size_a - cost_a;
	if (cost_b > size_b / 2)
		cost_b = size_b - cost_b;
	return (cost_a + cost_b);
}

// find the element which requires the fewest total operations
// to place in stack_a
int	find_cheapest_push_to_a(t_stack *stack_a, t_stack *stack_b)
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

// an exact mirror image of its sister
int	find_cheapest_push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	return (find_cheapest_push_to_a(stack_b, stack_a));
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
