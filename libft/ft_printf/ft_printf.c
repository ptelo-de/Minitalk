/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:03:50 by hepereir          #+#    #+#             */
/*   Updated: 2024/05/02 16:18:22 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (ft_print_s("(null)"));
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	ft_print_aux(const char *str, int i, va_list args)
{
	int	count;

	count = 0;
	i++;
	if (str[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		count += ft_print_s(va_arg(args, const char *));
	else if (str[i] == 'p')
		count += ft_print_p(va_arg(args, unsigned long), "0123456789abcdef", 1);
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_print_d(va_arg(args, int));
	else if (str[i] == 'u')
		count += ft_print_u(va_arg(args, unsigned int));
	else if (str[i] == 'x')
		count += ft_print_p(va_arg(args, unsigned int), "0123456789abcdef", 0);
	else if (str[i] == 'X')
		count += ft_print_p(va_arg(args, unsigned int), "0123456789ABCDEF", 0);
	else if (str[i] == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_print_aux(str, i, args);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 0)
			return (-1);
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
