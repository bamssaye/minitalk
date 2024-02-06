/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:06 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/05 05:47:09 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile/minitalk_bonus.h"

int	g_serverid;

void	ft_check(int sin, siginfo_t *info, void *str);
void	ft_header(void);
void	ft_singalhandler(void);

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		ft_header();
		ft_singalhandler();
		while (1)
		{
			pause();
		}
	}
	else
		ft_putstr(SERVERR);
	return (0);
}

void	ft_singalhandler(void)
{
	struct sigaction	action;

	action.sa_sigaction = ft_check;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGTSTP, &action, NULL);
}

void	ft_check(int sin, siginfo_t *info, void *str)
{
	static int	bit;
	static int	c;

	(void)str;
	if (sin == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(c);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		bit = 0;
		c = 0;
	}
	if (sin == SIGINT || sin == SIGQUIT || sin == SIGTSTP)
		kill (g_serverid, SIGKILL);
}

void	ft_header(void)
{
	int	pid;

	pid = getpid();
	g_serverid = pid;
	ft_putstr("\t\t===================  **MINITALK**  ===================\n");
	ft_putstr("\t\t==                                                  ==\n");
	ft_putstr("\t\t                             By : Bamssaye        \n");
	ft_putstr("\t\t   PID :");
	ft_putnbr(pid);
	ft_putstr("                                          \n");
	ft_putstr("\t\t==                                                  ==\n");
	ft_putstr("\t\t======================================================\n\n");
}
