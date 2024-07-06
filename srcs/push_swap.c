/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:04:55 by eviala            #+#    #+#             */
/*   Updated: 2024/07/05 09:48:33 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int (size_a) = ft_stsize(*stack_a);
	if (its_sort(*stack_a))
		return ;
	if (size_a == 2)
	{
		ft_sort_two(stack_a);
	}
	else if (size_a == 3)
	{
		if (ft_isrevsort(*stack_a))
		{
			ft_swap("sa", stack_a, NULL);
			ft_reverse_rotate("rra", stack_a, NULL);
			return ;
		}
		ft_sort_three(stack_a);
	}
	else if (size_a <= 5)
		ft_sort_5nbr(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b, size_a);
}

int	main(int ac, char **av)
{
	t_stack (*stack_a) = NULL;
	t_stack (*stack_b) = NULL;
	if (ac <= 1 || !av)
		return (1);
	av = full_split(ac, av);
	if (!av)
		return (ft_free_all(av, &stack_a, &stack_b), ft_error());
	if (!checks(av))
		return (ft_free_all(av, &stack_a, &stack_b), ft_error());
	ft_fill_stack(&stack_a, av);
	ft_init_index(&stack_a);
	push_swap(&stack_a, &stack_b);
	ft_free_all(av, &stack_a, &stack_b);
	return (0);
}
