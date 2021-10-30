#include <stdio.h>
#include <stdlib.h>

//this gives you the corresponding string for the env variable
int	main(void)
{
	printf("%s\n", getenv("SHELL"));
}
