/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:37:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/23 04:24:14 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef DEBUG
#  define DEBUG 0
# endif
# define SQUOTES 39
# define DQUOTES 34
# define NEWPAT "___0x4242___"
# define TMP_FILE "./tmp"

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

char		**g_environ;

typedef struct s_redir_in
{
	char	*file_in;
	int		heredoc;
}	t_redir_in;

typedef struct s_redir_out
{
	char	*file_out;
	int		out_append;
}	t_redir_out;

typedef struct s_flags
{
	t_redir_in	redir_in[20];
	t_redir_out	redir_out[20];
	char		*file_in;
	char		*file_out;
	int			out_append;
	int			heredoc;
	int			builtins;
	int			system_cmd;
	int			error;
}	t_flags;

typedef struct s_builtin
{
	char				*name;
	int					(*f)(char **, char **);
	struct s_builtin	*next;
}	t_builtin;

typedef struct s_pat
{
	char	*backup[50];
	char	*holder[50];
	int		i;
}	t_pat;

typedef struct s_data
{
	char				*lastline;
	char				**presplit;
	char				***cmd;
	char				**path;
	char				**accesspath;
	char				*alt_env[200];
	int					star;
	t_pat				*pat;
	t_flags				**flags;
	t_builtin			*head;
}	t_data;

void	init_builtins(t_builtin **head);
void	init_pat(t_pat **pat);
void	init_data(t_data **data);
void	init_flags(t_flags **flags, int cmds);

int		envlen(char *str);
void	debug(t_data *data);
void	printfunctions(t_builtin *head);
int		count_pipes(char *line);
int		len_to_space(char *str);
void	print_matrix(char ***cmd);
void	printsplit(char **split, char *header);
void	free_splited_mat(char **mat);
void	ftex_tr(char *str, char del, char replace);

void	minishell(t_data *data);
char	*prompt_user(char **lastline);
int		validate_line(char *line);
void	pre_split(t_data *data, char *line);
void	parser(t_data *data, char *line);
void	identify_flags(t_flags *flags, t_builtin *builtins, char *cmd);
char	*replace_quoted(t_pat *pat, char *line);
char	*single_quotes(t_pat *pat, char *line, int i);
char	***translate(t_pat *pat, char ***cmd, char **envp);
char	*find_stars(char *cmd);
char	***restore_quoted(t_pat *pat, char ***cmd);
char	***trim_quotes(char ***cmd);
void	reinit(t_data *data);

int		alt_echo(char **str, char **envp);
int		alt_cd(char **str, char **envp);
int		alt_pwd(char **str, char **envp);
int		alt_env(char **str, char **envp);
int		alt_unset(char **str, char **envp);
int		alt_exit(char **str, char **envp);
int		alt_export(char **str, char **envp);
int		alt_minishell(char **str, char **envp);

void	set_env(char *var, char *value, char **envp);
void	set_env_val(char *var, char *value, char **envp);
char	*get_env(char *value, char **envp);
char	*get_env_val(char *value, char **envp);
int		executer(t_data *data);
void	read_std_input(char *limiter, int file);
void	read_previous_pipe(int fd_tmp, int file);
int		execute_system(int *fd_tmp, t_data *data, int i);
int		execute_builtin(int *fd_tmp, t_data *data, int i);
int		dup_in(int *fd_tmp, t_data *data, int i);
int		dup_out(int *fd, t_data *data, int i);
void	here_doc(int *fd_tmp, t_data *data, int i, int j);
void	read_doc(char *file, int *fd_tmp, int *fd);
int		command_not_found(char *cmd);
int		p_error(const char *str);
int		dup42(int fd1, int fd2);

#endif
