/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:04 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/02 18:00:43 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile/minitalk_bonus.h"

int		g_serverid;

void	ft_sendbits(int pid, int c);
void	ft_checkmsg(int sin);

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	g_serverid = pid;
	if (ac == 3)
	{
		if ((kill(pid, 0) != 0) || pid == 0)
			return (ft_putstr(PIDNOTV), 0);
		signal(SIGUSR1, ft_checkmsg);
		signal(SIGUSR2, ft_checkmsg);
		while (av[2][i])
			ft_sendbits(pid, av[2][i++]);
		if (!av[2][i])
			ft_sendbits(pid, av[2][i]);
		ft_sendbits(pid, '\n');
	}
	else
		ft_putstr(PIDERROR);
	return (0);
}

void	ft_sendbits(int pid, int c)
{
	int	bit;

	bit = 0;
	while (bit <= 7)
	{
		if ((c >> bit & 1) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
	usleep(200);
}

void	ft_checkmsg(int sin)
{
	(void)sin;
	ft_putstr(MESSGR);
	ft_putnbr(g_serverid);
	ft_putchar('\n');
}
