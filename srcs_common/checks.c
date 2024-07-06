/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviala <eviala@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:26:35 by eviala            #+#    #+#             */
/*   Updated: 2024/06/25 11:20:49 by eviala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_isdigit(char **str)
{
	long	num;
	char	*endptr;

	int (i) = 0;
	int (j) = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) &&
			!ft_isplusminus(str[i][j]))
				return (0);
			else if (ft_isplusminus(str[i][j]) &&
			!ft_isdigit(str[i][j + 1]))
				return (0);
			j++;
		}
		num = ft_strlon(str[i], &endptr, 10);
		if (*endptr != '\0' || num < INT_MIN || num > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicate(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	checks(char **str)
{
	if (!check_isdigit(str) || !check_duplicate(str))
		return (0);
	return (1);
}
