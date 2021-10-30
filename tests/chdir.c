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

	str = ft_strdup("hello");
	printf("%p\n", str);
	ftex_minprintf("%p\n", str);
	ftex_null_ptr((void **)&str);
	ftex_minprintf("%p\n", str);
}
