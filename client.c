/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:49:58 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/05 05:37:23 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile/minitalk.h"

void	ft_sendbits(int pid, int c);
void	ft_checksinagl(void);
void	ft_handler(int sin);

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(av[1]);
	if (pid > INTMAX || pid == -1)
		return (ft_putstr(PIDNOTV), 0);
	ft_checksinagl();
	if (ac == 3)
	{
		if ((kill(pid, 0) != 0) || (pid == 0))
			return (ft_putstr(PIDNOTV), 0);
		while (av[2][i])
			ft_sendbits(pid, av[2][i++]);
		ft_sendbits(pid, '\n');
	}
	else
		ft_putstr(PIDERROR);
	return (0);
}

void	ft_checksinagl(void)
{
	signal(SIGINT, ft_handler);
	signal(SIGQUIT, ft_handler);
	signal(SIGTSTP, ft_handler);
}

void	ft_handler(int sin)
{
	if (sin == SIGINT || sin == SIGQUIT || sin == SIGTSTP)
		ft_putstr(HANDLERMSG);
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
		usleep(150);
		bit++;
	}
	usleep(100);
}
