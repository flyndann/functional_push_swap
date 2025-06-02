/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:07:43 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 11:07:44 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_is_hogback(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !stack->next || !stack->next->next)
		return (0);
	a = stack->num;
	b = stack->next->num;
	c = stack->next->next->num;
	if (b > c && b > a && a < c)
		return (1);
	else
		return (0);
}

void	sort_three(t_stack **stack)
{
	if (ft_is_sorted(*stack))
		return ;
	if (ft_is_reversed(*stack))
	{
		ra(stack);
		sa(stack);
		ft_printf("ra\nsa\n");
	}
	else if (ft_is_hogback(*stack))
	{
		rra(stack);
		sa(stack);
		ft_printf("rra\nsa\n");
	}
	else
	{
		single_case(stack);
	}
}

// Each remaining case needs only one op and each of the remaining cases has the max in a different position
// Thus the appropriate operation can be determined from the position of the max alone
void	single_case(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->num;
	second = (*stack)->next->num;
	third = (*stack)->next->next->num;
	if (second > first && second > third)
	{
		rra(stack);
		ft_printf("rra\n");
	}
	else if (third > second && third > first)
	{
		sa(stack);
		ft_printf("sa\n");
	}
	else
	{
		ra(stack);
		ft_printf("ra\n");
	}
}
