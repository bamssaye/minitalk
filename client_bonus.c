/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:04 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/05 05:47:19 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile/minitalk_bonus.h"

int	g_serverid;

void	ft_sendbits(int pid, int c);
void	ft_checkmsg(int sin);
void	ft_checksinagl(void);

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (pid > INTMAX || pid == -1)
		return (ft_putstr(PIDNOTV), 0);
	g_serverid = pid;
	ft_checksinagl();
	if (ac == 3)
	{
		if ((kill(pid, 0) != 0) || pid == 0)
			return (ft_putstr(PIDNOTV), 0);
		while (av[2][i])
			ft_sendbits(pid, av[2][i++]);
		ft_sendbits(pid, '\n');
		ft_sendbits(pid, '\0');
	}
	else
		ft_putstr(PIDERROR);
	return (0);
}

void	ft_checksinagl(void)
{
	signal(SIGUSR1, ft_checkmsg);
	signal(SIGUSR2, ft_checkmsg);
	signal(SIGINT, ft_checkmsg);
	signal(SIGQUIT, ft_checkmsg);
	signal(SIGTSTP, ft_checkmsg);
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
		usleep(400);
		bit++;
	}
}

void	ft_checkmsg(int sin)
{
	if (sin == SIGUSR1 || sin == SIGUSR2)
	{
		ft_putstr(MESSGR);
		ft_putnbr(g_serverid);
		ft_putchar('\n');
	}
	if (sin == SIGINT || sin == SIGQUIT || sin == SIGTSTP)
		ft_putstr(HANDLERMSG);
}
