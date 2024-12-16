/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:45:06 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 15:48:27 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

static volatile sig_atomic_t g_mutex = 0; // For signal synchronization

// Function to send a single character to the server
void send_signal(char c, int pid)
{
    int i;
    int bit;

    i = 8;  // We are sending the character bit by bit (8 bits)
    while (i-- > 0)
    {
        g_mutex = 0;  // Reset mutex for synchronization
        bit = (c >> i) & 1;  // Extract the current bit (either 0 or 1)
        
        // Send the corresponding signal based on the bit
        if (bit == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        
        // Wait until the server acknowledges the bit
        while (g_mutex == 0)
            usleep(100);  // Small sleep to avoid busy-waiting
    }
}

// Signal handler to receive acknowledgment and track received bits
void signal_handler(int signal)
{
    static int bits = 0;

    if (signal == SIGUSR2) // The server is acknowledging the bit (1)
    {
        bits++;
        g_mutex = 1;  // Set mutex to indicate acknowledgment
    }
    else if (signal == SIGUSR1) // End of message, server acknowledges completion
    {
        ft_printf("Bits received: %d\n", bits);
        exit(0);  // Exit after receiving complete message
    }
}

int main(int argc, char **argv)
{
    size_t i;
    char *str;
    int pid;

    // Ensure correct number of arguments
    if (argc != 3 || !ft_strlen(argv[2]))
    {
        ft_printf("Error: Invalid arguments. Usage: ./client PID message\n");
        return 1;
    }

    // Validate the PID
    pid = ft_atoi(argv[1]);
    if (pid <= 0)
    {
        ft_printf("Error: Invalid server PID\n");
        return 1;
    }

    // Set up the signal handler to handle both SIGUSR1 and SIGUSR2
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);

    str = argv[2];  // Get the message from the command-line arguments
    i = 0;

    // Send each character in the message to the server
    while (str[i] != '\0')
    {
        send_signal(str[i], pid);
        i++;
    }

    // After the message is sent, continue waiting for the acknowledgment
    while (1)
        pause();  // Wait for signals from the server

    return 0;
}
