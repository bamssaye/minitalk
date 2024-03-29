/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:25:41 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/03 00:41:47 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headerfile/minitalk_bonus.h"

void	ft_putstr(char *str);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
void	ft_putchar(int c);
void	ft_putnbr(int n);

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *nptr)
{
	int	i;
	int	p;
	int	n;

	i = 0;
	p = 1;
	n = 0;
	if (!nptr)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-')
		p *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (ft_isdigit(nptr[i]))
		n = 10 * n + nptr[i++] - 48;
	if (nptr[i] != '\0')
		return (0);
	return (n * p);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar((nb + 48));
	}
	else
	{
		ft_putnbr(((nb / 10)));
		ft_putchar(((nb % 10) + 48));
	}
}
