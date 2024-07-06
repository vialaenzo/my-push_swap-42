/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:29:42 by eviala            #+#    #+#             */
/*   Updated: 2024/07/04 11:08:41 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stsize(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_stclear(t_stack **stack)
{
	int (len) = ft_stsize(*stack);
	if (stack)
	{
		while (len != 0)
		{
			ft_stremove_front(stack);
			len--;
		}
	}
}

void	ft_fill_stack(t_stack **stack, char **av)
{
	int (i) = 0;
	while (av[i])
	{
		ft_stadd_back(stack, ft_stnew(ft_atoi(av[i]), -1));
		i++;
	}
}

t_stack	min_find(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	min;

	tmp = stack;
	min = *stack;
	while (tmp)
	{
		if (tmp->content < min.content)
			min = *tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	max_find(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	max;

	tmp = stack;
	max = *stack;
	while (tmp)
	{
		if (tmp->content > max.content)
			max = *tmp;
		tmp = tmp->next;
	}
	return (max);
}
