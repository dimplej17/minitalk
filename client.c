// Create a client that sends a string to the server using signals.
// You encode each character into 8 bits, then send each bit one by one:
// Use SIGUSR1 to send a bit 0
// Use SIGUSR2 to send a bit 1

// Create the Client. It should:
// Take PID of server and a string as arguments.
// For each character:
// Convert the char to 8 bits.
// Send each bit one-by-one using kill() with:
// SIGUSR1 for 0
// SIGUSR2 for 1
// Wait a short time between each signal (e.g., usleep(100)).

#include "minitalk.h"

static void ft_send_char(pid_t pid_server, unsigned char c)
{
	int bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(pid_server, SIGUSR2);
		else
			kill(pid_server, SIGUSR1);
		usleep(100);
		bit--;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
		return (0); // do nothing? or should an error be displayed?
	pid_t pid_server; 
	pid_server = (pid_t)ft_atoi(argv[1]);
	if (pid_server <= 0)
		return (0); // invalid PID - should an error be displayed or doing nothing is ok?
	char *msg;
	msg = argv[2];
	int idx;
	idx = 0;
	while (msg[idx] != '\0')
	{
		ft_send_char(pid_server, (unsigned char)msg[idx]);
		idx++;
	}
	ft_send_char(pid_server, '\0'); // is this okay for a stop message?
	return (0);
}
