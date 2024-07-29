/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptelo-de <ptelo-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:51:42 by hepereir          #+#    #+#             */
/*   Updated: 2024/05/02 16:20:39 by ptelo-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_print_s(const char *str);
int		ft_dec_len(long nb);
void	ft_print_dec(long nb);
int		ft_print_d(int nb);
int		ft_print_u(unsigned int nb);
int		ft_ptr_len(unsigned long nb);
void	ft_print_hex(unsigned long nb, const char *arr);
int		ft_print_p(unsigned long nb, const char *arr, int flag);
int		ft_print_aux(const char *str, int i, va_list args);
int		ft_printf(const char *str, ...);

#endif