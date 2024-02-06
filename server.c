/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:50:01 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/05 05:47:15 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile/minitalk.h"

int	g_serverid;

void	ft_check(int sin);
void	ft_header(void);
void	ft_singal(void);

int	main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		ft_header();
		while (1)
		{
			ft_singal();
		}
	}
	else
		ft_putstr(SERVERR);
	return (0);
}

void	ft_singal(void)
{
	signal(SIGUSR1, ft_check);
	signal(SIGUSR2, ft_check);
	signal(SIGINT, ft_check);
	signal(SIGQUIT, ft_check);
	signal(SIGTSTP, ft_check);
}

void	ft_check(int sin)
{
	static int	bit;
	static int	c;

	if (sin == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(c);
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
