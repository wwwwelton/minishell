/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 01:37:17 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/11 22:54:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef DEBUG
#  define DEBUG 1
# endif
# define SQUOTES 39
# define DQUOTES 34
# define NEWPAT "___0x4242___"

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

char		**g_environ;

typedef struct s_flags
{
	char				*file_out;
	char				*file_in;
	int					builtins;
	int					system_cmd;
}	t_flags;

typedef struct s_builtin
{
	char				*name;
	void				(*f)(char **, char **);
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
	char				**presplit;
	char				***cmd;
	char				**path;
	char				**accesspath;
	char				*alt_env[200];
	t_pat				*pat;
	t_flags				**flags;
	t_builtin			*head;
}	t_data;

void	init_builtins(t_builtin **head);
void	init_pat(t_pat **pat);
void	init_data(t_data **data);

char	*replace_quoted(t_pat *pat, char *line);
char	***restore_quoted(t_pat *pat, char ***cmd);
void	printfunctions(t_builtin *head);
void	minishell(t_data *data);
void	parser(t_data *data, char *line);
char	*prompt_user(void);
void	translate(t_data *data);
void	debug(t_data *data);
// void	translate(t_data)

void	alt_echo(char **str);
void	alt_cd(char *str);
void	alt_pwd(char **str);
void	alt_env(char **str, char **envp);
void	alt_unset(char *str);
void	alt_exit(char *str);
void	alt_export(char **str, char **envp);
void	alt_minishell(char *str);
void	free_splited_mat(char **mat);
void	set_env(char *var, char *value, char **envp);
char	*get_env(char *value, char **envp);

#endif
