/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:43:05 by jaewonki          #+#    #+#             */
/*   Updated: 2022/03/06 19:43:05 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	main(void)
{
	pid_t	serverPID;

	serverPID = getpid();
	if (serverPID)
	{
		ft_putnbr_fd(serverPID, 1);
		ft_putstr_fd("\n", 1);
	}
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);
	while (1)
		pause();
	return (0);
}

void	signalHandler(int sigNum)
{
	static char	receive = 0;
	static int	idx = 0;

	receive <<= 1;
	if (sigNum == SIGUSR1)
		receive += 0;
	else
		receive += 1;
	idx++;
	if (idx == 8)
	{
		ft_putchar_fd(receive, 1);
		receive = 0;
		idx = 0;
	}
	return ;
}
