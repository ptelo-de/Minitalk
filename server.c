#include "minitalk.h"
//getppid() returns the process ID of the parent of the calling process.
int main(void)
{
    ft_printf("PID: %d\n", getpid());
}