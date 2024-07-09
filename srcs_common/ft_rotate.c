/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:39:14 by eviala            #+#    #+#             */
/*   Updated: 2024/07/09 15:18:23 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	if ((ft_stsize(*stack) < 2) || !(*stack))
		return ;
	ft_stadd_back(stack, ft_stnew((*stack)->content, (*stack)->index));
	ft_stlast(*stack)->flag = (*stack)->flag;
	ft_stremove_front(stack);
}

void	ft_rotate(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(str, "ra", 3))
	{
		ft_printf("ra\n");
		rotate(stack_a);
	}
	else if (!ft_strncmp(str, "rb", 3))
	{
		ft_printf("rb\n");
		rotate(stack_b);
	}
	else if (!ft_strncmp(str, "rr", 3))
	{
		ft_printf("rr\n");
		rotate(stack_a);
		rotate(stack_b);
	}
}
