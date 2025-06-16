// Create the Server
// It should:
// Print its PID (so client knows where to send).
// Receive bits via SIGUSR1 and SIGUSR2.
// Reconstruct each character bit by bit (from LSB to MSB or vice versa — you pick a 
// consistent order).
// Reconstruct chars with bit shifting like:char |= (1 << bit_index);  // if bit is 1
// Print the character once all 8 bits are received.

// to check git logs: git log | grep -i "commit" | wc -l

#include "minitalk.h"

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int				bit_index = 0;
	static unsigned char	char_accumulator = 0;

	(void)context;
	(void)info;
	char_accumulator <<= 1;

	if (sig == SIGUSR1)
		char_accumulator |= 0;
	else if (sig == SIGUSR2)
		char_accumulator |= 1;

	bit_index++;

	if (bit_index == 8)
	{
		write(1, &char_accumulator, 1);
		bit_index = 0;
		char_accumulator = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
    pid_t pid_server;
    pid_server = getpid();
    ft_printf("Server PID: %d\n", pid_server);

	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
}
