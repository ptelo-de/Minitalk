/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:10:36 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/08/28 22:38:30 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_realloc(char *s, char c)
{
	char	*result;
	int		l;

	if (!s)
		l = 0;
	else
		l = ft_strlen(s);
	result = malloc(sizeof(char) * (l + 2));
	if (!result)
		return (NULL);
	if (s)
		ft_strlcpy(result, s, l + 1);
	result[l++] = c;
	result[l] = 0;
	free(s);
	s = NULL;
	return (result);
}

// the above function appends a caracter to previous string,
//	handling memory reallocation

void	handle_sigusr1(int sig, siginfo_t *info, void *context)
{
	static int	pid_client;
	static char	c;
	static int	i;
	static char	*s;

	(void)context;
	pid_client = info->si_pid;
	if (sig == SIGUSR1)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			ft_printf("%s\n", s);
			free(s);
			s = NULL;
			kill(pid_client, SIGUSR2);
		}
		else
			s = ft_realloc(s, c);
		c = 0;
		i = 0;
	}
	kill(pid_client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handle_sigusr1;
	sa.sa_flags = SA_SIGINFO;
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
	while (1)
	{
		pause();
	}
	return (0);
}
// ler 32 bits, while i <= 32 salva no len.
// allocar s com len array
// coverter bits de cada caracter
// guardar cada caracter no array
// ft_putstr_fd()
// Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

//        sigaction(): _POSIX_C_SOURCE

//        siginfo_t: _POSIX_C_SOURCE >= 199309L
