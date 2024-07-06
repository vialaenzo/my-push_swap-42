/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:58:02 by eviala            #+#    #+#             */
/*   Updated: 2024/07/04 14:03:23 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	push(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_stadd_front(stack_b, ft_stnew((*stack_a)->content));
// 	ft_stremove_front(stack_a);
// }

void	ft_push(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) && !(*stack_b))
		return ;
	if (!ft_strncmp(str, "pa", 3))
	{
		if (!*stack_b)
			return ;
		ft_printf("pa\n");
		ft_stadd_front(stack_a,
			ft_stnew((*stack_b)-> content, (*stack_b)->index));
		(*stack_a)->flag = (*stack_b)->flag;
		ft_stremove_front(stack_b);
	}
	else if (!ft_strncmp(str, "pb", 3))
	{
		if (!*stack_a)
			return ;
		ft_printf("pb\n");
		ft_stadd_front(stack_b,
			ft_stnew((*stack_a)-> content, (*stack_a)->index));
		(*stack_b)->flag = (*stack_a)->flag;
		ft_stremove_front(stack_a);
	}
}
