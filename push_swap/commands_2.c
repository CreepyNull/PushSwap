/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:13:54 by aylamgha          #+#    #+#             */
/*   Updated: 2024/08/19 09:13:55 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	func_rev_rotate(t_stack **stack, int flag)
{
	t_stack	*temp;
	t_stack	*last;
	t_stack	*prev;

	if (*stack && (*stack)->next)
	{
		last = ft_lstlast(*stack);
		temp = *stack;
		while (temp->next != last)
			temp = temp->next;
		prev = temp;
		temp = last;
		last = prev;
		last->next = NULL;
		temp->next = *stack;
		*stack = temp;
		if (flag == 1)
			ft_putstr_fd("rra\n", 1);
		else if (flag == 2)
			ft_putstr_fd("rrb\n", 1);
		else
			return ;
	}
}

void	func_rrr(t_stack **stack_a, t_stack **stack_b, int flag)
{
	func_rev_rotate(stack_a, 3);
	func_rev_rotate(stack_b, 3);
	if (flag == 1)
		ft_putstr_fd("rrr\n", 1);
	else
		return ;
}
