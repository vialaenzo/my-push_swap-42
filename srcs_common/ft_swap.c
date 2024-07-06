/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:51:53 by eviala            #+#    #+#             */
/*   Updated: 2024/06/24 13:50:37 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	ft_swap(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(str, "sa", 3))
	{
		ft_printf("sa\n");
		swap(stack_a);
	}
	else if (!ft_strncmp(str, "sb", 3))
	{
		ft_printf("sb\n");
		swap(stack_b);
	}
	else if (!ft_strncmp(str, "ss", 3))
	{
		ft_printf("ss\n");
		swap(stack_a);
		swap(stack_b);
	}
}
