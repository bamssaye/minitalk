/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:50:04 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/05 05:45:39 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>

# define HANDLERMSG "\nYou can't terminate the process, your msg not complete\n"
# define PIDERROR "Try: ./client <PID> \"MESSAGE YOU WANT TO SEND...\"\n"
# define PIDNOTV "The <PID> Not Valid, Please copy the PID from server.\n"
# define SERVERR "Run the Server without argument !!\n"
# define MESSGR "Your message was received by this server ID : "
# define INTMAX 2147483647

int					ft_isdigit(int c);
int					ft_atoi(char *str);
void				ft_putchar(int c);
void				ft_putnbr(int n);
void				ft_putstr(char *s);

#endif
