/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:34:20 by jaewonki          #+#    #+#             */
/*   Updated: 2022/03/13 19:14:56 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	serverPID;
	int	len;
	int	i;

	if (argc != 3)
	{
		ft_putstr_fd("Usage : ./client [serverPID] [string]\n", 1);
		return (0);
	}
	serverPID = ft_atoi(argv[1]);
	if (!(serverPID > 100 && serverPID < 100000))
		return (0);
	i = 0;
	len = ft_strlen(argv[2]);
	while (i < len)
	{
		formatWord(argv[2][i], serverPID);
		i++;
	}
	return (0);
}

void	formatWord(char word, int serverPID)
{
	unsigned char	num;
	int				idx;

	idx = 0;
	num = 0x80;
	while (idx < 8)
	{
		sendSignal(word & num, serverPID);
		num >>= 1;
		idx++;
	}
	return ;
}

void	sendSignal(int bit, int serverPID)
{
	if (bit)
		kill(serverPID, SIGUSR2);
	else
		kill(serverPID, SIGUSR1);
	usleep(100);
	return ;
}
