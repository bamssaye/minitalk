/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:50:04 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/02 17:50:00 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

# define PIDERROR "Try: ./client <PID> \"MESSAGE YOU WANT TO SEND...\"\n"
# define PIDNOTV "The <PID> Not Valid, Please copy the PID from server.\n"
# define SERVERR "Run the Server without argument !!\n"
# define MESSGR "Your message was received by this server ID "

int     ft_strlen(char *str);
void    ft_putstr(char *str);
int     ft_isdigit(int c);
int     ft_atoi(char *str);
void    ft_putchar(int c);
void	ft_putnbr(int n);

#endif