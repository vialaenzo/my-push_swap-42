/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:58:02 by eviala            #+#    #+#             */
/*   Updated: 2024/07/05 11:16:09 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	push(t_stack **stack_a, t_stack **stack_b)
// {
// 	ft_stadd_front(stack_b, ft_stnew((*stack_a)->content));
// 	ft_stremove_front(stack_a);
// }

void	ft_push_bonus(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!(*stack_a) && !(*stack_b))
		return ;
	if (!ft_strncmp(str, "pa", 3))
	{
		if (!*stack_b)
			return ;
		ft_stadd_front(stack_a,
			ft_stnew((*stack_b)-> content, (*stack_b)->index));
		(*stack_a)->flag = (*stack_b)->flag;
		ft_stremove_front(stack_b);
	}
	else if (!ft_strncmp(str, "pb", 3))
	{
		if (!*stack_a)
			return ;
		ft_stadd_front(stack_b,
			ft_stnew((*stack_a)-> content, (*stack_a)->index));
		(*stack_b)->flag = (*stack_a)->flag;
		ft_stremove_front(stack_a);
	}
}
