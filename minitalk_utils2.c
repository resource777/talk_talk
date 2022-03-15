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

int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\f' || c == '\r' || c == '\v'
		|| c == ' ')
		return (1);
	return (0);
}

void	ft_delspace(char const *s, int *i)
{
	while (ft_isspace(s[*i]))
		(*i)++;
}

int	ft_atoi(char const *s)
{
	int	res;
	int	i;
	int	minus;
	int	digit;

	res = 0;
	i = 0;
	minus = 1;
	ft_delspace(s, &i);
	if (s[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] != '\0')
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			break ;
		digit = s[i++] - '0';
		res = res * 10 + digit;
	}
	return (res * minus);
}
