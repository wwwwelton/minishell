LIBFT_PATH		=	../libft/
LIBFT			=	$(LIBFT_PATH)/libft.a
LINKS			=	-I ../ -I $(LIBFT_PATH)

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror -g3
RM				=	rm -rf

SRC_ECHO		=	builtin/test_echo.c ../src/ms_builtin_echo.c

SRC_PWD			=	builtin/test_pwd.c ../src/ms_builtin_pwd.c

ms_echo:
	$(CC) $(CFLAGS) $(SRC_ECHO) $(LIBFT) $(LINKS) -lreadline -o test_echo

ms_pwd:
	$(CC) $(CFLAGS) $(SRC_PWD) $(LIBFT) $(LINKS) -lreadline -o test_pwd

fclean:
	$(RM) test_echo test_pwd
