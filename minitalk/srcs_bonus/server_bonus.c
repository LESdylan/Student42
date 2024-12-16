/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:45:00 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 15:49:20 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

// Signal handler to receive and decode the incoming bits
void signal_handler(int signal, siginfo_t *info, void *param)
{
    static char c = 0;      // Current character being constructed
    static int bit = 7;     // Bit position (from 7 down to 0)
    static int pid = 0;     // PID of the client

    (void)param;

    // Initialize PID on first signal
    if (pid == 0)
        pid = info->si_pid;

    // Set the corresponding bit if SIGUSR2 is received (bit 1)
    if (signal == SIGUSR2)
        c = c | (1 << bit);

    // Acknowledge the received bit by sending SIGUSR2
    kill(pid, SIGUSR2);

    // Move to the next bit (decrement bit)
    bit--;

    // When all bits of the current character have been received
    if (bit < 0)
    {
        bit = 7;  // Reset bit counter for the next character

        // If the character is null (end of message), process it
        if (c == '\0')
        {
            // End of message: print newline, acknowledge and reset PID
            ft_printf("\n");
            kill(pid, SIGUSR1);  // Acknowledge completion of message
            pid = 0;              // Reset PID for next message
            return;
        }

        // Print the decoded character
        ft_printf("%c", c);
        c = 0;  // Reset the current character for the next one
    }
}

int main(void)
{
    struct sigaction info;

    // Display the server's PID for the client to send messages to
    ft_printf("Server PID: %d\n", getpid());

    // Set up the signal handler for SIGUSR1 and SIGUSR2 using sigaction
    info.sa_flags = SA_SIGINFO;
    info.sa_sigaction = signal_handler;

    // Register the signal handlers
    if (sigaction(SIGUSR1, &info, NULL) == -1)
    {
        ft_printf("Error: Failed to register SIGUSR1\n");
        return 1;
    }
    if (sigaction(SIGUSR2, &info, NULL) == -1)
    {
        ft_printf("Error: Failed to register SIGUSR2\n");
        return 1;
    }

    // The server runs indefinitely, waiting for signals
    while (1)
        pause();  // Wait for a signal to be received

    return 0;  // This will never be reached unless we forcefully terminate the program
}
