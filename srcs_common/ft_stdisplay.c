/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdisplay.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:37:21 by eviala            #+#    #+#             */
/*   Updated: 2024/07/04 11:08:54 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stdisplay(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\nA  B\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%d ", stack_a->content);
			stack_a = stack_a->next;
		}
		else
			ft_printf(" ");
		if (stack_b)
		{
			ft_printf("%d\n", stack_b->content);
			stack_b = stack_b->next;
		}
		else
			ft_printf("\n");
	}
}

// int	get_int_length(int num)
// {
// 	int	length;

// 	length = 0;
// 	if (num <= 0)
// 	{
// 		length = 1; // For '0' or negative sign
// 	}
// 	while (num != 0)
// 	{
// 		length++;
// 		num /= 10;
// 	}
// 	return (length);
// }

// int	get_max_width(t_stack *stack)
// {
// 	int	max_width;
// 	int	len;

// 	max_width = 0;
// 	while (stack)
// 	{
// 		len = get_int_length(stack->content);
// 		if (len > max_width)
// 		{
// 			max_width = len;
// 		}
// 		stack = stack->next;
// 	}
// 	return (max_width);
// }

// void	print_aligned(int value, int width)
// {
// 	int	len;
// 	int	spaces;

// 	len = get_int_length(value);
// 	spaces = width - len;
// 	while (spaces-- > 0)
// 	{
// 		ft_printf(" ");
// 	}
// 	ft_printf("%d", value);
// }

// void	ft_stdisplay(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	width_a;
// 	int	width_b;
// 	int	gap;
// 	int	spaces_a;
// 	int	spaces;
// 	int	spaces_gap;

// 	width_a = get_max_width(stack_a);
// 	width_b = get_max_width(stack_b);
// 	gap = 2;
// 	ft_printf("\nA");
// 	spaces_a = width_a + gap - 1;
// 	while (spaces_a-- > 0)
// 		ft_printf(" ");
// 	ft_printf("B\n");
// 	while (stack_a || stack_b)
// 	{
// 		if (stack_a)
// 		{
// 			print_aligned(stack_a->content, width_a);
// 			stack_a = stack_a->next;
// 		}
// 		else
// 		{
// 			spaces = width_a;
// 			while (spaces-- > 0)
// 				ft_printf(" ");
// 		}
// 		spaces_gap = gap;
// 		while (spaces_gap-- > 0)
// 			ft_printf(" ");
// 		if (stack_b)
// 		{
// 			ft_printf("%d\n", stack_b->content);
// 			stack_b = stack_b->next;
// 		}
// 		else
// 		{
// 			ft_printf("\n");
// 		}
// 	}
// }
