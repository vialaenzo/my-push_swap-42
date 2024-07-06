/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:26:07 by eviala            #+#    #+#             */
/*   Updated: 2024/07/03 12:14:00 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_replace(t_stack **stack, int n, int to)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content == n)
			break ;
		tmp = tmp->next;
	}
	tmp->index = to;
}

int	min_nbr(t_stack **stack)
{
	t_stack		*tmp;
	long int	min;

	min = LONG_MAX;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_init_index(t_stack **stack)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = ft_stsize(*stack);
	while (i < len)
	{
		min = min_nbr(stack);
		index_replace(stack, min, i);
		i++;
	}
}
