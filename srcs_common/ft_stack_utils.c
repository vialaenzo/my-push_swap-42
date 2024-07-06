/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:11:57 by eviala            #+#    #+#             */
/*   Updated: 2024/07/03 12:34:13 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stremove_front(t_stack **stack)
{
	t_stack	*temp;

	if (stack && *stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	ft_stadd_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	ft_stadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stlast(*stack);
	last->next = new;
}

t_stack	*ft_stlast(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*ft_stnew(int content, int index)
{
	t_stack	*new;

	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->next = NULL;
	return (new);
}
