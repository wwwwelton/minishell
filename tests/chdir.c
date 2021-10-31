#include "libft.h"
#include <stdio.h>

void ftex_null_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}


//if ptr is NULL getcwd returns a malloc buffer as long as necessary when
//length is set 0. Note how it does not terminate the string
int	main(void)
{
	char	*str;
	int		size;

	size = 200;
	str = ft_calloc(sizeof(char), size);
	str = getcwd(str, size);
	ftex_minprintf("the current directory: %s\n", str);
	ftex_null_ptr((void **)&str);
	chdir("../");
	str = ft_calloc(sizeof(char), size);
	str = getcwd(str, size);
	ftex_minprintf("After chdir to parent: %s\n", str);
	ftex_null_ptr((void **)&str);
}
