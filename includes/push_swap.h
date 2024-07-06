/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:04:53 by eviala            #+#    #+#             */
/*   Updated: 2024/07/04 13:32:27 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_opt_sort
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}		t_opt_sort;

typedef struct s_stack
{
	int				content;
	int				index;
	int				flag;
	struct s_stack	*next;
}		t_stack;
// Checks
t_stack	*ft_stmax(t_stack **stack);
t_stack	*ft_stmin(t_stack **stack);
int		checks(char **str);
int		ft_error(void);
// Stack
int		ft_stsize(t_stack *stack);
int		check_sort_a(t_stack **stack1, int count);
int		its_sort(t_stack *stack);
int		ft_isrevsort(t_stack *stack);
t_stack	max_find(t_stack *stack);
t_stack	min_find(t_stack *stack);
// int		ft_strstr_len(char **str);
// Move
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_rotate(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_push(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a, t_stack **stack_b, int count);
// Sorts
void	ft_sort_two(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
// void	ft_sort_4nbr(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_5nbr(t_stack **stack_a, t_stack **stack_b);
// Index
void	ft_init_index(t_stack **stack);
// STACK FONCTIONS
t_stack	*ft_stnew(int content, int index);
t_stack	*ft_stlast(t_stack *stack);
void	ft_stdisplay(t_stack *stack_a, t_stack *stack_b);
void	ft_stadd_back(t_stack **stack, t_stack *new);
void	ft_stdelone(t_stack *stack, void (*del)(void*));
void	ft_stadd_front(t_stack **stack, t_stack *new);
void	ft_stclear(t_stack **stack);
void	ft_stremove_front(t_stack **stack );
void	ft_fill_stack(t_stack **stack, char **av);
void	ft_free(char **strs);
void	ft_free_all(char **av, t_stack **stack_a, t_stack **stack_b);
char	**full_split(int ac, char **av);

#endif
