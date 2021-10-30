#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

//this gives you prompt
//the returned line is allocated with malloc by readline
int	main(void)
{
	char *str;

	printf("$ ");
	str = readline(str);
	printf("%s\n", str);
	return (0);
}
