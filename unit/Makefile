LIBFT_PATH		=	../libft/
LIBFT			=	$(LIBFT_PATH)/libft.a
LINKS			=	-I ../ -I $(LIBFT_PATH)

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf

SRC_ECHO		=	builtin/test_echo.c ../src/ms_builtin_echo.c

ms_echo:
	$(CC) $(CFLAGS) $(SRC_ECHO) $(LIBFT) $(LINKS) -lreadline -o test_echo

fclean:
	$(RM) test_echo
