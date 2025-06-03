/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 21:45:00 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 21:45:02 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

char	*ft_join_args(int argc, char **argv)
{
	char	*joined;
	int		i;
	char	*temp;

	joined = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		temp = ft_strjoin(joined, argv[i]);
		free(joined);
		joined = ft_strjoin(temp, " ");
		free(temp);
		i++;
	}
	return (joined);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (current->num == runner->num)
				return (1);
			runner = runner->next;
		}
		current = current->next;
	}
	return (0);
}

int	process_input(int argc, char **argv, t_stack **stack_a)
{
	char	*joined;

	if (argc == 2)
		*stack_a = ft_fill_stack(argv[1]);
	else
	{
		joined = ft_join_args(argc, argv);
		*stack_a = ft_fill_stack(joined);
		free(joined);
	}
	if (!*stack_a || has_duplicates(*stack_a))
		return (0);
	return (1);
}

static void	handle_two_nodes(t_stack **stack_a)
{
	if (!ft_is_sorted(*stack_a))
	{
		ft_printf("sa\n");
		sa(stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!validate_input(argc, argv) || !process_input(argc, argv, &stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		ft_stack_clear(&stack_a);
		return (1);
	}
	if (ft_is_sorted(stack_a))
		ft_stack_clear(&stack_a);
	else if (ft_stack_size(stack_a) == 2)
		handle_two_nodes(&stack_a);
	else if (ft_stack_size(stack_a) == 3)
		sort_three(&stack_a);
	else
		push_swap(&stack_a, &stack_b);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
