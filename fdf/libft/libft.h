/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:55:05 by ksuh              #+#    #+#             */
/*   Updated: 2024/02/27 16:00:39 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# define MAX_SIZE 1025

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

size_t	get_read_bytes(char *lst, int *is_end);
char	*read_buffer(int fd, char *lst, char *buffer, int *is_end);
char	*strjoin(char *src1, char *src2, size_t bytesize);
char	*get_next_line(int fd);
void	reset(char *lst, size_t readbytes);
int		ft_atoi(const char *s);
int		ft_max(int x, int y);
int		ft_min(int x, int y);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_atoi_base(char *str, char *base);

#endif
