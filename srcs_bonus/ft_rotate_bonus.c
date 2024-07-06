/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:14 by eviala            #+#    #+#             */
/*   Updated: 2024/07/05 11:16:36 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	ft_stadd_back(stack, ft_stnew((*stack)->content, (*stack)->index));
	ft_stlast(*stack)->flag = (*stack)->flag;
	ft_stremove_front(stack);
}

void	ft_rotate_bonus(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(str, "ra", 3))
	{
		rotate(stack_a);
	}
	else if (!ft_strncmp(str, "rb", 3))
	{
		rotate(stack_b);
	}
	else if (!ft_strncmp(str, "rr", 3))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
