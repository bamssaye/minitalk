/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 04:50:04 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/01 14:23:45 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINITALK_H
# define MINITALK_H

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "src/ft_printf/ft_printf.h"
#include "src/libft/libft.h"

#define PIDERROR "Use this prototype : ./client <PID> \"MESSAGE YOU WANT TO SEND...\"\n"
#define PIDNOTV "The <PID> Not Valid, Please copy the PID from server.\n"
#define SERVERR "Run the Server without argument !!\n"
#define MESSGR "Your message was received by this server ID "

# endif