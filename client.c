
//getppid() returns the process ID of the parent of the calling process. 
#include "minitalk.h"

void    ft_sendbit(char **av)
{
    
}
//calculates the number an atribute can be translated
//does not allow buffer overflow or returning the number 
// if trash values follow the digit part.
// prints error message and terminates 
// the program with a status code of 1, 
// indicating error.
void	ft_error(void)
{
	write (2, "Error\n", 7);
	exit(1);
}
int	ft_atoi2(const char *nptr)
{
	long long	nb;
	int	i;
	int	sign;

	nb = 0;
	i = 0;
	sign = 1;
	if(!nptr[0])
		ft_error();
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		if (nb*10 < nb)
			ft_error();
		nb = 10 * nb + (nptr[i] - 48);
		i++;
	}
	nb = nb * sign;
	if (nptr[i] || nb > 2147483647 || nb < -2147483648)
		ft_error();
	return (nb);
}
int main(int ac, char **av)
{
    if (ac == 3)
        ft_sendbit(av);

    else
        ft_printf("The use of the programe is: ./client [VALID PID] [MESSAGE]\n");


}
/*
receber a string
send bit: mandar bit a bit string lengh + string
como ]e que vou mandar os bits? ver bitwise
como filtrar o range de pid?

*/