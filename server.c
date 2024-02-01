/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:50:01 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/01 21:17:04 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile/minitalk.h"

void	ft_check(int sin);
void	ft_header(vod);

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
		ft_printf("%s", SERVERR);
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
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

void	ft_header(void)
{
	int	pid;

	pid = getpid();
	ft_printf("======================================================\n");
	ft_printf("==                    **MINITALK**                  ==\n");
	ft_printf("==                                                  ==\n");
	ft_printf("==   PID : %d                      By : Bamssaye ==\n", pid);
	ft_printf("======================================================\n\n\n");
}
