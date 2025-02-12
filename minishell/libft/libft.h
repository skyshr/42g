/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 21:55:05 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/20 11:07:30 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# define MAX_SIZE 1025

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_env
{
	char			*name;
	char			*value;
	int				status;
	struct s_env	*next;
}	t_env;

char	*ft_itoa(int c);
int		ft_isparenthesis(int c);
int		ft_isoperand(int c);
int		ft_isredirection(int c);
int		ft_ispipe(char a, char b);
int		ft_isoper_or(char a, char b);
int		ft_issign(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
int		ft_isquote(int c);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
int		ft_lstadd_back(t_env **lst, t_env *new);
void	ft_lstadd_front(t_env **lst, t_env *new);
void	ft_lstclear(t_env **lst);
void	ft_lstdel_node(t_env **lst, t_env *prev, t_env *cur);
t_env	*ft_lstfind_node(t_env *lst, char *name);
t_env	*ft_lstlast(t_env *lst);
t_env	*ft_lstnew(char *key, char *value);
int		ft_lstsize(t_env *lst);

#endif
