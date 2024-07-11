/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:17:31 by eviala            #+#    #+#             */
/*   Updated: 2024/07/11 14:47:00 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_rotate("ra", stack_a, NULL);
}

void	ft_sort_three(t_stack **stack_a)
{
	int (a) = (*stack_a)->index;
	int (b) = (*stack_a)->next->index;
	int (c) = (*stack_a)->next->next->index;
	if (its_sort(*stack_a))
		return ;
	if (a > b && b < c && a < c)
		ft_swap("sa", stack_a, NULL);
	else if (a > b && b > c)
	{
		ft_swap("sa", stack_a, NULL);
		ft_reverse_rotate("rra", stack_a, NULL);
	}
	else if (a > b && b < c && a > c)
		ft_rotate("ra", stack_a, NULL);
	else if (a < b && b > c && a < c)
	{
		ft_swap("sa", stack_a, NULL);
		ft_rotate("ra", stack_a, NULL);
	}
	else if (a < b && b > c && a > c)
		ft_reverse_rotate("rra", stack_a, NULL);
}

void	ft_sort_5nbr(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_a) > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
		{
			ft_push("pb", stack_a, stack_b);
		}
		else
		{
			ft_rotate("ra", stack_a, NULL);
		}
	}
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_push("pa", stack_a, stack_b);
		if ((*stack_a)->index > (*stack_a)->next->index)
			ft_swap("sa", stack_a, NULL);
	}
}

