/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:51:53 by eviala            #+#    #+#             */
/*   Updated: 2024/07/05 11:16:50 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	ft_swap_bonus(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(str, "sa", 3))
	{
		swap(stack_a);
	}
	else if (!ft_strncmp(str, "sb", 3))
	{
		swap(stack_b);
	}
	else if (!ft_strncmp(str, "ss", 3))
	{
		swap(stack_a);
		swap(stack_b);
	}
}
