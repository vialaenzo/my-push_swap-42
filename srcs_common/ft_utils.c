/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:51:06 by eviala            #+#    #+#             */
/*   Updated: 2024/07/06 11:34:48 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

char	*join_with_space(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 2);
	if (!result)
		return (NULL);
	ft_strcpy(result, s1);
	result[len1] = ' ';
	ft_strcpy(result + len1 + 1, s2);
	return (result);
}

char	**full_split(int ac, char **av)
{
	char	*tmp;
	char	*new_tmp;
	char	**split;
	int		i;

	if (ac < 2)
		return (NULL);
	tmp = ft_strdup(av[1]);
	if (!tmp)
		return (NULL);
	i = 2;
	while (i < ac)
	{
		new_tmp = join_with_space(tmp, av[i]);
		free(tmp);
		if (!new_tmp)
			return (NULL);
		tmp = new_tmp;
		i++;
	}
	split = ft_split(tmp, ' ');
	free(tmp);
	return (split);
}

void	ft_free(char **strs)
{
	int (i) = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	ft_free_all(char **av, t_stack **stack_a, t_stack **stack_b)
{
	ft_free(av);
	ft_stclear(stack_a);
	ft_stclear(stack_b);
}
