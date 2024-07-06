/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:39:25 by eviala            #+#    #+#             */
/*   Updated: 2024/07/06 11:39:00 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if ((!*stack) || (ft_stsize(*stack) < 2))
		return ;
	tmp = *stack;
	last = ft_stlast(*stack);
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_stadd_front(stack, last);
}

void	ft_reverse_rotate(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strncmp(str, "rra", 4))
	{
		ft_printf("rra\n");
		reverse_rotate(stack_a);
	}
	else if (!ft_strncmp(str, "rrb", 4))
	{
		ft_printf("rrb\n");
		reverse_rotate(stack_b);
	}
	else if (!ft_strncmp(str, "rrr", 4))
	{
		ft_printf("rrr\n");
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}
