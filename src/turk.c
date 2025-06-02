/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:18:39 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 10:36:45 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_insert_position(t_stack *stack, int value)
{
	int		i;
	t_stack	*current;
	int		min_num;
	int		min_pos;

	if (!stack)
		return (0);
	i = 0;
	current = stack;
	min_num = current->num;
	min_pos = 0;
	while (current)
	{
		if (current->num < min_num)
		{
			min_num = current->num;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	i = 0;
	current = stack;
	while (current && current->next)
	{
		if (current->num < value && value < current->next->num)
			return (i + 1);
		current = current->next;
		i++;
	}
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

void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int	target;
	int	rot_b;
	int	size_b;
	int	rot_a;

	target = find_cheapest_value(*stack_a, *stack_b);
	if (target == -1)
		return ;
	rot_b = get_index(*stack_b, target);
	if (rot_b == -1)
	{
		return ;
	}
	size_b = ft_stack_size(*stack_b);
	if (rot_b > size_b / 2)
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
	rot_a = find_insert_position(*stack_a, target);
	rotate_to_top(stack_a, rot_a);
	pa(stack_a, stack_b);
	ft_printf("pa\n");
}

void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	ft_printf("pb\n");
}

void	push_until_three(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_b) > 0)
	{
		execute_cheapest_move(stack_a, stack_b);
	}
}

void	final_align(t_stack **stack_a)
{
	int	min_index;
	int	size;

	min_index = find_min_index(*stack_a);
	size = ft_stack_size(*stack_a);
	if (min_index <= size / 2)
	{
		while (min_index-- > 0)
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
	}
	else
	{
		while (min_index++ < size)
		{
			rra(stack_a);
			ft_printf("rra\n");
		}
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	initial_push(stack_a, stack_b);
	push_until_three(stack_a, stack_b);
	sort_three(stack_a);
	while (ft_stack_size(*stack_b) > 0)
		execute_cheapest_move(stack_a, stack_b);
	final_align(stack_a);
}
