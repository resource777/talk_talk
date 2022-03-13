/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:39:52 by jaewonki          #+#    #+#             */
/*   Updated: 2022/03/06 19:39:52 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\f' || c == '\r' || c == '\v'
		|| c == ' ')
	{
		return (1);
	}
	return (0);
}

static void	ft_deletespace(char const *str, int *index)
{
	while (ft_isspace(str[*index]) == 1)
		(*index)++;
}

int	ft_atoi(char const *str)
{
	int	res;
	int	index;
	int	minus;
	int	middle;

	res = 0;
	index = 0;
	minus = 1;
	middle = 1;
	ft_deletespace(str, &index);
	if (str[index] == '-')
	{
		minus = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] != '\0')
	{
		if (!(str[index] >= '0' && str[index] <= '9'))
			break ;
		middle = str[index++] - '0';
		res = res * 10 + middle;
	}
	return (res * minus);
}
