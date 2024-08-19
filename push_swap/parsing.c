/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aylamgha <aylamgha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:14:19 by aylamgha          #+#    #+#             */
/*   Updated: 2024/08/19 13:46:25 by aylamgha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"

char	**get_values(char **av, int ac)
{
	char			**holder;
	int				i;
	unsigned int	num_vals;

	i = 1;
	num_vals = 0;
	holder = NULL;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0 || count_words(av[i], ' ') == 0)
			free_all(NULL, holder, 0);
		num_vals += count_words(av[i++], ' ');
	}
	holder = ft_split_numbers(av, ac, num_vals);
	if (!holder)
		free_all(NULL, holder, 1);
	return (holder);
}

void	create_stack(t_stack **stack_a, char **strings)
{
	int			i;
	int long	num;

	i = 0;
	while (strings[i])
	{
		if (checking_syntax(strings[i]))
			free_all(stack_a, strings, 1);
		num = ft_atoi(strings[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_all(stack_a, strings, 1);
		ft_lstadd_back(stack_a, ft_lstnew((int)num));
		if (check_dub(*stack_a, num))
			free_all(stack_a, strings, 1);
		i++;
	}
	free_func(strings);
}

void	free_func(char **strings)
{
	int	i;

	i = 0;
	if (NULL == strings || NULL == *strings)
		return ;
	while (strings[i])
		free(strings[i++]);
	free(strings);
}

void	free_all(t_stack **stack_a, char **strings, int flag)
{
	ft_lstclear(stack_a);
	if (flag)
		free_func(strings);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

char	**ft_split_numbers(char **av, int ac, int size)
{
	char	**temp;
	char	**temp2;
	char	**strings;
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (size == 0)
		return (NULL);
	strings = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strings)
		return (NULL);
	while (i < ac)
	{
		temp = ft_split(av[i++], ' ');
		if (!temp)
			return (NULL);
		temp2 = temp;// store the address to get freed after .
		while (*temp)
			strings[j++] = *temp++;
		free(temp2);
	}
	strings[j] = NULL;
	return (strings);
}
