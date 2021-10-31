#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int		size;

	size = 200;
	str = ft_calloc(size, sizeof(char));
	getcwd(str, size);
	ftex_minprintf("%s\n", str);
	chdir("./openthis");
	free(str);
	str = ft_calloc(size, sizeof(char));
	getcwd(str, size);
	ftex_minprintf("%s\n", str);
	free(str);
	open("42", O_CREAT | O_RDWR, 0666);
	return (0);
}
