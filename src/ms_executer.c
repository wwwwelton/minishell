/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_executer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:20:40 by wleite            #+#    #+#             */
/*   Updated: 2021/11/21 12:46:59 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_return_value(int code, t_data *data, int i)
{
	char	*value;

	value = ft_itoa(code);
	if (code)
		data->flags[i]->error = code;
	set_env_val("?", value, data->alt_env);
	ftex_null_ptr((void *)&value);
	return (code);
}

static void	print_system_error(t_data *data)
{
	int	i;

	i = -1;
	while (data->cmd[++i])
		if (data->flags[i]->error == 127)
			command_not_found(data->cmd[i][0]);
}

static void	execute_system_command(int *fd_tmp, int *code, t_data *data, int i)
{
	if (access(data->accesspath[i], X_OK) == 0)
	{
		*code = execute_system(fd_tmp, data, i);
		set_return_value(*code, data, i);
	}
	else
		*code = set_return_value(127, data, i);
}

static void	execute_builtin_command(int *fd_tmp, int *code, t_data *data, int i)
{
	*code = execute_builtin(fd_tmp, data, i);
	set_return_value(*code, data, i);
}

int	executer(t_data *data)
{
	int		i;
	int		code;
	int		fd_tmp;

	code = 0;
	i = -1;
	fd_tmp = STDIN_FILENO;
	while (data->cmd[++i])
	{
		if (data->flags[i]->system_cmd)
			execute_system_command(&fd_tmp, &code, data, i);
		if (data->flags[i]->builtins)
			execute_builtin_command(&fd_tmp, &code, data, i);
		unlink(TMP_FILE);
	}
	print_system_error(data);
	return (0);
}
