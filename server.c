
#include "minitalk.h"
char *ft_realloc(char *s, char c)
{
    char *result;
    int l;

    if(!s)
        l = 0;
    else
        l = ft_strlen(s);
    result = malloc(sizeof(char)*(l + 2));
    if(!result )
        return(NULL);
    if(s)
        ft_strlcpy(result, s, l + 1);
    result[l++] = c;
    result[l] = 0;
    free(s);
    s = NULL;
    return(result);
}
//the above function appends a caracter to previous string, handling memory reallocation

void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    (void)context;
    static int pid_client;
    pid_client = info->si_pid;
    (void)pid_client;
    static int c;
    static int i;
    static char *s;

    if (sig == SIGUSR1)
        c += (1 << i);
        //c >> (7 - i) = 1 >> 7:
        //c |= (1 << i);
    i++;
    if (i == 7)
    {
        if (c == 0)
            {
                ft_printf("%s\n", s);
                free(s);
                return;
            }
        s = ft_realloc(s, c);
        //ft_printf("%s\n",s);
        i = 0;
        c = 0;
    }

}
int main(void)
{
    struct sigaction sa;

    ft_printf("PID: %d\n", getpid());
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = handle_sigusr1;  // Specify the handler function
    sa.sa_flags = 0;                 // No special flags
    if (sigaction(SIGUSR1, &sa, NULL) == -1)
    {
        ft_printf("sigaction\n");
        exit(1);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        ft_printf("sigaction\n");
        exit(1);
    }
    while(1)
    {
        pause();//justify this instead of usllep()
    }
    return(0);
}
//ler 32 bits, while i <= 32 salva no len.
//allocar s com len array
//coverter bits de cada caracter
//guardar cada caracter no array
//ft_putstr_fd()
// Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

//        sigaction(): _POSIX_C_SOURCE

//        siginfo_t: _POSIX_C_SOURCE >= 199309L
