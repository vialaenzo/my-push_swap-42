/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:40:41 by eviala            #+#    #+#             */
/*   Updated: 2024/07/05 12:45:30 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <limits.h>
# include "push_swap.h"

void	ft_push_bonus(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_rev_rotate_bonus(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_rotate_bonus(char *str, t_stack **stack_a, t_stack **stack_b);
void	ft_swap_bonus(char *str, t_stack **stack_a, t_stack **stack_b);

#endif
