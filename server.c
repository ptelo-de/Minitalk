#include "minitalk.h"
//getppid() returns the process ID of the parent of the calling process.
void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    (void)context;
    static int pid_client;
    pid_client = info->si_pid;
    (void)pid_client;
    ft_printf("Received SIGUSR1 signal with number: %d\n", sig);
}
int main(void)
{
    struct sigaction sa;
    sa.sa_sigaction = handle_sigusr1;  // Specify the handler function
    sa.sa_flags = 0;                 // No special flags
    sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        ft_printf("sigaction\n");
        exit(1);
    }
     ft_printf("PID: %d\n", getpid());
    while(1)
    {
        pause();
    }

}
//ler 32 bits, while i <= 32 salva no len.
//allocar s com len array
//coverter bits de cada caracter
//guardar cada caracter no array
//ft_putstr_fd()
// Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

//        sigaction(): _POSIX_C_SOURCE

//        siginfo_t: _POSIX_C_SOURCE >= 199309L
