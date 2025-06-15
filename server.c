// Create the Server
// It should:
// Print its PID (so client knows where to send).
// Receive bits via SIGUSR1 and SIGUSR2.
// Reconstruct each character bit by bit (from LSB to MSB or vice versa — you pick a 
// consistent order).
// Reconstruct chars with bit shifting like:char |= (1 << bit_index);  // if bit is 1
// Print the character once all 8 bits are received.

#include "minitalk.h"

int main(void)
{
    pid_t pid_server;
    pid_server = getpid();
    ft_printf("PID of server: %i\n", pid_server);
    return (0);
}