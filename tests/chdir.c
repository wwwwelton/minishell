#include "libft.h"
#include <stdio.h>

void ftex_null_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}


//if ptr is NULL getcwd returns a malloc buffer as long as necessary when
//length is set 0
int	main(void)
{
	char *str;

	str = getcwd(str, 0);
	ftex_minprintf("the current directory: %s\n", str);
	ftex_null_ptr((void **)&str);
	chdir("../");
	str = getcwd(str, 0);
	ftex_minprintf("After chdir to parent: %s\n", str);
	ftex_null_ptr((void **)&str);
}
