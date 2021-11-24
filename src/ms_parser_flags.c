/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parser_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:07:10 by jofelipe          #+#    #+#             */
/*   Updated: 2021/11/22 18:38:17 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_exec_mode(t_builtin *builtins, t_flags *flags, char *cmd)
{
	while (builtins)
	{
		if (!strcmp(builtins->name, cmd))
		{
			flags->builtins = 1;
			return ;
		}
		builtins = builtins->next;
	}
	flags->system_cmd = 1;
}

void	fill_redir_out(t_flags *flags, char *str, char **cmd, int index)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '>')
		{
			if (*(str + 1) == '>')
			{
				while (flags->redir_out[i].file_out)
					i++;
				flags->redir_out[i].file_out = ft_strdup(cmd[index++ + 1]);
				flags->redir_out[i++].out_append = 1;
				str++;
			}
			else
			{
				while (flags->redir_out[i].file_out)
					i++;
				flags->redir_out[i++].file_out = ft_strdup(cmd[index++ + 1]);
			}
		}
		str++;
	}
}

void	fill_redir_in(t_flags *flags, char *str, char **cmd, int index)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == '<')
		{
			if (*(str + 1) == '<')
			{
				while (flags->redir_in[i].file_in)
					i++;
				flags->redir_in[i].file_in = ft_strdup(cmd[index + 1]);
				flags->redir_in[i++].heredoc = 1;
				str++;
			}
			else
			{
				while (flags->redir_in[i].file_in)
					i++;
				flags->redir_in[i++].file_in = ft_strdup(cmd[index + 1]);
			}
		}
		str++;
	}
}

void	init_redir(t_flags *flags)
{
	int	i;

	i = -1;
	while (++i < 20)
	{
		flags->redir_in[i].file_in = NULL;
		flags->redir_in[i].heredoc = 0;
		flags->redir_out[i].file_out = NULL;
		flags->redir_out[i].out_append = 0;
	}
}

void	identify_flags(t_flags *flags, t_builtin *builtins, char *cmd)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_split(cmd, ' ');
	set_exec_mode(builtins, flags, tmp[0]);
	init_redir(flags);
	while (tmp[++i])
	{
		fill_redir_in(flags, tmp[i], tmp, i);
		fill_redir_out(flags, tmp[i], tmp, i);
		// remove from here until line 109 to test how it was previously
		// if (tmp[i][0] == '<')
		// {
		// 	if (tmp[i][1] == '<')
		// 		flags->heredoc = 1;
		// 	flags->file_in = ft_strdup(tmp[i + 1]);
		// }
		// if (tmp[i][0] == '>')
		// {
		// 	if (tmp[i][1] == '>')
		// 		flags->out_append = 1;
		// 	flags->file_out = ft_strdup(tmp[i + 1]);
		// }
	}
	free_splited_mat(tmp);
}
