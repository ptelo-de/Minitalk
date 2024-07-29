/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:03:38 by hepereir          #+#    #+#             */
/*   Updated: 2024/05/02 16:19:56 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_print_hex(unsigned long nb, const char *arr)
{
	if (nb > 15)
	{
		ft_print_hex(nb / 16, arr);
		ft_print_hex(nb % 16, arr);
	}
	else
		ft_putchar(arr[nb]);
}

int	ft_print_p(unsigned long nb, const char *arr, int flag)
{
	if (nb > 0 && flag)
	{
		ft_print_s("0x");
		ft_print_hex(nb, arr);
		return (ft_ptr_len(nb) + 2);
	}
	else if (nb <= 0 && flag)
		return (ft_print_s("(nil)"));
	ft_print_hex(nb, arr);
	return (ft_ptr_len(nb));
}
