/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlibft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:48:00 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/12 14:51:21 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTLIBFT_H
# define PRINTLIBFT_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./includes/libft.h"

int		ft_checkformat(va_list ap, char const *f, int *idx);
int		ft_isvalidformat(const char **format, va_list ap);
char	*ft_itoa_address(void *p, char *base);
char	*ft_itoa_hex(int n, char *base);
char	*ft_itoa_int(int n);
char	*ft_itoa_uint(unsigned int n);
void	ft_print_address(va_list ap, int *len);
void	ft_print_char(va_list ap, int *len);
void	ft_print_hex(va_list ap, int *len, int islower);
void	ft_print_int(va_list ap, int *len);
void	ft_print_percent(int *n);
void	ft_print_str(va_list ap, int *len);
void	ft_print_uint(va_list ap, int *len);
int		ft_printf(char const *format, ...);
char	*setbase(int n, int islower);

#endif
