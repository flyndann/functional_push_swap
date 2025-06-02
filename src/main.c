/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daflynn <daflynn@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 10:54:25 by daflynn           #+#    #+#             */
/*   Updated: 2025/06/02 10:54:37 by daflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*joined;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		stack_a = ft_fill_stack(argv[1]);
	else if (argc > 2)
	{
		joined = ft_join_args(argc, argv);
		stack_a = ft_fill_stack(joined);
		free(joined);
	}
	if (ft_stack_size(stack_a) > 3)
		push_swap(&stack_a, &stack_b);
	else
		sort_three(&stack_a);
	ft_stack_clear(&stack_a);
	ft_stack_clear(&stack_b);
	return (0);
}
