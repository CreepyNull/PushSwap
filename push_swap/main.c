/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:14:55 by aylamgha          #+#    #+#             */
/*   Updated: 2024/08/19 16:21:45 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**strings;

	if (ac == 1)
		return (1); 
	stack_a = NULL;
	stack_b = NULL;
	strings = get_values(av, ac);
	create_stack(&stack_a, strings);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
