//getppid() returns the process ID of the parent of the calling process. 
#include "minitalk.h"
void    ft_error(char *s)
{
    ft_putendl_fd(s,2);
    exit(1); //return 1 or -1?
}


//calculates the number an atribute can be translated
//does not allow buffer overflow or returning the number 
// if trash values follow the digit part.
// prints error message and terminates 
// the program with a status code of 1, 
// indicating error.
int ft_atoi3(const char *nptr)
{
    long long   nb;
    int i;

    nb = 0;
    i = 0;
    if (!nptr[0])
        ft_error("empty string in atoi input");
    while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
        i++;
    if (nptr[i] == '+' && nptr[i + 1] != 0)
        i++;
    while (nptr[i] <= '9' && nptr[i] >= '0')
    {
        if (nb * 10 < nb)
            ft_error("overflow in atoi input");
        nb = 10 * nb + (nptr[i] - 48);
        i++;
    }
    if (nptr[i] || nb > 2147483647 || nb < -2147483648)
        ft_error("n atoi input, integer overflow or wrong chars");
    return (nb);
}
void    ft_send_message(int pid, char *s)
{
    int i;
    int check_kill;

    while(*s)
    {

        i = 1;
        while(i++ <= 8)
        {
            if(*s & 1)
                check_kill = kill(pid, SIGUSR1);
            else
                check_kill = kill(pid, SIGUSR2);
            if(check_kill == -1)
                ft_error("kill function returned an error while sending signal to server");
            *s = *s >> 1;
            usleep(2000); //in microseconds 10^⁽⁻6) sec
        }
        s++;
    }
}
int main(int ac, char **av)
{

    if (ac == 3) 
    {
        ft_send_message(ft_atoi3(av[1]), av[2]);
    }
    else 
        ft_error("Too many or too little arguments");
}