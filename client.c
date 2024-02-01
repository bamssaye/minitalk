/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:49:58 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/01 21:17:14 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headerfile/minitalk.h"

oid	ft_sendbits(int pid, int c);

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac == 3)
	{
		if ((kill(pid, 0) != 0) || (pid == 0))
			return (ft_printf("%s", PIDNOTV));
		while (av[2][i])
			ft_sendbits(pid, av[2][i++]);
		ft_sendbits(pid, '\n');
	}
	else
		ft_printf("%s", PIDERROR);
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
		usleep(150);
		bit++;
	}
	usleep(100);
}
