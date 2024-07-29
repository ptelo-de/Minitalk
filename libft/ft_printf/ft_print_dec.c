/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 14:52:17 by ptelo-de          #+#    #+#             */
/*   Updated: 2024/05/07 14:52:21 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_len(long nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

void	ft_print_dec(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_print_dec(nb / 10);
		ft_print_dec(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

int	ft_print_d(int nb)
{
	ft_print_dec(nb);
	return (ft_dec_len(nb));
}

int	ft_print_u(unsigned int nb)
{
	ft_print_dec(nb);
	return (ft_dec_len(nb));
}
