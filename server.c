/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:50:01 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/02 17:57:58 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile/minitalk.h"

void	ft_check(int sin);
void	ft_header(void);

int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac == 1)
	{
		ft_header();
		while (1)
		{
			signal(SIGUSR1, ft_check);
			signal(SIGUSR2, ft_check);
		}
	}
	else
		ft_putstr(SERVERR);
	return (0);
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
}

void	ft_header(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("\t\t===================  **MINITALK**  ===================\n");
	ft_putstr("\t\t==                                                  ==\n");
	ft_putstr("\t\t                             By : Bamssaye        \n");
	ft_putstr("\t\t   PID :");
	ft_putnbr(pid);
	ft_putstr("                                          \n");
	ft_putstr("\t\t==                                                  ==\n");
	ft_putstr("\t\t======================================================\n\n");
}
