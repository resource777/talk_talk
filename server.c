/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:43:05 by jaewonki          #+#    #+#             */
/*   Updated: 2022/03/16 15:10:53 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(void)
{
	pid_t	serverPID;

	serverPID = getpid();
	if (serverPID)
	{
		ft_putstr_fd("serverPID : ", 1);
		ft_putnbr_fd(serverPID, 1);
		ft_putstr_fd("\n", 1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}

void	handler(int sig)
{
	static char	receive = 0;
	static int	sendedBit = 0;

	receive <<= 1;
	if (sig == SIGUSR2)
		receive += 1;
	sendedBit++;
	if (sendedBit == 8)
	{
		ft_putchar_fd(receive, 1);
		receive = 0;
		sendedBit = 0;
	}
	return ;
}
