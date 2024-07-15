/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:12:37 by eviala            #+#    #+#             */
/*   Updated: 2024/07/15 11:34:06 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_sort(t_stack **stack_a, t_stack **stack_b,
t_opt_sort *opsort, int count)
{
	int (i) = -1;
	while (++i < count)
	{
		if ((*stack_a)->index <= opsort->mid)
			ft_push("pb", stack_a, stack_b);
		else
		{
			if (ft_stsize(*stack_b) > 1
				&& (*stack_b)->index < (opsort->mid / 2))
				ft_rotate("rr", stack_a, stack_b);
			else
				ft_rotate("ra", stack_a, NULL);
		}
	}
	opsort->max = opsort->mid;
	opsort->mid = (opsort->max - opsort->next) / 2 + opsort->next;
	opsort->flag++;
}

void	find_the_next(t_stack **stack_a, t_stack **stack_b, t_opt_sort *opsort)
{
	if (ft_stsize(*stack_b) > 0 && ((*stack_b)->index == opsort->next))
		ft_push("pa", stack_a, stack_b);
	else if ((*stack_a)->index == opsort->next)
	{
		(*stack_a)->flag = -1;
		ft_rotate("ra", stack_a, NULL);
		opsort->next++;
	}
	else if ((ft_stsize(*stack_b)) > 2
		&& ft_stlast(*stack_b)->index == opsort->next)
		ft_reverse_rotate("rrb", NULL, stack_b);
	else if ((*stack_a)->next->index == opsort->next)
		ft_swap("sa", stack_a, NULL);
	else if ((ft_stsize(*stack_a)) > 1
		&& ((*stack_a)->next->index == opsort->next)
		&& ((*stack_b)->next->index == opsort->next + 1))
		ft_swap("ss", stack_a, stack_b);
	else
		return ;
	find_the_next(stack_a, stack_b, opsort);
}

void	quick_a(t_stack **stack_a, t_stack **stack_b, t_opt_sort *opsort)
{
	int (count_b) = ft_stsize(*stack_b);
	int (i) = -1;
	while (ft_stsize(*stack_b) && ++i < count_b)
	{
		if ((*stack_b)->index == opsort->next)
			find_the_next(stack_a, stack_b, opsort);
		else if ((*stack_b)->index >= opsort->mid)
		{
			(*stack_b)->flag = opsort->flag;
			ft_push("pa", stack_a, stack_b);
		}
		else if ((*stack_b)->index < opsort->mid)
			ft_rotate("rb", NULL, stack_b);
	}
	opsort->max = opsort->mid;
	opsort->mid = (opsort->max - opsort->next) / 2 + opsort->next;
	opsort->flag++;
}

void	quick_b(t_stack **stack_a, t_stack **stack_b, t_opt_sort *opsort)
{
	int (now_flag) = (*stack_a)->flag;
	if ((*stack_a)->flag != 0)
	{
		while ((*stack_a)->flag == now_flag)
		{
			if ((*stack_a)->index != opsort->next)
				ft_push("pb", stack_a, stack_b);
			find_the_next(stack_a, stack_b, opsort);
		}
	}
	else if ((*stack_a)->flag == 0)
	{
		while ((*stack_a)->flag != -1)
		{
			if ((*stack_a)->index != opsort->next)
				ft_push("pb", stack_a, stack_b);
			find_the_next(stack_a, stack_b, opsort);
		}
	}
	if (ft_stsize(*stack_b))
		opsort->max = (ft_stmax(stack_b))->index;
	opsort->mid = (opsort->max - opsort->next) / 2 + opsort->next;
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b, int count)
{
	t_opt_sort	opsort;

	opsort.next = ft_stmin(stack_a)->index;
	opsort.max = ft_stmax(stack_a)->index;
	opsort.mid = opsort.max / 2 + opsort.next;
	opsort.flag = 0;
	first_sort(stack_a, stack_b, &opsort, count);
	while (!(check_sort_a(stack_a, count)))
	{
		if (ft_stsize(*stack_b) == 0)
			quick_b(stack_a, stack_b, &opsort);
		else
			quick_a(stack_a, stack_b, &opsort);
	}
}
