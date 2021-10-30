#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>

//note how echo prints a space in between the splitted strings
int	main(void)
{
	char	**arg;
	int		pid;

	arg = ft_split(readline(""), ' ');
	pid = fork();
	if (pid == 0)
		execvp("echo", arg);
	for (int i = 0; arg[i]; i++)
		ftex_minprintf("%s$\n", arg[i]);
}
