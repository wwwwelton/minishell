#include "../libft/libft.h"
#include "../minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

//clang tests/signal.c -I ./libft -L./libft -lft && ./a.out top

// void	print(int sig)
// {
// 	if (WIFEXITED(status))
// 	{
// 		ftex_minprintf("exited\n");
// 		status = WEXITSTATUS(status);
// 		ftex_minprintf("exit code = %d\n", status);
// 	}
// 	if (WIFSIGNALED(status))
// 	{
// 		ftex_minprintf("signaled\n");
// 		status = WTERMSIG(status);
// 		ftex_minprintf("signal = %d\n", status);
// 	}
// 	if (WIFSTOPPED(status))
// 	{
// 		ftex_minprintf("stopped\n");
// 		status = WSTOPSIG(status);
// 		ftex_minprintf("stopcode = %d\n", status);
// 	}
// }

void	init_sigaction(t_sigaction *action, void (*handler)(int), int sig)
{
	action->sa_handler = handler;
	action->sa_flags = 0;
	sigemptyset(&action->sa_mask);
	sigaction(sig, action, NULL);
}

char **args(int argc, char **argv)
{
	char **ret;
	int	i;

	i = -1;
	ret = malloc(sizeof(char *) * argc);
	while (++i < argc - 1)
		ret[i] = ft_strdup(argv[i + 1]);
	ret[i] = NULL;
	return (ret);
}

int	main(int argc, char **argv)
{
	int	pid;
	int status;
	t_sigaction action;

	(void)argc;
	pid = fork();
	if (pid == 0)
	{
		execve(ft_strjoin("/usr/bin/", argv[1]), args(argc, argv), __environ);

	}
	waitpid(pid, &status, 0);
	// sleep(1);
	if (WIFEXITED(status))
	{
		ftex_minprintf("exited\n");
		status = WEXITSTATUS(status);
		ftex_minprintf("exit code = %d\n", status);
	}
	if (WIFSIGNALED(status))
	{
		ftex_minprintf("signaled\n");
		status = WTERMSIG(status);
		ftex_minprintf("signal = %d\n", status);
	}
	if (WIFSTOPPED(status))
	{
		ftex_minprintf("stopped\n");
		status = WSTOPSIG(status);
		ftex_minprintf("stopcode = %d\n", status);
	}
}
