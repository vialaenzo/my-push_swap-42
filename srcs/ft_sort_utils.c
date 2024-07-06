/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:57:37 by eviala            #+#    #+#             */
/*   Updated: 2024/07/04 13:31:50 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stmin(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack;
	min = *stack;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*ft_stmax(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *stack;
	max = *stack;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	its_sort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_isrevsort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->index < tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_sort_a(t_stack **stack_a, int count)
{
	int	len;

	len = ft_stsize(*stack_a);
	if (len != count)
		return (0);
	if (its_sort(*stack_a) == 0)
		return (0);
	return (1);
}
