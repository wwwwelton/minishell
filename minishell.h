/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:37:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/12/12 23:49:00 by jofelipe         ###   ########.fr       */
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
# define TMP_FILE "/tmp/here_doc_tmp_file"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# define DFL_SIGNAL 12500
# ifndef WORKSPACE
#  define WORKSPACE 0
# endif

# define BOLDBLUE "\001\033[1;36m\002"
# define BOLDGREEN "\001\033[1;32m\002"
# define BOLDRED "\001\033[1;31m\002"
# define RESET "\001\033[0m\002"

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

extern char					**g_envp;

typedef struct sigaction	t_sigaction;

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
	int			builtins;
	int			system_cmd;
	int			error;
}	t_flags;

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
	char				*alt_env[4000];
	int					star;
	t_pat				*pat;
	t_flags				**flags;
	void				*head;
}	t_data;

typedef struct s_builtin
{
	char				*name;
	int					(*f)(char **, t_data *);
	struct s_builtin	*next;
}	t_builtin;

//controllers
void	minishell(t_data *data);
char	*prompt(char **lastline, char **envp);
void	parse(t_data *data, char *line);
void	translate(t_pat *pat, char ***cmd, char **envp);
int		execute(t_data *data);

//signals
void	init_sigaction(t_sigaction *action, void (*handler)(int), int sig);
void	sig_prompt(int sig);
void	sig_cmd(int sig);
void	sig_child(int sig);

//structures and memory management
void	init_builtins(t_builtin **head);
void	init_pat(t_pat **pat);
void	init_data(t_data **data);
void	init_flags(t_flags **flags, int cmds);
int		cleanup(t_data *data, int code);
void	reinit(t_data *data);

//support functions
int		envlen(char *str);
int		last_status_code(char **envp);
void	debug(t_data *data);
void	printfunctions(t_builtin *head);
int		count_pipes(char *line);
int		len_to_space(char *str);
void	print_matrix(char ***cmd);
void	printsplit(char **split, char *header);
void	free_splited_mat(char **mat);
t_bool	is_multiple_commands(char *buf);
int		command_size(char *buf);
int		ms_putchar(int c);
t_bool	is_blank_line(char *line);

//prompt
char	*prompt_loop(char *line, char **lastline);
char	*fetch_buffer(char *buf, char *line, char **lastline, char **envp);
t_bool	validate_line(char *line, char **lastline);
t_bool	is_file_invalid(char *line);
char	*check_redir_spaces(char *line);
char	*check_here_doc_spaces(char *line);
void	paint_cwd(char **cwd);
void	replace_cwd_path(char **cwd);
void	replace_dir_name(char **cwd);

//parsing
char	*pre_split(t_data *data, char *line);
void	identify_flags(t_flags *flags, t_builtin *builtins, char *cmd);
char	*replace_quoted(t_pat *pat, char *line);
char	*single_quotes(t_pat *pat, char *line, int i);
char	*find_stars(char *cmd);
void	restore_quoted(t_pat *pat, char ***cmd);
void	trim_quotes(char ***cmd);

//builtins
int		alt_echo(char **str, t_data *data);
int		alt_cd(char **str, t_data *data);
int		alt_pwd(char **str, t_data *data);
int		alt_env(char **str, t_data *data);
int		alt_unset(char **str, t_data *data);
int		alt_exit(char **str, t_data *data);
int		alt_export(char **str, t_data *data);
int		alt_minishell(char **str, t_data *data);

//builtin helpers
void	set_env(char *var, char *value, char **envp);
void	set_env_val(char *var, char *value, char **envp);
char	*get_env(char *value, char **envp);
char	*get_env_val(char *value, char **envp);

//execution
int		execute_system(int *fd_tmp, t_data *data, int i);
int		execute_builtin(int *fd_tmp, t_data *data, int i);
void	read_previous_pipe(int fd_tmp, int file);
void	read_std_input(char *limiter, int file);
int		dup_in(int *fd_tmp, t_data *data, int i);
int		dup_out(int *fd, t_data *data, int i);
void	here_doc(int *fd_tmp, t_data *data, int i, int j);
void	here_doc_eof_handler(void);
int		inside_here_doc(void);
void	read_doc(char *file, int *fd_tmp, int *fd);
int		write_to_files(t_data *data, int i);

//error management
int		p_error(const char *str);
int		command_not_found(char *cmd);

#endif
