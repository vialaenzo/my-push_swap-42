make/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:40:50 by eviala            #+#    #+#             */
/*   Updated: 2024/07/06 11:40:45 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	lexer(char *input, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(input, "sa\n", 3) == 0)
		ft_swap_bonus("sa", stack_a, stack_b);
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		ft_swap_bonus("sb", stack_a, stack_b);
	else if (ft_strncmp(input, "ss\n", 3) == 0)
		ft_swap_bonus("ss", stack_a, stack_b);
	else if (ft_strncmp(input, "pa\n", 3) == 0)
		ft_push_bonus("pa", stack_a, stack_b);
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		ft_push_bonus("pb", stack_a, stack_b);
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		ft_rotate_bonus("ra", stack_a, stack_b);
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		ft_rotate_bonus("rb", stack_a, stack_b);
	else if (ft_strncmp(input, "rr\n", 3) == 0)
		ft_rotate_bonus("rr", stack_a, stack_b);
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		ft_rev_rotate_bonus("rra", stack_a, stack_b);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		ft_rev_rotate_bonus("rrb", stack_a, stack_b);
	else if (ft_strncmp(input, "rrr\n", 4) == 0)
		ft_rev_rotate_bonus("rrr", stack_a, stack_b);
	else
		return (free(input), 0);
	return (free(input), 1);
}

int	input(t_stack **stack_a, t_stack **stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (!lexer(input, stack_a, stack_b))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		input = get_next_line(0);
	}
	return (1);
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

int	main(int ac, char **av)
{
	t_stack (*stack_a) = NULL;
	t_stack (*stack_b) = NULL;
	if (ac <= 1 || !av)
		return (1);
	av = full_split(ac, av);
	if (!av)
		return (ft_free_all(av, &stack_a, &stack_b), ft_error());
	if (!checks(av))
		return (ft_free_all(av, &stack_a, &stack_b), ft_error());
	ft_fill_stack(&stack_a, av);
	if (input(&stack_a, &stack_b))
	{
		if (its_sort(stack_a) && !stack_b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	ft_free_all(av, &stack_a, &stack_b);
	return (0);
}
