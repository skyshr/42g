/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksuh <ksuh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:36:45 by ksuh              #+#    #+#             */
/*   Updated: 2024/06/28 21:12:12 by ksuh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define SUCCESS 	0
# define FAIL 		1
# define SIGINT		2
# define SIGQUIT	3
# define SIGINTERR	130
# define SIGQUITERR 131
# define EXEC		"./minishell"

# include "libft/libft.h"

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <term.h>
# include <sys/wait.h>
# include <ctype.h>

/* t_token Type Enumeration */
typedef enum e_tokentype
{
	TOKEN_STRING,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_DOUBLE_OUT,
	TOKEN_REDIR_DOUBLE_IN,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_ERROR,
	TOKEN_EOF
}	t_tokentype;

/* t_token Structure */
typedef struct s_token
{
	t_tokentype	type;
	char		*value;
}				t_token;

/* t_lexer Structure */
typedef struct s_lexer
{
	char	*text;
	int		position;
	int		bracket_num;
	int		is_bracket_closed;
	t_token	token;
}			t_lexer;

/* Node Type Enumeration */
typedef enum e_nodetype
{
	NODE_COMMAND,
	NODE_PIPE,
	NODE_REDIR_IN,
	NODE_REDIR_OUT,
	NODE_REDIR_DOUBLE_OUT,
	NODE_REDIR_DOUBLE_IN,
	NODE_AND,
	NODE_OR,
	NODE_ERROR,
	NODE_EOF
}	t_nodetype;

/* t_treenode Structure */
typedef struct s_treenode {
	t_nodetype			type;
	char				*command;
	char				**arguments;
	int					arg_count;
	struct s_treenode	*left;
	struct s_treenode	*right;
	int					start_bracket;
	int					end_bracket;
	int					is_closed_prev;
}						t_treenode;

/* t_parser Structure */
typedef struct s_parser
{
	t_lexer	lexer;
}	t_parser;

typedef struct s_pipex
{
	int		dupin;
	int		dupout;
	int		save_fdin;
	int		save_fdout;
	int		status;
	int		child_count;
	int		oper_status;
	int		exit;
	int		is_pipe;
	int		is_heredoc;
}	t_pipex;

typedef struct s_minishell
{
	struct s_pipex	*pipex;
	struct s_env	*head;
	t_treenode		*root;
	t_treenode		*tmp_root;
	t_treenode		*command_tree;
	int				treenode_num;
	t_treenode		*cur_treenode;
	t_treenode		*root_treenode;
	int				node_type;
	int				exe_num;
	int				exit;
	int				isexit;
	char			*exit_str;
}	t_minishell;

/* ft_parser.c */
void		change_tree(t_treenode *root, t_minishell *ms);
t_treenode	*do_parse_input(t_minishell *ms, char *input);
t_token		get_next_token(t_lexer *lexer);
t_treenode	*parse_command(t_parser *parser);
t_treenode	*parse_simple_command(t_parser *parser);

/* ft_parser_utils.c */
void		ft_append(t_treenode *dest, t_treenode *src);
char		**ft_realloc(char **memblock, size_t size);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_par_strdup(const char *s);

/* ft_parser_lexer_utils.c*/
void		skip_white_space(t_lexer *lexer);
void		advance(t_lexer *lexer);
int			skip_bracket(t_lexer *lexer);
int			is_special_command(t_parser *parser);

/* ft_parser_tree.c */
int			get_treenode_num(t_treenode *root);
int			check_tree_validation(t_treenode *root);
void		free_tree(t_treenode *root);
int			change_tree_utils(t_treenode *root, t_minishell *ms);

/* ft_parser_init.c */
t_parser	create_parser(char *text);
t_lexer		create_lexer(char *text);

/* ft_parser_make_token.c*/
t_token		make_token_pipe_or(t_lexer *lexer);
t_token		make_token_redirection_in(t_lexer *lexer);
t_token		make_token_redirection_out(t_lexer *lexer);
t_token		make_token_and(t_lexer *lexer);
t_token		make_token_string(t_lexer *lexer);

/* ft_parser_make_node.c */
t_treenode	*make_command_new_node(t_parser *parser);
t_treenode	*make_null_node(t_parser *parser);
t_treenode	*make_new_node(t_parser *parser);
void		make_token_string_utils(t_lexer *lexer);

/* aster_pattern.c */
int			is_match(char *pattern, char *file);
void		concat_matched_files(char **dest, char **dirs, char *pattern);

/* aster_readdir.c */
char		**get_dir(char *pwd);
char		*get_pwd(void);
int			get_matched_file_len(char *pattern, char **dirs);

/* asterisk.c */
char		*translate_asterisk(char *str);

