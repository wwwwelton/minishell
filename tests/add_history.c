#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>

//it works for the current session
int	main(void)
{
	char *str;

	str = NULL;
	ft_putstr_fd("$ ", 0);
	str = readline(str);
	add_history(str);
	free(str);
	main();
	return (0);
}
