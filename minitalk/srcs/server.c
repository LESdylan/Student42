/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:31:42 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 17:42:19 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *param)
{
	static char	c = 0;
	static int	bit = 7;
	static int	pid = 0;

	(void)param;
	if (signal == SIGUSR2)
		c = c | (1 << bit);
	if (pid == 0)
		pid = info->si_pid;
	kill(pid, SIGUSR2);
	bit--;
	if (bit < 0)
	{
		bit = 7;
		if (c == '\0')
		{
			c = 0;
			kill(pid, SIGUSR1);
			ft_printf("\n");
			pid = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	info;

	ft_printf("PID: %d\n", getpid());
	info.sa_flags = SA_SIGINFO;
	info.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &info, NULL) == -1)
    {
        ft_printf("Error: Could not set SIGUSR1 handler\n");
        return (1);
    }
    if (sigaction(SIGUSR2, &info, NULL) == -1)
    {
        ft_printf("Error: Could not set SIGUSR2 handler\n");
        return (1);
    }

	while (1)
		pause();
}