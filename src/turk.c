/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:18:39 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 11:49:01 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// remains because it is step 1
void	initial_push(t_stack **stack_a, t_stack **stack_b)
{
	pb(stack_a, stack_b);
	ft_printf("pb\n");
	pb(stack_a, stack_b);
	ft_printf("pb\n");
}

// remains becase it is step 2
void	push_until_three(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
		ft_printf("pb\n");
	}
}

// remains because it is step 4
void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	int	target;
	int	rot_b;
	int	size_b;
	int	rot_a;

	target = find_cheapest_push_to_a(*stack_a, *stack_b);
	if (target == -1)
		return ;
	rot_b = get_index(*stack_b, target);
	if (rot_b == -1)
		return ;
	size_b = ft_stack_size(*stack_b);
	rotate_target_to_top(rot_b, size_b, stack_b, target);
	rot_a = find_insert_position(*stack_a, target);
	rotate_to_top(stack_a, rot_a);
	pa(stack_a, stack_b);
	ft_printf("pa\n");
}

// remains because it is step 5
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

/*
Flow of mechanical Turk alg:
Blind push of two elements

*/
void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	initial_push(stack_a, stack_b);
	push_until_three(stack_a, stack_b);
	sort_three(stack_a);
	if (ft_stack_size(*stack_a) == 2 && !ft_is_sorted(*stack_a))
	{
		sa(stack_a);
		ft_printf("sa\n");
	}
	while (ft_stack_size(*stack_b) > 0)
		execute_cheapest_move(stack_a, stack_b);
	final_align(stack_a);
}
