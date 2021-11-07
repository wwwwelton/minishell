#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	char *args[3];

	args[0] = "/usr/bin/echo";
	args[1] = "hello";
	args[2] = "world";
	args[3] = NULL;
	execve(args[0], args, envp);
}
