LIBFT_PATH		=	../libft/
LIBFT			=	$(LIBFT_PATH)/libft.a
LINKS			=	-I ../ -I $(LIBFT_PATH)

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror -g3
RM				=	rm -rf

SRC_ECHO		=	builtin/test_echo.c ../src/ms_builtin_echo.c

SRC_PWD			=	builtin/test_pwd.c ../src/ms_builtin_pwd.c ../src/ms_utils.c

SRC_ENV			=	builtin/test_env.c ../src/ms_builtin_env.c

SRC_EXPORT		=	builtin/test_export.c ../src/ms_builtin_export.c
SRC_EXPORT		+=	../src/ms_builtin_env.c ../src/ms_utils.c

SRC_UNSET		=	builtin/test_unset.c ../src/ms_builtin_unset.c
SRC_UNSET		+=	../src/ms_builtin_env.c ../src/ms_utils.c

SRC_CD			=	builtin/test_cd.c ../src/ms_builtin_cd.c ../src/ms_utils.c
SRC_CD			+=	../src/ms_builtin_export.c ../src/ms_builtin_env.c

SRC_EXIT		=	builtin/test_exit.c ../src/ms_builtin_exit.c

SRC_EXIT		=	builtin/test_here.c

ms_echo:
	$(CC) $(CFLAGS) $(SRC_ECHO) $(LIBFT) $(LINKS) -lreadline -o test_echo

ms_pwd:
	$(CC) $(CFLAGS) $(SRC_PWD) $(LIBFT) $(LINKS) -lreadline -o test_pwd

ms_env:
	$(CC) $(CFLAGS) $(SRC_ENV) $(LIBFT) $(LINKS) -lreadline -o test_env

ms_export:
	$(CC) $(CFLAGS) $(SRC_EXPORT) $(LIBFT) $(LINKS) -lreadline -o test_export

ms_unset:
	$(CC) $(CFLAGS) $(SRC_UNSET) $(LIBFT) $(LINKS) -lreadline -o test_unset

ms_cd:
	$(CC) $(CFLAGS) $(SRC_CD) $(LIBFT) $(LINKS) -lreadline -o test_cd

ms_exit:
	$(CC) $(CFLAGS) $(SRC_EXIT) $(LIBFT) $(LINKS) -lreadline -o test_exit

ms_heredoc:
	$(CC) $(CFLAGS) $(SRC_EXIT) $(LIBFT) $(LINKS) -lreadline -o test_heredoc

fclean:
	$(RM) test_echo test_pwd test_env test_export test_unset test_cd test_exit test_heredoc
