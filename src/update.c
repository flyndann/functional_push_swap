/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:07:50 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 11:07:52 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "pushswap.h"

void	ft_append_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*tail;

	if (!*stack)
	{
		*stack = new_node;
		new_node->head = new_node;
		new_node->tail = new_node;
	}
	else
	{
		tail = (*stack)->tail;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->head = (*stack)->head;
		(*stack)->tail = new_node;
	}
}

void	ft_prepend_node(t_stack **stack, t_stack *new_node)
{
	if (!*stack)
	{
		*stack = new_node;
		new_node->head = new_node;
		new_node->tail = new_node;
	}
	else
	{
		new_node->next = *stack;
		new_node->prev = new_node;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

void	ft_push(t_stack **stack, t_stack *new_node)
{
	t_stack	*current;

	if (!new_node)
		return ;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (*stack)
	{
		new_node->head = (*stack)->head;
		new_node->tail = (*stack)->tail;
		(*stack)->prev = new_node;
		current = new_node;
		while (current)
		{
			current->head = new_node;
			current = current->next;
		}
	}
	else
	{
		new_node->head = new_node;
		new_node->tail = new_node;
	}
	*stack = new_node;
}
