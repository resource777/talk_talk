/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewonki <jaewonki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:35:22 by jaewonki          #+#    #+#             */
/*   Updated: 2022/03/06 19:35:22 by jaewonki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	send_message(int pid, char *message);
void	clienthandler(int signum, siginfo_t *siginfo, void *context);
void	decimal_to_bin(int pid, char message);
void	binary_to_decimal(int binary, int pid);
void	serverhandler(int signum, siginfo_t *siginfo, void *context);
int		ft_atoi(char const *str);
void	formatWord(char word, int serverPID);
void	sendSignal(int sig, int serverPID);
void	signalHandler(int sigNum);
