/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamssaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:31:06 by bamssaye          #+#    #+#             */
/*   Updated: 2024/02/01 14:27:44 by bamssaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_check(int sin, siginfo_t *info, void *str);
void    ft_header();

int main(int ac, char **av)
{
    struct sigaction action;
    
    (void)av;
    if(ac == 1)
    {
        ft_header();
        action.sa_sigaction = ft_check;
        action.sa_flags = SA_SIGINFO ;
        while (1)
        {
            sigaction(SIGUSR1, &action, NULL);
		    sigaction(SIGUSR2, &action, NULL);
            pause();
        }
    }
    else
        ft_printf("%s",SERVERR);
    return (0);
}
void    ft_check(int sin, siginfo_t *info, void *str)
{
    static int bit;
    static int c;

    (void)str;
    if (sin == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        if (c != '\0')
            ft_printf ("%c", c);
        else
            kill(info->si_pid, SIGUSR2);
        bit = 0;
        c = 0;
    }
}
void ft_header()
{
    int pid;
    
    pid = getpid();
    ft_printf("         ======================================================\n");
    ft_printf("         ==                    **MINITALK**                  ==\n");
    ft_printf("         ==                                                  ==\n");
    ft_printf("         ==   PID : %d                      By : Bamssaye ==\n", pid);
    ft_printf("         ======================================================\n\n\n");

}