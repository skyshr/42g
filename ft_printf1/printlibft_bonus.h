/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlibft_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:00:22 by ksuh              #+#    #+#             */
/*   Updated: 2024/03/13 22:00:35 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTLIBFT_BONUS_H
# define PRINTLIBFT_BONUS_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./includes/libft.h"

typedef struct s_print
{
	int	*flag;
	int	width;
	int	precision;
	int	length;
}	t_print;

void	ft_checkflag(t_print *print, char const *format, int *idx);
int		ft_checkformat(va_list ap, t_print *print, char const *f, int *idx);
void	ft_checklength(t_print *print, char const *format, int *idx);
void	ft_checkprecision(t_print *print, char const *format, int *idx);
void	ft_checkwidth(t_print *print, char const *format, int *idx);
int		ft_isvalidformat(const char **format, va_list ap);
char	*ft_itoa_address(void *p, char *base);
char	*ft_itoa_hex(int n, char *base);
char	*ft_itoa_int(int n);
char	*ft_itoa_uint(unsigned int n);
void	ft_print_address(va_list ap, t_print *print, int *len);
void	ft_print_char(va_list ap, t_print *print, int *len);
void	ft_print_hex(va_list ap, t_print *print, int *len, int islower);
void	ft_print_int(va_list ap, t_print *print, int *len);
void	ft_print_percent(int *n);
void	ft_print_str(va_list ap, t_print *print, int *len);
void	ft_print_uint(va_list ap, t_print *print, int *len);
void	ft_printc(t_print *print, char c);
int		ft_printf(char const *format, ...);
void	ft_printh(t_print *print, char *s, int n, char *sign);
void	ft_printi(t_print *print, char *s, int n, int size);
void	ft_printp(t_print *print, char *s);
void	ft_prints(t_print *print, char *s);
void	ft_printu(t_print *print, char *s, int size);
int		ft_setprint(t_print *print);
void	ft_setstate(va_list ap, t_print *print);
void	handle_length(t_print *print, int *size);
void	print_inti_nneg(t_print *print, char *s, int size);
void	print_inti_npos(t_print *print, char *s, int size);
void	print_inti_yneg(t_print *print, char *s, int size);
void	print_inti_ypos(t_print *print, char *s, int size);
void	print_nhex(t_print *print, char *s, int size, char *sign);
void	print_yhex(t_print *print, char *s, int size, char *sign);
void	setaddr(t_print *print, char *s, int *len);
char	*setbase(int n, int islower);
void	setchar(t_print *print, int *len);
void	sethex(t_print *print, int n, int size, int *len);
void	setint(t_print *print, int n, int size, int *len);
void	setstr(t_print *print, char *s, int *len);
void	setuint(t_print *print, int n, int size, int *len);

#endif