/* init_minishell.c */
t_minishell	*init_minishell(char **envp);
void		free_minishell(t_minishell **ms);

/* builtins_dir.c */
int			ft_cd(char **args, t_env *head);
int			ft_pwd(void);
int			ft_exit(t_minishell *ms, char **args);
int			isfile(const char *name);

/* builtins_env_utils.c */
char		*env_get_value(char *name, t_env *head);
void		change_env_status(t_env *head);
void		print_export(t_env *head);
int			change_export(t_env **head, char *arg);
void		unset_env(char *name, t_env **head);

/* builtins_env.c */
int			ft_echo(char **args);
int			ft_export(char **args, t_env **head);
int			ft_unset(char **args, t_env **head);
int			ft_env(char **args, t_env *head);
int			split_env(char *str, char **name, char **value);

/* builtins.c */
int			is_builtins(char *cmd);
int			exec_builtins(t_minishell *ms, char **args);
char		**get_env(t_env *head);

/* env_oper_utils.c */
int			edit_env_pwd(char *path, char *pwd, t_env *head);
int			is_valid_exit(char *args);
int			get_env_len(t_env *head);

/* error.c */
void		print_stderr(char *str1, char *str2, char *arg);
void		error(int error_num);
void		execve_error(char *path, t_minishell *ms);
void		close_fd_error(t_minishell *ms, int errnum);

/* handle operations */
int			handle_operations(char *str, t_minishell *ms);

/* order_str.c */
char		*order_str(char *str);

/* order_str_utils.c */
void		copy_str(char **str, char *dest, int *i);
void		copy_rdt(char **str, char *dest, int *i);

/* parenthesis_validation */
int			is_valid_parenthesis(char *str);

/* pipe_execute_utils.c */
void		get_waitpid_status(t_pipex *pipex, int i);
int			iscmd_cat(t_pipex *pipex, char **args);
int			is_interactive_mode(t_pipex *pipex, char **args);
void		redirect_ppid(t_pipex *pipex, char **args, int fd);
void		redirect_pid(t_pipex *pipex, char **args, int fd);

/* pipe_execute.c */
void		execute(t_minishell *ms, char **args);

/* pipe_heredoc.c */
void		here_doc(t_pipex *pipex, char *file_name);

/* pipe_interpret_utils.c */
char		*dup_token(char **str);
void		move_to_next_token(char **str);
int			io_error(t_pipex *pipex, char *file, int errnum);
void		dup_file(t_pipex *pipex, char *file, int num);
void		reset_pipex(t_pipex *pipex);

/* pipe_interpret.c */
void		interpret_ios(t_minishell *ms, t_treenode *root_node);

/* pipe_tree.c */
int			handle_multi_cmd1(t_treenode *root, t_minishell *ms);

/* pipe_utils.c */
void		change_curtree(t_minishell *ms);
int			is_nodetype_and_or(int type);
void		change_status_on_rdt_fail(t_minishell *ms);
void		parent_wait(t_minishell *ms, char **args);
int			process_cmd(t_minishell *ms);

/* pipe_utils2.c */
int			is_process_wait(t_minishell *ms);
void		execute_now(t_minishell *ms);
void		set_pipe_interactive_signal(void);

/* pipe.c */
int			handle_multi_cmd(t_minishell *ms, int status);
void		preprocess(t_minishell *ms);
int			wait_child(t_pipex *pipex);

/* split_pipe_utils1.c */
void		split_pipe_move_to_next_token(t_minishell *ms, \
											char **str, int *len);
int			get_translate_len(t_minishell *ms, char **s, int sign);
int			handle_quotes(char *str);

/* split_pipe_utils2.c */
void		copy_delimiter(char **read, char **str);
void		handle_token(t_minishell *ms, char **read, char **str);
char		*translate(t_minishell *ms, char **s, int sign);

/* split_pipe_utils3.c */
void		copy_cmd_token(t_minishell *ms, char **s, char **cmds);
void		copy_rdt_token(t_minishell *ms, char **s, char **rdts);

/* split_pipe.c */
char		*init_cmds_rdts(char *str, t_minishell *ms);

/* split_utils.c */
int			get_limiter_len(char **str);
void		free_args(char **args);
int			get_args_len(char **args);
char		**free_split(char **split, size_t m);

/* validation.c */
int			is_valid_quotes(char *str);

/* signal_set.c */
void		set_signal_interactive(void);
void		set_signal_fork(void);
void		set_signal(void);
void		set_terminal_print_off(void);
void		set_terminal_print_on(void);

/* signal_do.c */
void		do_sigint_cat1(int signum);
void		do_sigint_heredoc(int signum);
void		do_sigint(int signum);
void		do_sigint_cat(int signum);
void		do_sigquit_cat(int signum);

#endif